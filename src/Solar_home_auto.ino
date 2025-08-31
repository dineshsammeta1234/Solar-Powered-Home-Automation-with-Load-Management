#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int relay1 = 8;  // Essential Load
const int relay2 = 9;  // Non-essential Load
const int solarSensor = A0;
const int battSensor = A1;

float solarVoltage = 0;
float battVoltage = 0;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  
  lcd.begin(16, 2);
  lcd.print("Solar Home Auto");
}

void loop() {
  solarVoltage = analogRead(solarSensor) * (5.0 / 1023.0) * 10; // adjust factor
  battVoltage = analogRead(battSensor) * (5.0 / 1023.0) * 5;   // adjust factor

  lcd.setCursor(0, 1);
  lcd.print("Batt:");
  lcd.print(battVoltage);

  if (solarVoltage > 12.0 && battVoltage > 12.5) {
    digitalWrite(relay1, HIGH); // Turn on essential load
    digitalWrite(relay2, HIGH); // Turn on non-essential load
  } else if (battVoltage > 11.8) {
    digitalWrite(relay1, HIGH); // Only essential load
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW); // switch to grid (manual relay)
  }

  delay(1000);
}
