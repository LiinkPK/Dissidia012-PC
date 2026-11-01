# Builds the zip for a GitHub release: only what is needed to run, no source, no game files, no saves.
#   .\scripts\make_release.ps1 -Version 0.20
param(
    [string]$Version = "0.20",
    [string]$Build = "out\d012_vk\bin\Release",
    [string]$Out = "dist"
)
$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
$src = Join-Path $root $Build
$name = "Dissidia 012 Final Fantasy HD Remastered"
$stage = Join-Path $root "$Out\$name"
if (-not (Test-Path (Join-Path $src "d012_native.exe"))) { throw "Build the project first: $src\d012_native.exe not found" }
if (Test-Path $stage) { Remove-Item -Recurse -Force $stage }
New-Item -ItemType Directory -Force $stage | Out-Null

Copy-Item (Join-Path $src "d012_native.exe") $stage
Get-ChildItem $src -Filter *.dll | Copy-Item -Destination $stage
# FFmpeg is LGPL: its licence text and source pointer travel with the DLLs
foreach ($f in "FFmpeg-LICENSE.txt", "FFmpeg-SOURCE.txt") { $p = Join-Path (Split-Path $src -Parent) $f; if (Test-Path $p) { Copy-Item $p $stage } }
Copy-Item (Join-Path $src "overlays") $stage -Recurse
New-Item -ItemType Directory -Force "$stage\data" | Out-Null
if (Test-Path "$src\data\textures") { Copy-Item "$src\data\textures" "$stage\data" -Recurse }
# release\: requirements.bat, README.txt, an empty game\ folder with the drop-your-ISO placeholder
Copy-Item (Join-Path $root "release\*") $stage -Recurse -Force

$zip = Join-Path $root "$Out\Dissidia-012-HD-Remastered-v$Version.zip"
if (Test-Path $zip) { Remove-Item $zip }
Compress-Archive -Path $stage -DestinationPath $zip -CompressionLevel Optimal
Write-Host "Done: $zip ($([math]::Round((Get-Item $zip).Length / 1MB)) MB)"
