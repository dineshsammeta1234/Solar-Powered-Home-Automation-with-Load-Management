# Makefile — Solar-Powered Home Automation (compile-only with Arduino CLI)
# Default board: Arduino UNO. Override FQBN/PORT at call time if needed.
# Examples:
#   make setup
#   make compile
#   make upload PORT=/dev/ttyACM0
#   make bench-snapshot

FQBN ?= arduino:avr:uno
PORT ?= /dev/ttyACM0
SKETCH_DIR := arduino/sketches/solar_controller
BUILD_DIR := build

.PHONY: setup compile upload clean bench-snapshot

setup:
	arduino-cli core update-index
	arduino-cli core install arduino:avr

compile:
	arduino-cli compile --fqbn $(FQBN) --build-path $(BUILD_DIR) $(SKETCH_DIR)

upload:
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH_DIR)

bench-snapshot:
	@python - <<'PY'
import csv, os
bench = "data/bench.csv"
metrics = "data/metrics.csv"
fields = ["accuracy","f1_weighted","latency_p50_ms","latency_p95_ms","throughput_rps"]
if not os.path.exists(bench):
    print("No bench.csv found at", bench); raise SystemExit(1)
rows = list(csv.DictReader(open(bench, newline='', encoding='utf-8')))
if not rows:
    print("bench.csv is empty"); raise SystemExit(1)
last = rows[-1]
with open(metrics, "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f); w.writerow(["metric","value"])
    for k in fields: w.writerow([k, last.get(k, "")])
print("Wrote", metrics, "from last run in bench.csv")
PY

clean:
	rm -rf $(BUILD_DIR)
