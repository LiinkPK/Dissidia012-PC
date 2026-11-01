@echo off
setlocal EnableExtensions
title Dissidia 012 Final Fantasy HD Remastered - first-time setup

rem Asks for administrator rights once, because the runtimes below install system-wide.
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo Asking for administrator rights...
    powershell -NoProfile -Command "Start-Process -FilePath '%~f0' -Verb RunAs"
    exit /b
)

set "HERE=%~dp0"
set "TMPDIR=%TEMP%\d012_setup"
if not exist "%TMPDIR%" mkdir "%TMPDIR%"

echo.
echo === 1/3  Vulkan (graphics) ===
if exist "%SystemRoot%\System32\vulkan-1.dll" (
    echo Vulkan runtime found.
) else (
    echo Vulkan runtime not found. Downloading it from LunarG...
    powershell -NoProfile -Command "try { Invoke-WebRequest -UseBasicParsing 'https://sdk.lunarg.com/sdk/download/latest/windows/vulkan-runtime.exe' -OutFile '%TMPDIR%\vulkan-runtime.exe' } catch { exit 1 }"
    if exist "%TMPDIR%\vulkan-runtime.exe" (
        "%TMPDIR%\vulkan-runtime.exe" /S
        echo Vulkan runtime installed.
    ) else (
        echo Could not download it. Install the newest driver for your graphics card instead:
        echo   NVIDIA: nvidia.com/drivers   AMD: amd.com/support   Intel: intel.com/content/www/us/en/download-center
    )
)
echo Note: Vulkan also needs a graphics card driver that supports it (GeForce 600 and newer, Radeon HD 7000 and
echo newer, Intel HD 4000 and newer). If the game shows no window, update the graphics driver.

echo.
echo === 2/3  Microsoft Visual C++ runtime ===
powershell -NoProfile -Command "try { Invoke-WebRequest -UseBasicParsing 'https://aka.ms/vs/17/release/vc_redist.x64.exe' -OutFile '%TMPDIR%\vc_redist.x64.exe' } catch { exit 1 }"
if exist "%TMPDIR%\vc_redist.x64.exe" (
    "%TMPDIR%\vc_redist.x64.exe" /install /quiet /norestart
    echo Visual C++ runtime ready.
) else (
    echo Could not download the Visual C++ runtime. Get it from https://aka.ms/vs/17/release/vc_redist.x64.exe
)

echo.
echo === 3/3  Your game disc ===
set "GAME=%HERE%d012_native.exe"
set "ISO="
if exist "%HERE%game\disc.iso" (
    set "ISO=%HERE%game\disc.iso"
) else (
    for %%F in ("%HERE%game\*.iso") do if not defined ISO set "ISO=%%~fF"
)
if not defined ISO (
    echo No ISO found in the "game" folder.
    echo Put your own copy of Dissidia 012 [duodecim] Final Fantasy ^(.iso^) in the "game" folder and run this
    echo file again, or just start the game and drop the ISO onto its window.
    goto :done
)
if exist "%HERE%game\EBOOT.ELF" (
    echo The game is already set up.
    goto :done
)
rem The disc is used where it is, under the name the game looks for.
if /i not "%ISO%"=="%HERE%game\disc.iso" (
    ren "%ISO%" disc.iso
    set "ISO=%HERE%game\disc.iso"
)
echo Setting up the game from your disc...
"%GAME%" --install "%ISO%" --in-place
echo Done. Start the game with "d012_native.exe".

:done
echo.
pause
