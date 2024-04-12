#include <SoftwareSerial.h>
//mariandechavez.wordpress.com
//The purpose of the code is to connect your microcontroller and sensors to the android app you will create.
//The data is transferred through Bluetooth/wirelessconnection

SoftwareSerial BTSerial(2, 3); // RX, TX

const int potPin = A0; // Connect potentiometer to analog pin A0

void setup() {
  Serial.begin(9600); // Initialize serial communication
  BTSerial.begin(9600); // Initialize Bluetooth serial communication
  Serial.println("Bluetooth communication initialized");
}

void loop() {
  // Read the value from the potentiometer
  int sensorValue = analogRead(potPin);

  // Map the sensor value from 0-1023 to 0-100
  int outputValue = map(sensorValue, 0, 1023, 0, 103);

  // Send the output value over Bluetooth
  BTSerial.println(outputValue);
  
  Serial.print("Temperature: ");
  // Serial.println(sensorValue);
  // Serial.print("Mapped Output Value: ");
  Serial.println(outputValue);

  delay(100); // Delay for stability
}
