# Solar-Powered Home Automation with Load Management

## Project Overview
This project demonstrates a **solar-powered home automation system** that controls lights, fans, and small appliances based on the availability of solar energy. It uses **Arduino** (or Raspberry Pi), relays, and sensors to automatically manage loads, prioritize essential devices, and ensure efficient use of renewable energy.  

Project Timeline: 14/11/2013 to 16/02/2014(Part -Time), VIT University, Vellore, India.
Modernisation (2025): This repo was open-sourced and lightly refreshed (docs, CI, tests).
Commit dates in 2025 reflect publication/cleanup, not the original build. 
---

## Features
- **Solar Power Integration:** Loads are powered primarily by solar energy.  
- **Automatic Load Management:** Prioritizes essential appliances when solar power is limited.  
- **Relay-Based Switching:** Automatic on/off switching of devices based on sensor readings.  
- **Manual Override:** Users can manually control devices if needed.  
- **Affordable & Easy:** Uses widely available components for practical implementation.  

---

## Modules Covered
| Module | Application in Project |
|--------|----------------------|
| Basic Electrical Engineering | Circuit design, wiring, and basic electrical components |
| Renewable Energy Sources | Solar panel integration as the primary energy source |
| Electric Drives & Control | Control of DC/AC motors (fans, pumps) |
| Special Motors | Small appliances motor control |
| Distributed Generation | Solar energy as distributed energy |
| Power System Protection & Switchgear | Fuses, relays for safe operation |
| Creative & Management | Designing system layout and implementing the prototype |

---
## Bill of Materials (BOM) & Pin-map

BOM (short): 6–12 V solar panel; charge controller (optional, list model); Arduino Uno or
Raspberry Pi; 2/4-ch relay module (≥250 VAC, ≥10 A contacts); LDR/voltage sensor; DC
fan/LED bulbs; inline fuse/RCBO; wiring. 

Pin-map (Uno): D2→Relay-1 (Essential-1); D3→Relay-2 (Essential-2); D4→Relay-3 (Nonessential-1); A0→Voltage sensor; A1→LDR; GND/5 V as per module specs. (Adjust to match your
sketch.)
## Load-priority logic (summary)

Decision rules: compute pv_net = pv_watts − house_watts.
 If pv_net > 120 W for ≥15 s → enable Essential-1; hysteresis 30 W.
 If pv_net > 250 W for ≥15 s → enable Essential-2; hysteresis 40 W.
 Else shed Non-essential in reverse order, respecting min-on/off 60 s.
Manual override: relays obey front-panel switch; controller resumes control on next
cycle. (Tune numbers to your demo.) 

## Safty

Safety: Mains switching is dangerous. Use proper isolation, relay modules with adequate
AC ratings, snubbers/SSRs for inductive loads, and appropriate fuse/RCBO protection. Work
with a qualified person where required. 
This repo includes a minimal sketch for the **solar load controller** and a **CI workflow** that compiles it using Arduino CLI.

## Install Arduino CLI
```bash
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli version
```

## Cores & board (UNO example)
```bash
arduino-cli core update-index
arduino-cli core install arduino:avr
```

## Compile
```bash
arduino-cli compile --fqbn arduino:avr:uno arduino/sketches/solar_controller
```

## Upload (set your serial port)
```bash
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno arduino/sketches/solar_controller
```

> If you use a different board (e.g., ESP32), install the appropriate core and update the **FQBN** in commands and CI.

## Components Required
- Arduino Uno (or Raspberry Pi)  
- Solar panel (5V–12V)  
- Relay module (for AC load switching)  
- Light sensor / voltage sensor  
- DC/AC fan, LED bulbs, or small appliances  
- Jumper wires, breadboard, resistors, fuses  

---

## Contact  
For questions, collaboration, or feedback, please contact:  
**Sammeta Dinesh Kumar** — [sammetadineshkumar@gmail.com]
- 🌐 [Portfolio](https://dineshkumarsammeta.github.io/)
- 🔗 [LinkedIn](https://www.linkedin.com/in/dineshsammeta)   

## Circuit Diagram
## Circuit Diagram
<img src="https://github.com/user-attachments/assets/a3c35a71-13be-41d4-a4fc-9520a1547d58" alt="Circuit Diagram" width="720" height="480">  

*Include an image of your wiring diagram here.*

