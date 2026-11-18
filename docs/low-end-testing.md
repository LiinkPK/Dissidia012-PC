# Testing on a slow computer

What to run, and what to send back, so the cost can be found with numbers instead of guesses.

## The machine

Start the game once and keep the console log. Near the top it prints a `[system]` line (CPU model, SSE4.2 / AVX / AVX2 / FMA / BMI2, logical cores, RAM) and `[render]` lines (graphics card, Vulkan version, driver, memory type). Send those lines. If the game stops at once with "needs a CPU with AVX", the Windows build was compiled for AVX and this CPU (or the operating system) does not offer it: that is a compatibility problem to fix, so send that message and the CPU model (the `[system]` line comes later, so it will not be there).

## One run per scene

Run the game once for each scene below, with the same save every time, and play it for about 60 seconds. Use a different CSV name for each run.

Windows (PowerShell):

    $env:D012_PERF = "log"; $env:D012_PERF_CSV = "battle.csv"; $env:D012_TRACE_STALLS = "1"; .\d012_native.exe

Linux:

    D012_PERF=log D012_PERF_CSV=battle.csv D012_TRACE_STALLS=1 ./run.sh

Scenes: main menu, roster screen, loading into a battle (start the CSV before pressing Start), a 1-on-1 battle, a battle with heavy effects, a cutscene, the shop.

Then summarize each one:

    python tools/perf/summarize_perf_csv.py battle.csv

It prints average fps, the fps of the slowest 1% of frames, frame time percentiles, hitches, where the time goes (guest code, render, waiting on the GPU), the time spent creating pipelines and uploading textures, and the worst frames with their biggest cost.

Send the CSVs, the console log (it has the `[perf]` and `[slow-frame]` lines) and your settings: resolution or render scale, HD textures, HD text, frame interpolation and the frame limiter.

## Comparing before and after

Run the same scene twice, with the same save, before and after a change, and compare:

    python tools/perf/summarize_perf_csv.py before.csv after.csv

## Reading the result

- Guest time high: the recompiled game code is the cost.
- Render time high: recording the frame is the cost (draw calls, state changes, per-draw memory work).
- Wait time high: the GPU or the frame fence is the cost, so the graphics card or the render scale is too much for it.
- Hitches with pipeline creation: shaders are being compiled in the middle of play.
- Hitches with texture upload: textures are being uploaded while the game runs.

## Switches for comparing

Each change has a way to turn it off for one run, so the same scene can be measured both ways:

- `D012_WORKER_PRIORITY=0`: background workers (HD texture decoding, the pipeline prewarm) keep the normal priority.
- `D012_EXPANSION=0`: the stock executable without the memory expansion.
- `D012_INTERNAL_SCALE`, `D012_TEXTURE_PACK`: the render size and the HD textures. The Video page also has a Quality row (Low, Medium, High) that sets these two and HD text together.
