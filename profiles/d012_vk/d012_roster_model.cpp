// PLACEHOLDER: a character model on the select screens, drawn by the host over the game's picture.
//
// D012_ROSTER_OBJ=<path to a .obj> loads that mesh (positions and faces only) and draws it, flat shaded and turning slowly,
// at the right of the roster grid while a full grid is on screen. It is a CPU-projected silhouette drawn with Dear ImGui
// through the port's game overlay hook: no game code or renderer change, and the game's own controls never reach it.
// Nothing happens without the variable.

#if defined(PORTABLEKIT_HAS_RENDERER)

#include "imgui.h"
#include "ui/ui.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool d012_roster_screen_active();  // d012_hud_layout.cpp

namespace {

struct Vec3 {
    float x, y, z;
};

struct Mesh {
    std::vector<Vec3> vertices;
    std::vector<unsigned> indices;  // triangles
    float min_y = 0.0f, max_y = 1.0f, center_x = 0.0f, center_z = 0.0f;
};

Mesh &mesh() {
    static Mesh loaded = [] {
        Mesh m;
        const char *path = std::getenv("D012_ROSTER_OBJ");
        if (path == nullptr || *path == '\0') return m;
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream words(line);
            std::string kind;
            words >> kind;
            if (kind == "v") {
                Vec3 v{};
                words >> v.x >> v.y >> v.z;
                m.vertices.push_back(v);
            } else if (kind == "f") {
                std::vector<unsigned> face;
                std::string token;
                while (words >> token) {
                    const int index = std::atoi(token.c_str());  // "v", "v/vt" or "v/vt/vn": the first number
                    face.push_back(static_cast<unsigned>(index > 0 ? index - 1 : static_cast<int>(m.vertices.size()) + index));
                }
                for (std::size_t k = 2; k < face.size(); ++k) {
                    m.indices.push_back(face[0]);
                    m.indices.push_back(face[k - 1]);
                    m.indices.push_back(face[k]);
                }
            }
        }
        if (m.vertices.empty()) return m;
        float x0 = 1e9f, x1 = -1e9f, z0 = 1e9f, z1 = -1e9f;
        m.min_y = 1e9f;
        m.max_y = -1e9f;
        for (const Vec3 &v : m.vertices) {
            m.min_y = std::min(m.min_y, v.y);
            m.max_y = std::max(m.max_y, v.y);
            x0 = std::min(x0, v.x);
            x1 = std::max(x1, v.x);
            z0 = std::min(z0, v.z);
            z1 = std::max(z1, v.z);
        }
        m.center_x = 0.5f * (x0 + x1);
        m.center_z = 0.5f * (z0 + z1);
        std::fprintf(stderr, "[roster model] %zu vertices, %zu triangles\n", m.vertices.size(), m.indices.size() / 3u);
        return m;
    }();
    return loaded;
}

// The roster grid is detected as soon as its first cells are drawn, while the screen is still animating in. The model waits
// until the grid has been on screen without a break for this long.
constexpr double kShowDelaySeconds = 1.2;

bool model_visible() {
    static std::chrono::steady_clock::time_point since{};
    static bool was_active = false;
    const bool active = d012_roster_screen_active();
    if (active && !was_active) since = std::chrono::steady_clock::now();
    was_active = active;
    if (!active) return false;
    return !mesh().indices.empty() &&
           std::chrono::duration<double>(std::chrono::steady_clock::now() - since).count() >= kShowDelaySeconds;
}

void model_draw() {
    const Mesh &m = mesh();
    const portablekit::ui::GamePicture picture = portablekit::ui::game_picture();
    const float sx = picture.width / 480.0f, sy = picture.height / 272.0f;
    static float yaw = 0.0f;
    yaw += ImGui::GetIO().DeltaTime * 0.8f;
    const float c = std::cos(yaw), s = std::sin(yaw);
    // Where it stands, in the game's 480x272 pixels: feet at (375, 262), 190 pixels tall.
    const float feet_x = 375.0f, feet_y = 262.0f, height = 190.0f;
    const float scale = height / std::max(0.01f, m.max_y - m.min_y);

    struct Projected {
        ImVec2 p;
        float z;
    };
    std::vector<Projected> projected(m.vertices.size());
    std::vector<Vec3> rotated(m.vertices.size());
    for (std::size_t i = 0; i < m.vertices.size(); ++i) {
        const float x = m.vertices[i].x - m.center_x, z = m.vertices[i].z - m.center_z;
        rotated[i] = {x * c + z * s, m.vertices[i].y, -x * s + z * c};
        projected[i] = {ImVec2(picture.left + (feet_x + rotated[i].x * scale) * sx,
                               picture.top + (feet_y - (rotated[i].y - m.min_y) * scale) * sy),
                        rotated[i].z};
    }

    struct Face {
        unsigned a, b, c;
        float depth, light;
    };
    std::vector<Face> faces;
    faces.reserve(m.indices.size() / 3u);
    for (std::size_t t = 0; t + 2 < m.indices.size(); t += 3) {
        const unsigned a = m.indices[t], b = m.indices[t + 1], d = m.indices[t + 2];
        if (a >= rotated.size() || b >= rotated.size() || d >= rotated.size()) continue;
        const Vec3 &p = rotated[a], &q = rotated[b], &r = rotated[d];
        const Vec3 u{q.x - p.x, q.y - p.y, q.z - p.z}, v{r.x - p.x, r.y - p.y, r.z - p.z};
        Vec3 n{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
        const float length = std::sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
        if (length < 1e-12f) continue;
        n = {n.x / length, n.y / length, n.z / length};
        if (n.z <= 0.0f) continue;  // facing away (the camera looks down -z; +z is toward it)
        const float light = std::clamp(0.35f + 0.65f * std::max(0.0f, 0.3f * n.x + 0.5f * n.y + 0.8f * n.z), 0.0f, 1.0f);
        faces.push_back({a, b, d, (p.z + q.z + r.z) / 3.0f, light});
    }
    std::sort(faces.begin(), faces.end(), [](const Face &l, const Face &r) { return l.depth < r.depth; });

    ImDrawList *draw = ImGui::GetForegroundDrawList();
    for (const Face &f : faces) {
        const int level = static_cast<int>(40.0f + 190.0f * f.light);
        draw->AddTriangleFilled(projected[f.a].p, projected[f.b].p, projected[f.c].p,
                                IM_COL32(level, static_cast<int>(level * 0.92f), static_cast<int>(level * 0.7f), 255));
    }
}

struct Install {
    Install() { portablekit::ui::add_game_overlay(&model_visible, &model_draw); }
} install;

}  // namespace

#endif
