# ASTRIA: Bioastronautics Crew-Health Copilot

**NASA Space Apps Challenge 2026 · "Create Health Monitoring Software for Astronauts"**

ASTRIA is a Windows desktop app, built in C++ with Qt 6, that helps a flight surgeon monitor astronaut health during long missions. It shows vital signs, the 3D heart and body, blood, environment and eye screening in one place. The design follows the team's Figma file *ASTRIA_NasaSpaceApps*.

> ⚠️ **Prototype, not a medical device.** All data is synthetic, based on published NASA ranges. It is not for clinical use.

---

## ⬇️ Download & install from GitHub

This repository contains the **ready-to-run Windows build**. No Qt, compiler or installer is needed.

### Option 1: Download ZIP (easiest)
1. On this repository page, click the green **`<> Code`** button, then **Download ZIP**.
2. Find the ZIP in your Downloads folder, right-click it and choose **Extract All…**, then **Extract**.
   *Don't run the app from inside the ZIP. Windows can't load its DLLs from there.*
3. Open the extracted folder (`…-main`). The build folder contains `Astria.exe` with its `platforms\`, `sqldrivers\`, `tls\` … folders.

### Option 2: Git clone
```bash
git clone https://github.com/<user>/<repo>.git
cd <repo>
```

## ▶️ Launch the app

1. Double-click **`Astria.exe`**.
2. If Windows SmartScreen shows *"Windows protected your PC"*, click **More info**, then **Run anyway**. The app is unsigned because it's a hackathon build.
3. On the first start ASTRIA creates its database at `Documents\ASTRIA\astria.db` and fills it with a sample mission: 4 crew members, Sol 142.

**Requirements:** Windows 10 or 11 (64-bit). A screen of 1600 × 900 or larger is recommended; the UI scales down automatically.

### Optional: turn on the AI Health Bot
The Health Bot can answer questions with **NVIDIA Nemotron 3 Ultra** (free tier through OpenRouter), using the live mission data. Without a key it uses its built-in offline rules.
1. Create a free key at <https://openrouter.ai/keys>.
2. Save it as a plain-text file named `openrouter.key` in `Documents\ASTRIA\`, or set the environment variable `OPENROUTER_API_KEY`.
3. Restart `Astria.exe`.

### Command-line options (from PowerShell in the app folder)
```powershell
.\Astria.exe --export-csv C:\out     # export every table to CSV, no window
.\Astria.exe --import-csv C:\in      # import <table>.csv files back
.\Astria.exe --db D:\demo.db         # use a different database file
```

### If something goes wrong
| Problem | Fix |
|---|---|
| "Qt6Core.dll / VCRUNTIME not found" | You started it from inside the ZIP, or moved `Astria.exe` out of its folder. Keep the exe next to its DLLs and sub-folders. |
| Nothing happens on double-click | Check that the antivirus didn't quarantine it. Right-click the file, choose **Properties**, then **Unblock**. |
| Start with fresh data | Close the app, delete `Documents\ASTRIA\astria.db`, and start it again. |

---

## ✨ Features

| Screen | What it does |
|---|---|
| **Overview** | Mission health dashboard: status strip, crew cards with live heart rate, ECG / respiration / SpO₂ streams, cabin environment, event log, telemetry link. |
| **Crew health** | Body composition, bone density (DXA T-score), grip and dynamometer strength, endurance and balance; 140-day lean-mass / bone / strength trends; fitness-for-duty gate; fatigue algorithm; adaptation envelope. |
| **Biotelemetry & biometric twin** | Rotatable 3D "digital twin" with 6 sensor nodes (neuro, cardiovascular, respiratory, metabolic, musculoskeletal / DXA, wearables), layer filters, sensor detail windows, live Lead II ECG, Cognitive Pulse test (reaction time + mood → Behavioral Drift Index). |
| **Environment & habitat** | Cabin atmosphere and life-support (ECLSS) table, CO₂ margin, nutrition, hydration and kidney balance, personal CO₂ dose meter, radiation exposure ledger with solar-storm shelter clock. |
| **Alerts & health tasks** | Active advisories with Acknowledge, daily health checklist, ground dispatch feed, Earth-independence dial (how long a reply from Earth takes, ISS → Mars) and compressed "delta packets" for downlink. |
| **Reports & trends** | Pre-, in- and post-flight forecasts, KPI cards, musculoskeletal corridor chart, audit table, CSV / PDF export. |
| **SANS eye screener** | Full-screen dark module: pupil-reflex capture with a latency curve, Amsler-grid distortion drawing per eye, 3D schematic eye and Safe / Warning / Critical status, plan-only LBNP preview, saves to the crew-medical review. |
| **Heart 3D** | Animated 3D heart driven by the data: anatomy, electrical activation, oxygenation and workload views, pressure-volume loop, hemodynamics (SV, CO, EF, MAP). |
| **Body 3D** | 3D body with skin, 18 muscle groups and the full skeleton. Click any structure for its recordings; change and normality lenses, tissue cross-section, dynamometer replay that moves the joint, bone health against WHO and NASA criteria. |
| **Blood** | Animated vessel (cell count, oxygen colour, clotting, virus markers), centrifuge-tube view, 20 lab range bars with trends, jugular-vein clot screen. |
| **Data** | Edit every table directly, quick-entry forms, simulation or manual mode, CSV export / import at any time. |
| **HB Health Bot** | Chat assistant on the Overview. It answers with live mission data, through the AI model or offline rules, and every answer is tagged with its source. |

**Keyboard:** Ctrl+1 … Ctrl+0 switch pages, and Ctrl+Shift+E exports all data to CSV.

---

# Developer guide

> The sections below are for building ASTRIA from source. The source is not part of this release repository.

## Quick start

```powershell
powershell -ExecutionPolicy Bypass -File build.ps1    # configure + build + deploy Qt DLLs
build\Astria.exe                                      # launch
```

## 1. Prerequisites

| Tool | Version used | Where |
|---|---|---|
| Qt | 6.12.0, **MinGW 64-bit** kit, modules *Widgets, Sql, Network* | `C:\Qt\6.12.0\mingw_64` |
| MinGW compiler | 13.1 (ships with Qt) | `C:\Qt\Tools\mingw1310_64` |
| CMake + Ninja | ship with Qt (*Developer and Designer Tools*) | `C:\Qt\Tools\CMake_64`, `C:\Qt\Tools\Ninja` |
| OS | Windows 10/11 (Linux/macOS work with any Qt 6 kit and the manual CMake commands) | |

If Qt is installed somewhere else, edit the `$Qt` / `$Tools` paths at the top of `build.ps1`.

## 2. Build

**A. Script (recommended)**

```powershell
powershell -ExecutionPolicy Bypass -File build.ps1
```

`build.ps1` does the following:
1. Puts Qt, MinGW, CMake and Ninja on the `PATH`.
2. Runs `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release`.
3. Runs `cmake --build build --parallel`.
4. Runs `windeployqt` to copy the Qt DLLs, platform, sqldriver and tls plugins next to the exe.

The result is `build\Astria.exe`. The whole `build\` folder is portable: zip it and run it on any Windows PC without installing Qt.

**B. Manual CMake (any OS)**

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=<path-to-Qt>/6.12.0/<kit>
cmake --build build --parallel
```

