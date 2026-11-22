#pragma once

// Start skips the Square Enix logo and the credits at start-up (d012_boot_skip.cpp); D012_NO_BOOT_SKIP=1 turns it off.

namespace portablekit {
class HleRegistrar;
}

namespace d012_boot_skip {

void install(portablekit::HleRegistrar &hle);

} // namespace d012_boot_skip
