# Arduino CLI — Quick Start

**Board:** Arduino UNO (default). Replace FQBN if you use another board.

```bash
# One-time
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli board list  # find your PORT

# Compile (UNO)
arduino-cli compile --fqbn arduino:avr:uno arduino/sketches/solar_controller

# Upload (replace PORT)
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno arduino/sketches/solar_controller
```
