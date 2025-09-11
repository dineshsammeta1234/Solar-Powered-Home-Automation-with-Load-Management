# Legacy Notes

This document captures older approaches, deprecated features, and lessons learned during the development of the  
**Solar-Powered Home Automation with Load Management** project.  

It serves as a reference for future contributors to understand past design choices and avoid repeating mistakes.  

---

## 🕰️ Legacy Design Choices

1. **Manual Load Switching (Deprecated)**
   - Early versions required users to manually toggle loads using physical switches.
   - Replaced by **relay-based automatic switching** controlled by Arduino.

2. **Fixed Priority Load Management**
   - Initially, load priority was hardcoded (e.g., Fan > Light > Appliances).
   - Now replaced with **dynamic priority logic** configurable in software.

3. **Single Power Source (Solar Only)**
   - Early design relied only on solar energy, which caused frequent outages.
   - Updated to allow **hybrid mode**: solar + grid/battery backup (planned for future versions).

4. **Basic Voltage Thresholds**
   - Early implementation switched loads at static voltage cutoffs.
   - Now replaced with **smarter algorithms** using real-time sensor data smoothing.

---

## 🛠️ Deprecated Features

- **CSV-only Logging**: Replaced with optional **JSON + SQL database support** for flexibility.
- **Direct Arduino Serial Output**: Deprecated in favor of structured logs for Power BI / Grafana integration.
- **Wired-only Override Switch**: Deprecated with the introduction of **manual override via software/app (planned)**.

---

## 📚 Lessons Learned

- **Sensor Stability**: LDR and cheap voltage sensors caused noisy data.  
  → Introduced data smoothing and calibration.  

- **Load Management Logic**: Hardcoding logic was too rigid.  
  → Shifted toward modular, configurable code.  

- **Energy Efficiency**: Running non-essential appliances drained solar capacity quickly.  
  → Essential vs non-essential load classification was added.  

- **Documentation Matters**: Early contributors struggled without setup diagrams.  
  → Now every release includes **circuit diagrams and setup guides**.  

---

## 🔮 Future Migration Notes

- Migrate from **Arduino Uno → ESP32** for more memory, WiFi, and IoT integration.  
- Replace **basic relay modules → smart relays with current sensing**.  
- Explore **cloud integration (AWS IoT, Firebase, or Azure IoT Hub)** for scalability.  
- Build **cross-platform mobile app** for monitoring & manual control.  

---

## 📬 Contact
For legacy system questions, reach out:  
**Sammeta Dinesh Kumar**  
📧 [sammetadineshkumar@gmail.com](mailto:sammetadineshkumar@gmail.com)  
🔗 [LinkedIn](https://www.linkedin.com/in/dineshsammeta)  
[portifolio](https://dineshkumarsammeta.github.io/)
