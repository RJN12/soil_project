int sensorPin = A0; // Soil moisture sensor pin
int relayPin = 2;  // Relay module pin
int sensorValue = 0;
int threshold = 500; // Adjust this value based on your soil moisture sensor readings

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure the relay is off at startup
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Soil Moisture: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    digitalWrite(relayPin, HIGH); // Turn on the pump
    Serial.println("Pump ON");
  } else {
    digitalWrite(relayPin, LOW); // Turn off the pump
    Serial.println("Pump OFF");
  }

  delay(2000); // Wait for 2 seconds before taking another reading
}
