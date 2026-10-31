# Dissidia 012 PC Port — Project Overview & Requirements

## 1. Current Project Status
* **Engine & Gameplay:** The game runs and is playable, but performance currently experiences slight slowdowns.
* **Texture Overhaul:** Approximately 90% of texture replacements are complete, with minor legacy assets remaining.
* **Font Assets:** System and UI fonts are not yet 100% HD.

---

## 2. Environment & Workflow Setup
* **Main Machine (Dev):** Primary PC used for coding, asset processing, and building binary files.
* **Secondary Machine (Test):** Deployment PC used strictly to test performance and compatibility on clean systems without dev tools installed.

---

## 3. Core Technical Goals
* **Full Native PC Architecture (No ISO Dependency):** 
  * Eliminate the need to read from or mount the original PSP `.ISO`.
  * Extract, convert, and stream all original game assets, scripts, and media directly from native file paths or custom archive packages.
* **Distribution & Deployment:**
  * Package all locally compiled binaries, asset folders, and dependencies into a standard Windows installer (`.msi` or `.exe`).
  * Ensure the output package allows one-click installation and execution on the secondary test machine.