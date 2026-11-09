# Builds the zip for a GitHub release: dist\d012_native-windows.zip.
#
# The zip is assembled from the build's own outputs, not from whatever happens to sit in the Release folder:
#   - d012_native.exe and the DLLs beside it come from the build's Release folder;
#   - the code overlays come from the build's overlays\Release folder (where the build writes them) and replace
#     any copy in Release\overlays, so an old overlay can never travel in the zip;
#   - FFmpeg's DLLs and licence files come from the build's bin folder;
#   - requirements.bat and README.txt come from the repo's release\ folder;
#   - fonts\calibri.ttf (next to the exe, not inside data\) comes from the Windows fonts folder (or release\fonts);
#   - data\ (fonts, textures, ...) is copied as it is, except the player's own folders and the files made while
#     testing here (listed below): those are in the zip as empty folders.
# It stops with a message if something the game needs is missing.
param(
    [string]$Build = "out\d012_vk\bin\Release",
    [string]$Out = "dist",
    [string]$Name = "d012_native-windows"
)
$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
$src = Join-Path $root $Build
$bin = Split-Path $src -Parent
$overlaySrc = Join-Path $bin "overlays\Release"
$name = $Name
$stage = Join-Path $root "$Out\$name"
$playerFolders = "data\mods", "data\ms0\PSP\GAME", "data\ms0\PSP\SAVEDATA", "game"
# Made on this machine while testing: the game writes them again on the player's first run.
$localFiles = "data\settings.ini", "data\pipeline_cache.bin", "data\pipeline_keys.bin"
# The logs and the screenshots are the player's own (running the game from the build folder makes data\logs, F9 makes
# data\screenshots): they never ship.
$localFolders = "data\logs", "data\screenshots"
# Test leftovers and old copies that must not ship.
$junk = "*.stale*", "*.old", "*.log", "*.pdb", "*.ilk", "*.exp", "*.lib", "*.bak",
    # what the test switches write beside the exe: traces, crash dumps and trigger files
    "roster_*.txt", "roster_trigger", "text_trace.txt", "text_trigger", "live.txt", "crash_report.txt", "*.dmp"
# Linux and macOS files never go in the Windows zip: the shell scripts, the Linux binary and libraries, the .dylib files, and the Carlito font
# (the Linux package takes release\linux\ and scriptsuild_linux.sh; this script only ever copies release\*.* files).
$linuxOnly = "*.sh", "*.so", "*.so.*", "*.dylib", "d012_native", "Carlito*", "linux_deps*", "run.sh"

if (-not (Test-Path (Join-Path $src "d012_native.exe"))) { throw "Build the project first: $src\d012_native.exe not found" }
if (-not (Test-Path $overlaySrc)) { throw "The build's overlays are missing: $overlaySrc" }

Write-Host "[1/6] Preparing the staging folder... " -NoNewline
if (Test-Path $stage) { Remove-Item -Recurse -Force $stage }
New-Item -ItemType Directory -Force $stage | Out-Null
Write-Host "Done!"

# robocopy exit codes below 8 are success
Write-Host "[2/6] Copying the build... " -NoNewline
robocopy $src $stage /E /XD (($playerFolders + $localFolders) | ForEach-Object { Join-Path $src $_ }) /XF (($localFiles | ForEach-Object { Join-Path $src $_ }) + $junk + $linuxOnly) /NFL /NDL /NJH /NJS /NP | Out-Null
if ($LASTEXITCODE -ge 8) { throw "robocopy failed: $LASTEXITCODE" }
Write-Host "Done!"

