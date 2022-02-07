//Addresses for reading
#define LIS2DE12Address 0x19 //Device Address 
#define reader 0x33
#define writer 0x32
#define OUT_X_H 0x29 // X acceleration register
#define OUT_Y_H 0x2B
#define OUT_Z_H 0x2D
#define WHO_AM_I 0x0F

#include "SoftwareI2C.h"
SoftwareI2C softwarei2c;

void getData(byte *a)
{
  softwarei2c.beginTransmission(LIS2DE12Address); // Calling the sensor
  softwarei2c.write(OUT_X_H);  // Moving Register pointer to OUT_X_H
  softwarei2c.endTransmission(); // End
  softwarei2c.requestFrom(LIS2DE12Address,1); //Request information I asked
  *a = softwarei2c.read(); // Read and store data
}
void showData()
{
  byte aa;
  int b1 = 0;
  Serial.print(b1);
  getData(&aa);
  b1 = aa;
  Serial.println(b1);
  delay(500);
}

//GPS, PPS, uC, LoRa, LTE
int gpios[] = {5, 36, 40, 21, 13};


// the setup function runs once when you press reset or power the board
void setup() {
  delay(3000);
  Serial.begin(115200);
  Serial.println("Setting up...");

  for (int i=0; i<5; i++){
    if (i < 3) {
      pinMode(gpios[i], INPUT_PULLDOWN);
    }
    else {
      pinMode(gpios[i], OUTPUT);
    }
    digitalWrite(gpios[i], HIGH);
  }
  softwarei2c.begin(26, 27);       // sda, scl
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Looping...");
  for (int i=0; i<5; i++){
    if (i < 3) {
      pinMode(gpios[i], INPUT_PULLUP);
    }
    else {
      digitalWrite(gpios[i], LOW);
    }
    Serial.print("Pin going low: ");
    Serial.println(i);
    delay(100);
  }

  showData();

  for (int i=0; i<5; i++){
    if (i < 3) {
      pinMode(gpios[i], INPUT_PULLDOWN);
    }
    else {
      digitalWrite(gpios[i], HIGH);
    }
    Serial.print("Pin going high: ");
    Serial.println(i);
    delay(100);
  }
  Serial.println("Looping...");
}
