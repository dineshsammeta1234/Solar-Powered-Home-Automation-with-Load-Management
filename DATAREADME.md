# Data README

This document describes the datasets, formats, and data handling procedures used in the  
**Solar-Powered Home Automation with Load Management** project.

---

## 📊 Data Sources
The system collects and generates data from the following sources:

1. **Solar Panel (Voltage & Current)**
   - Measures real-time solar energy availability.
   - Sensor: Voltage/Current Sensor (e.g., INA219 or similar).

2. **Appliance Load Data**
   - Monitors ON/OFF state of connected devices (fans, lights, small appliances).
   - Captured via relay modules and Arduino logic.

3. **Environmental Sensors (Optional)**
   - Light sensor (LDR) for ambient brightness.
   - Temperature sensor (DHT11/DHT22) for thermal load monitoring.

---

## 🗂️ Data Formats

| Data Type              | Format    | Example                             |
|------------------------|-----------|-------------------------------------|
| Voltage & Current Logs | CSV/JSON  | `{"time": "2025-09-11T10:00Z", "voltage": 5.1, "current": 1.2}` |
| Appliance States       | JSON/CSV  | `{"fan": "ON", "light": "OFF"}`    |
| Energy Consumption     | SQL Table | `timestamp | device | power_used`   |
| Sensor Data            | CSV/JSON  | `{"light_level": 320, "temp": 27}` |

---

## 🗄️ Data Storage

- **Local Storage**  
  - Arduino / Raspberry Pi stores data temporarily in memory.  
  - Logs can be exported as CSV/JSON via serial monitor or SD card.  

- **Database (Optional)**  
  - MySQL / SQLite used for structured storage of logs and consumption data.  

- **Cloud Storage (Optional)**  
  - AWS S3, Google Sheets, or Firebase can be integrated for remote logging.  

---

## 📈 Data Usage

- **Load Management**: Prioritizing appliances based on available solar energy.  
- **Visualization**: Power BI / Grafana dashboards for monitoring solar power vs load consumption.  
- **Automation**: Auto-switching appliances based on thresholds.  
- **Research & Optimization**: Historical data analysis for efficiency improvements.  

---

## 🔒 Data Privacy & Security

- Data is **not shared externally** unless explicitly configured for cloud storage.  
- Sensitive information (user settings, energy patterns) should be stored securely.  
- If using cloud integration, ensure encryption (HTTPS, TLS) and restricted access.  

---

## 📬 Contact

For data-related queries, reach out:  
**Sammeta Dinesh Kumar**  
📧 [sammetadineshkumar@gmail.com](mailto:sammetadineshkumar@gmail.com)  
🔗 [LinkedIn](https://www.linkedin.com/in/dineshsammeta)  