Write-Host "[3/6] Adding the build's overlays, FFmpeg and the setup files... " -NoNewline
# The overlays the build just made replace whatever the Release folder held.
$stageOverlays = Join-Path $stage "overlays"
if (Test-Path $stageOverlays) { Remove-Item -Recurse -Force $stageOverlays }
New-Item -ItemType Directory -Force $stageOverlays | Out-Null
Get-ChildItem $overlaySrc -Filter "*.dll" | Where-Object { $_.Name -notlike "*.stale*" } | Copy-Item -Destination $stageOverlays
# FFmpeg (LGPL): its DLLs and its licence text and source pointer travel together.
Get-ChildItem $bin -Filter "*.dll" -File | Copy-Item -Destination $stage -Force
foreach ($f in "FFmpeg-LICENSE.txt", "FFmpeg-SOURCE.txt") { $p = Join-Path $bin $f; if (Test-Path $p) { Copy-Item $p $stage -Force } }
# Calibri Regular: the game's text is drawn from it only (fonts\calibri.ttf next to the exe, not in data\; found on any
# system). Taken from this machine's Windows fonts, or from release\fonts\calibri.ttf if that exists.
$calibriDst = Join-Path $stage "fonts"
New-Item -ItemType Directory -Force $calibriDst | Out-Null
$calibri = @((Join-Path $root "release\fonts\calibri.ttf"), (Join-Path $env:WINDIR "Fonts\calibri.ttf")) | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $calibri) { throw "calibri.ttf not found (looked in release\fonts and the Windows fonts folder)" }
Copy-Item $calibri (Join-Path $calibriDst "calibri.ttf") -Force
# requirements.bat and README.txt: the repo's copies win over the ones in the build folder.
$releaseDir = Join-Path $root "release"
if (Test-Path $releaseDir) { Get-ChildItem $releaseDir -File -Exclude $linuxOnly | Copy-Item -Destination $stage -Force }
# The cheats files (ULES and ULUS) kept in the repo go in too, whether or not the build folder has them.
$cheatsSrc = Join-Path $root "release\data\ms0\PSP\CHEATS"
if (Test-Path $cheatsSrc) {
    $cheatsDst = Join-Path $stage "data\ms0\PSP\CHEATS"
    New-Item -ItemType Directory -Force $cheatsDst | Out-Null
    Copy-Item (Join-Path $cheatsSrc "*") $cheatsDst -Recurse -Force
}
# data\logs and data\screenshots are never packed, whichever way they got in.
foreach ($folder in $localFolders) { Remove-Item -Recurse -Force (Join-Path $stage $folder) -ErrorAction SilentlyContinue }
# Sweep: whatever Linux file got in by another way is removed before zipping.
Get-ChildItem $stage -Recurse -File -Include $linuxOnly | Remove-Item -Force
Write-Host "Done!"

Write-Host "[4/6] Creating the empty player folders... " -NoNewline
foreach ($folder in $playerFolders) { New-Item -ItemType Directory -Force (Join-Path $stage $folder) | Out-Null }
Write-Host "Done!"

Write-Host "[5/6] Checking the package... " -NoNewline
$missing = @()
foreach ($f in "d012_native.exe", "SDL3.dll", "avcodec-61.dll", "avformat-61.dll", "avutil-59.dll", "swresample-5.dll", "requirements.bat", "README.txt") {
    if (-not (Test-Path (Join-Path $stage $f))) { $missing += $f }
}
foreach ($o in "battle", "extra", "menu", "suppreacc") {
    if (-not (Get-ChildItem $stageOverlays -Filter "ovl*_${o}_*.dll")) { $missing += "overlays\*_${o}_*.dll" }
}
if (-not (Test-Path (Join-Path $stage "data\textures"))) { $missing += "data\textures" }
if (-not (Test-Path (Join-Path $stage "fonts\calibri.ttf"))) { $missing += "fonts\calibri.ttf" }
Remove-Item -Recurse -Force (Join-Path $stage "data\fonts") -ErrorAction SilentlyContinue  # fonts live in the root only
if ($missing.Count -gt 0) { throw "Missing from the package: $($missing -join ', ')" }
# An overlay older than the exe means the build was not finished: say so instead of shipping it.
$exeTime = (Get-Item (Join-Path $stage "d012_native.exe")).LastWriteTime
Get-ChildItem $stageOverlays -Filter "*.dll" | ForEach-Object {
    if ($_.LastWriteTime -lt $exeTime.AddHours(-12)) { Write-Warning "$($_.Name) is much older than d012_native.exe: rebuild before shipping." }
}
Write-Host "Done!"

Write-Host "[6/6] Zipping (this takes a while)... " -NoNewline
# Written entry by entry with forward slashes, so every folder lands where it is in the build folder on any
# system (Windows PowerShell's CreateFromDirectory writes backslashes, which unzip tools read as part of a file name
# at the root). Empty folders are kept as entries.
Add-Type -AssemblyName System.IO.Compression
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = Join-Path $root "$Out\$name.zip"
if (Test-Path $zip) { Remove-Item $zip }
$stageFull = (Resolve-Path $stage).Path.TrimEnd('\')
$archive = [System.IO.Compression.ZipFile]::Open($zip, [System.IO.Compression.ZipArchiveMode]::Create)
try {
    Get-ChildItem $stageFull -Recurse -Force | ForEach-Object {
        $entry = $_.FullName.Substring($stageFull.Length + 1).Replace('\', '/')
        if ($_.PSIsContainer) {
            if (-not (Get-ChildItem $_.FullName -Force)) { [void]$archive.CreateEntry($entry + '/') }
        } else {
            [void][System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile($archive, $_.FullName, $entry, [System.IO.Compression.CompressionLevel]::Optimal)
        }
    }
} finally { $archive.Dispose() }
Remove-Item -Recurse -Force $stage
Write-Host "Done!"
Write-Host "Zip: $zip ($([math]::Round((Get-Item $zip).Length / 1MB)) MB)"
