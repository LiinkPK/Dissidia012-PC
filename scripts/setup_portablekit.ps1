# Gets PortableKit for the build: clones the upstream project (TeamGDB/PortableKit, MIT) at the commit this port is based on
# and applies two patch series on top: the upstream port's (third_party\dissidia012-pc\port\portablekit-patches) and this
# project's (patches\portablekit). Nothing of PortableKit itself is stored in this repository.
#   .\scripts\setup_portablekit.ps1                 (creates third_party\PortableKit-d012; does nothing if it is there)
#   .\scripts\setup_portablekit.ps1 -Source <path or URL>   clone from there instead of GitHub (must contain commit 33800c4)
#   .\scripts\setup_portablekit.ps1 -Force          remove an existing third_party\PortableKit-d012 and start over
param([string]$Source = "https://github.com/TeamGDB/PortableKit.git", [switch]$Force, [string]$Dest)
$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
if (-not $Dest) { $Dest = Join-Path $root "third_party\PortableKit-d012" }
$base = "33800c4060c53f3233e08f8ab2cc4590a0872063"
if ($Force -and (Test-Path $Dest)) { Remove-Item -Recurse -Force $Dest }
if ((Test-Path (Join-Path $Dest "cmake\PortableKit.cmake")) -and (Test-Path (Join-Path $Dest ".d012_patched"))) { Write-Host "PortableKit is already set up: $Dest"; return }
if (Test-Path $Dest) { Remove-Item -Recurse -Force $Dest }
if (-not (Get-Command git -ErrorAction SilentlyContinue)) { throw "git is needed" }
Write-Host "Cloning PortableKit from $Source ..."
git clone -q $Source $Dest
if ($LASTEXITCODE -ne 0) { throw "git clone failed" }
Push-Location $Dest
try {
    git checkout -q $base
    if ($LASTEXITCODE -ne 0) { throw "commit $base not found in $Source" }
    git config user.name "d012 setup"; git config user.email "setup@localhost"; git config core.autocrlf false
    $patches = @(Get-ChildItem (Join-Path $root "third_party\dissidia012-pc\port\portablekit-patches") -Filter *.patch | Sort-Object Name) +
               @(Get-ChildItem (Join-Path $root "patches\portablekit") -Filter *.patch | Sort-Object Name)
    $tmp = Join-Path ([System.IO.Path]::GetTempPath()) "d012_patch.patch"
    foreach ($patch in $patches) {
        # Windows line endings in a patch make git am fail: write an LF copy
        $bytes = [System.IO.File]::ReadAllBytes($patch.FullName) | Where-Object { $_ -ne 13 }
        [System.IO.File]::WriteAllBytes($tmp, [byte[]]$bytes)
        git am -q $tmp
        if ($LASTEXITCODE -ne 0) { git am --abort 2>$null; throw "Patch failed: $($patch.Name)" }
    }
    Set-Content (Join-Path $Dest ".d012_patched") "$($patches.Count) patches applied"
    Write-Host "PortableKit ready: $Dest ($($patches.Count) patches)"
} finally { Pop-Location }
