# Builds the zip for a GitHub release: dist\d012_native-windows.zip.
# The build folder is copied as it is, except what is in the player's own folders (listed below): those are
# in the zip as empty folders, and what is in them here (your test saves, mods, disc image) is never read.
param(
    [string]$Build = "out\d012_vk\bin\Release",
    [string]$Out = "dist"
)
$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
$src = Join-Path $root $Build
$name = "d012_native-windows"
$stage = Join-Path $root "$Out\$name"
$playerFolders = "data\mods", "data\ms0\PSP\GAME", "data\ms0\PSP\SAVEDATA", "game"
# Made on this machine while testing: the game writes them again on the player's first run.
$localFiles = "data\settings.ini", "data\pipeline_cache.bin", "data\pipeline_keys.bin"
if (-not (Test-Path (Join-Path $src "d012_native.exe"))) { throw "Build the project first: $src\d012_native.exe not found" }
Write-Host "[1/5] Preparing the staging folder... " -NoNewline
if (Test-Path $stage) { Remove-Item -Recurse -Force $stage }
New-Item -ItemType Directory -Force $stage | Out-Null
Write-Host "Done!"

# robocopy exit codes below 8 are success
Write-Host "[2/5] Copying the build... " -NoNewline
robocopy $src $stage /E /XD ($playerFolders | ForEach-Object { Join-Path $src $_ }) /XF ($localFiles | ForEach-Object { Join-Path $src $_ }) /NFL /NDL /NJH /NJS /NP | Out-Null
if ($LASTEXITCODE -ge 8) { throw "robocopy failed: $LASTEXITCODE" }
Write-Host "Done!"
Write-Host "[3/5] Creating the empty player folders... " -NoNewline
foreach ($folder in $playerFolders) { New-Item -ItemType Directory -Force (Join-Path $stage $folder) | Out-Null }
# FFmpeg is LGPL: its licence text and source pointer travel with the DLLs
foreach ($f in "FFmpeg-LICENSE.txt", "FFmpeg-SOURCE.txt") { $p = Join-Path (Split-Path $src -Parent) $f; if (Test-Path $p) { Copy-Item $p $stage } }
Write-Host "Done!"

Write-Host "[4/5] Zipping (this takes a while)... " -NoNewline
# Compress-Archive leaves empty folders out of the zip; ZipFile keeps them. The files go straight in the zip root.
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = Join-Path $root "$Out\$name.zip"
if (Test-Path $zip) { Remove-Item $zip }
[System.IO.Compression.ZipFile]::CreateFromDirectory($stage, $zip, [System.IO.Compression.CompressionLevel]::Optimal, $false)
Write-Host "Done!"
Write-Host "[5/5] Removing the staging folder... " -NoNewline
Remove-Item -Recurse -Force $stage
Write-Host "Done!"
Write-Host "Zip: $zip ($([math]::Round((Get-Item $zip).Length / 1MB)) MB)"
