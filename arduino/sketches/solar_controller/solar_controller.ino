/*
  Solar Controller Demo (UNO)
  - Relay on D7 (simulated load)
  - Status LED on built-in LED
  - Simple voltage-based hysteresis using A0 (simulate PV/battery input)
  This sketch is for CI compile tests and demos only.
*/
const int RELAY_PIN = 7;
const int SENSOR_PIN = A0;
const float VREF = 5.0;       // ADC reference
const int ADC_MAX = 1023;
const float ON_THRESHOLD  = 3.8;  // Volts
const float OFF_THRESHOLD = 3.6;  // Volts

bool relayOn = false;

float readVoltage() {
  int raw = analogRead(SENSOR_PIN);
  return (raw * VREF) / ADC_MAX;
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  float v = readVoltage();

  if (!relayOn && v >= ON_THRESHOLD) {
    relayOn = true;
    digitalWrite(RELAY_PIN, HIGH);
  } else if (relayOn && v <= OFF_THRESHOLD) {
    relayOn = false;
    digitalWrite(RELAY_PIN, LOW);
  }

  digitalWrite(LED_BUILTIN, relayOn ? HIGH : LOW);
  delay(200);
}
