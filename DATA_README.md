# DATA_README — Solar‑Powered Home Automation with Load Management

**Last updated:** 2025-09-09

## Data & Measurements
This repository tracks **bench measurements** to verify controller behaviour and provide recruiter‑visible evidence.

### Files
- `data/bench.csv` — append‑only log (one row per bench/run).
- `data/metrics.csv` — snapshot of headline metrics copied from the latest bench run.

### Suggested columns in `bench.csv`
- **run_id**: unique identifier (e.g., SHA-YYYYMMDD-###)
- **date_iso**: ISO date of the run
- **board**: Arduino board FQBN (e.g., `arduino:avr:uno`)
- **firmware_version**: semantic version of the sketch
- **pv_source**: PV/power source used (panel spec or PSU setting)
- **battery_source**: battery pack or simulator
- **bench_duration_min**: minutes measured
- **relay_cycles**: number of on/off cycles
- **switch_latency_p50_ms / p95_ms**: median and p95 switching latency
- **min_battery_soc_pct**: minimum State‑of‑Charge seen during the run
- **pv_yield_wh / energy_saved_wh**: approximate energy contribution and saving
- **notes**: short free‑text note

## Reproducing bench runs
1. Ensure **low‑voltage** only (e.g., 5–12V DC). **Do not** connect or demonstrate **mains AC** in this repository.
2. Flash the firmware (Arduino CLI example in docs/ and CI). Confirm LEDs/relays toggle as expected.
3. Record observations with timestamps; append a new row to `data/bench.csv`.
4. Copy a small subset of headline metrics to `data/metrics.csv` (snapshot for README).

## Privacy & Safety
- Avoid images/data that reveal addresses or proprietary facility layouts.
- Keep all guidance constrained to **safe low‑voltage DC**. If you do mains integration offline, never document it in this public repo.