**C. Qt Creator**

Open `CMakeLists.txt`, choose the *Desktop Qt 6.x MinGW 64-bit* kit, then press **Run** (Ctrl+R).

> **Rebuild error "Permission denied" on Astria.exe:** the app is still running. Close it first, or run
> `Get-Process Astria | Stop-Process`.

## 3. Launch

```powershell
build\Astria.exe                                   # normal start
build\Astria.exe --db D:\demo.db                   # use another database file
build\Astria.exe --export-csv C:\out               # export all tables to CSV, no window
build\Astria.exe --import-csv C:\in                # restore <table>.csv files, no window
build\Astria.exe --screenshots C:\shots            # render every screen to PNG and exit (QA, uses a throw-away DB)
```

On the first start the app creates `Documents\ASTRIA\astria.db` and seeds a sample mission: 4 crew, Sol 142, plus vitals, musculoskeletal, blood and environment history.

**Keyboard:** Ctrl+1 … Ctrl+0 switch pages, and Ctrl+Shift+E exports every table to CSV.

### AI Health Bot (optional)

The Health Bot can answer with **NVIDIA Nemotron 3 Ultra** through OpenRouter, using the live mission data as context. The key is looked up in this order:
1. The environment variable `OPENROUTER_API_KEY`
2. The file `Documents\ASTRIA\openrouter.key`, containing only the key

