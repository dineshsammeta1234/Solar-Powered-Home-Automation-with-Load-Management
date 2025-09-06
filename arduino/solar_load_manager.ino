// Solar-Powered Home Automation (2014 Project, Modernized)

int relay1 = 2; // Light
int relay2 = 3; // Fan
int relay3 = 4; // Appliance
int sensorPin = A0; // Solar voltage sensor

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int solarVoltage = analogRead(sensorPin);

  Serial.print("Solar Voltage: ");
  Serial.println(solarVoltage);

  if (solarVoltage > 700) { 
    digitalWrite(relay1, HIGH); // Turn ON Light
    digitalWrite(relay2, HIGH); // Turn ON Fan
    digitalWrite(relay3, HIGH); // Turn ON Appliance
  } else if (solarVoltage > 400) {
    digitalWrite(relay1, HIGH); 
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, LOW); // Save energy
  } else {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
  }

  delay(1000);
}
