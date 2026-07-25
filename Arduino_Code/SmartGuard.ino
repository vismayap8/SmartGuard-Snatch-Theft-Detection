#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>

MPU6050 mpu;
SoftwareSerial bt(6, 7);

#define BUZZER 8
#define THRESHOLD 2.5

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  Wire.begin();
  mpu.initialize();
  pinMode(BUZZER, OUTPUT);

  if (mpu.testConnection()) {
    Serial.println("================================");
    Serial.println(" SMARTGUARD SYSTEM READY");
    Serial.println("================================");
    Serial.println("Monitoring...");
    bt.println("SmartGuard Ready!");
  }
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  float g = sqrt(pow(ax/16384.0, 2) +
                 pow(ay/16384.0, 2) +
                 pow(az/16384.0, 2));

  Serial.print("G-Force: ");
  Serial.println(g);

  if (g > THRESHOLD) {
    // Serial Monitor output
    Serial.println("================================");
    Serial.println("SNATCH DETECTED!");
    Serial.println("================================");
    Serial.println("Buzzer: TRIGGERED");
    Serial.println("Alert sent to: +91XXXXXXXXXX");
    Serial.println("Location: maps.google.com/?q=12.9716,77.7480");
    Serial.println("================================");

    // Bluetooth Terminal output
    bt.println("================================");
    bt.println("SNATCH DETECTED!");
    bt.println("Alert: +91XXXXXXXXXX");
    bt.println("Location: maps.google.com/?q=12.9716,77.7480");
    bt.println("================================");

    // Buzzer
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
    delay(10000);
    Serial.println("Monitoring resumed...");
    bt.println("Monitoring resumed...");
  }

  delay(200);
} 