```powershell
$env:OPENROUTER_API_KEY = "sk-or-v1-..."; build\Astria.exe
```

Without a key, or when the network fails, HB falls back to its built-in offline rule engine. Never commit the key to the repository.

## 4. How the program starts: `src/main.cpp`

```text
main()
 ├─ QApplication + Fusion style
 ├─ Theme::uiScale()  ← screen width (fits the 1800 px Figma layout on smaller screens)
 ├─ palette, Inter font, global stylesheet  (Theme.h = Figma colour tokens)
 ├─ parse flags: --db, --screenshots, --import-csv, --export-csv
 │     └─ CSV flags run headless and return without opening a window
 ├─ MainWindow w          → builds header, sidebar, page stack, Health Bot
 │     └─ Model::instance()  → opens SQLite (Database.cpp), seeds on first run,
 │                             loads crew/vitals/env/events, starts a 1 s simulation timer
 ├─ --screenshots? → visit every page, grab PNGs, quit
 └─ w.show(); return app.exec();   ← Qt event loop
```

**Runtime data flow**

```text
Model (1 s tick) ──signals ticked / dataChanged / eventsChanged / selectionChanged──▶ every page refreshes
     ▲                                                                               │
     └──── Database (SQLite) ◀── Data page edits, Quick entry, CSV import ◀──────────┘
Health Bot ── question + live data snapshot ──▶ AiClient (OpenRouter) ──▶ answer (or offline rules)
```

**MainWindow page stack:** 0 Overview · 1 Crew health · 2 Biotelemetry · 3 Environment · 4 Alerts · 5 Reports · 6 SANS (full-screen, dark) · 7 Data · 8 Heart 3D · 9 Body 3D · 10 Blood.

## 5. Troubleshooting

| Problem | Fix |
|---|---|
| `Qt6Core.dll not found` | Run `build.ps1` again, which calls windeployqt. Or start the exe from a Qt command prompt. |
| `QSqlDatabase: QSQLITE driver not loaded` | The `build\sqldrivers\` folder is missing. Re-run windeployqt. |
| HB says "AI unavailable: TLS…" | The `build\tls\` folder is missing. Re-run windeployqt. |
| HB says "AI unavailable: 401 / 429" | The key is invalid, or the free-tier rate limit was hit. HB still answers offline. |
| Layout too large | The UI scales from the screen width automatically. Maximize the window. |
| Start over with fresh data | Close the app and delete `Documents\ASTRIA\astria.db`. It is re-seeded on the next start. |

## Your data: where it lives and how to work with it

All data is stored in **one SQLite file**, `Documents\ASTRIA\astria.db`. It is created and filled with a sample mission on first run. Everything you change is saved immediately and is still there after a restart.

Open the **Data** page (sidebar, or Ctrl+8):

- **Storage**
  - **Data source:**
    - **Simulation** generates live readings and records them every *N* seconds.
    - **Manual entry only** shows exactly what you stored.
  - **CSV format:**
    - **Standard** uses `,` as the separator and `.` for decimals.
    - **Excel regional** uses `;` and `,`. Pick it if Excel opens a CSV as one column.
- **Quick entry:** forms for vital signs, cabin environment, lab results and medical events. They are pre-filled with the latest values, and each entry is time-stamped in UTC.
- **Table editor:** one list entry per table.
  - Double-click a cell to edit it; changes save instantly.
  - Search, filter by crew member, add or delete rows.
  - Export the current table to CSV, or import a CSV into it (add rows or replace the table).

| Table | Contents |
|---|---|
| crew | roster + personal baselines (edit names, baselines, sleep, work hours) |
| vitals | HR, SpO₂, respiration, skin/core temperature, blood pressure |
| environment | cabin + personal CO₂, O₂, temperature, humidity, pressure, dose rate |
| events | medical event log (Open / Acknowledged / Resolved) |
| labs | SSM blood / urine / saliva results (used by the Health Bot's hydration check) |
| cognitive | Cognitive Pulse results (saved automatically after each PVT) |
| sans | eye exams (saved by "Evaluate & save exam" on the SANS page) |
| settings | flight day, launch date, career dose, data mode, record interval, CSV format |

**Export everything to CSV, any time:**
- **Ctrl+Shift+E**
- **Data → Export ALL tables to CSV**
- **Reports → Export HRP Package → CSV**

Any of these writes one `<table>.csv` per table.

CSV import matches columns by header name, so you can edit an exported CSV in Excel and import it back.

### Command line

```powershell
build\Astria.exe --export-csv C:\path\to\folder        # export all tables, no window
build\Astria.exe --import-csv C:\path\to\folder        # restore <table>.csv files (replaces those tables)
build\Astria.exe --db D:\other.db                      # use a different database file
build\Astria.exe --screenshots C:\path\to\folder       # render every page to PNG (throw-away database)
```

The database can also be opened with any SQLite tool, e.g. *DB Browser for SQLite*.

## Screens (sidebar, Ctrl+1 … Ctrl+7)

| Page | Contents | Blueprint features |
|---|---|---|
| Overview | Status strip, CO₂ advisory, 4 crew cards, live ECG / HR / resp / SpO₂, cabin environment, event log, telemetry link | Figma frame 1 |
| Crew health | **Figma "Crew Health" frame** (subject strip, body composition / DXA / strength / endurance KPIs, 140-day lean-mass, bone and strength chart, isokinetic bars, sensorimotor and composition cards, filled from the musculoskeletal tables), then the ASTRIA tools: Fitness-for-Duty Gate (weakest-link, radar, what-if sliders), fatigue algorithm with EVA / robotics lockout, Adaptation Envelope with flight-day scrubber | H5, H3, ExMC Alg. 2 |
| Biotelemetry | **Figma "Biotelemetry & biometric twin" frame**: light 3D twin with 6 sensor nodes and info cards, layer tabs (All / Cardiovascular / Musculoskeletal / DXA / Neuro-Cognitive), 360° rotate, anterior and posterior views, camera preview, sensor detail dialogs, live Lead II ECG, connected systems. Below it: live vitals table, large ECG, Cognitive Pulse (typing dynamics, 8-trial PVT, mood) → Behavioral Drift Index | H4 |
| Body 3D (Ctrl+0) | Rotatable 3D body: skin with adjustable transparency, 18 muscle groups and the skeleton (skull, spine, ribs, pelvis, limbs, hands, feet). Click any structure to see its recordings. Anatomy / Change / Normality lenses, timeline + timelapse, tissue cross-section (skin, fat, muscle, cortical and trabecular bone), dynamometer replay that moves the joint, bone normality (WHO and NASA expected loss), whole-body composition. Variables are listed in [docs/ASTRIA_Data_Dictionary.md](docs/ASTRIA_Data_Dictionary.md) | musculoskeletal |
| Blood | Animated vessel: cell density from the blood count, colour from SpO₂, pulsing with heart rate, fibrin clot shown when D-dimer is high, virus particles when EBV is detected. Centrifuged-tube comparison, 20 range bars with status and trend, jugular-vein clot screen with the ExMC Enoxaparin action, sample-chain tracking | blood_panel, vascular_scan |
| Heart 3D (Ctrl+9) | Rotatable 3D heart with chambers, great vessels and coronaries. Driven by live, stored (replay) or what-if data. Four lenses: Anatomy, Electrical activation, Oxygenation, Workload. Beat-synced ECG, LV pressure-volume loop, hemodynamics (SV, CO, EF, MAP, RPP, sphericity) and plain-language findings | T6 / digital twin |
| Environment | **Figma "Environment & habitat" frame**: cabin atmosphere, nutrition, fluid and urine/osmolality KPIs, ECLSS table with references, CO₂ margin, nutrition, hydration and renal cards, ECLSS CSV export, "Log environment event". Below it: personal CO₂ burden meter, Pocket Sentinel, 24 h trend, dose per day, radiation Exposure Ledger, SPE storm-shelter clock, ECLSS detail | H6, T1, T13 |
| Alerts | **Figma "Alerts & Health Tasks" frame**: active advisories with Acknowledge (open events), daily health protocols (ticks saved per sol), NASA ground dispatch feed, uplink footer. Below it: Earth-Independence Dial + reply window (ISS → Mars), ACT NOW / ACT AND NOTIFY / WAIT SAFELY, Delta Packet A/B/C with byte counts + DTN outbox + reply ingestion, full event log | H1, H2 |
| Reports & trends | Pre-flight / in-flight / post-flight forecast, KPI cards, musculoskeletal corridor chart, neuro-cognitive vs sleep, audit table, CSV / PDF export | Figma frame 2 |
| SANS | **Full-screen dark Figma SANS module** (sidebar and header hidden): 01 reflex capture (alignment preview, 3-second auto-flash countdown, pupil latency trace), 02 Amsler field mapping (draw traces per eye with undo/clear and a distortion preview), 03 ocular assessment (rotatable schematic eye, Safe/Warning/Critical status, LBNP plan-only preview, "Send for crew-medical review" saves to the `sans` table, summary export), plus the Flight interface kit. "Go Back To Overview" returns. Demo data only, no camera or hardware | T3, T4 |

**HB — Health Bot** (the right-hand panel) is a deterministic, offline rule engine. It can explain HR, CO₂, sleep, radiation, SANS, the EVA gate, hydration and the medical kit. Every answer carries a provenance tag.
The mission selector in the header (ISS / Gateway / Lunar / Mars) drives the autonomy tier.

## Code map

- `src/main.cpp`: entry point (see section 4)
- `src/MainWindow.*`: window shell, page stack, per-page header/sidebar/bot visibility, shortcuts
- `src/AiClient.*`: OpenRouter / Nemotron client for the Health Bot (key lookup, live-data context, history)
- `src/Theme.h`: design tokens (colours, fonts, stylesheet)
- `src/Database.*`: SQLite schema, settings, CSV export/import (RFC-4180, both separator formats)
- `src/DataPage.*`: Data manager page (storage settings, quick entry, table editor)
- `src/Model.*`: loads from and records to the database, the simulation loop, and the ExMC decision logic (gate, autonomy tier, CO₂ odds, SANS, fatigue)
- `src/Widgets.*`: custom-painted components (ECG, charts, dial, radar, shield, gauges, icons, nav)
- `src/Chrome.*`: header, sidebar, status strip, Health Bot
- `src/Pages.*`: Overview and Reports (Figma screens)
- `src/HeartPage.*`: procedural 3D heart mesh, software renderer (smooth-shaded, depth-sorted), cardiac-cycle / PV-loop model, Heart page
- `src/FeaturePages.*`: ASTRIA tools under Crew health, Biotelemetry, Environment, Alerts
- `src/FigmaKit.*`, `src/FigmaBlocks.h`, `src/FigmaCrew/Alerts/Env/Bio*.cpp`: Figma frames for those four pages (the twin reuses the Body 3D renderer in a light style)
- `src/SansModule.*`, `src/SansSteps.cpp`, `src/SansWidgets.cpp`, `src/SansUi.h`: the dark SANS screener
