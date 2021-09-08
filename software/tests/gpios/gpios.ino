/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
//GPS, PPS, uC, LoRa, LTE
int gpios[] = {15, 14, 6, 7, 12};


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);

  for (int i=0; i<5; i++){
    if (i < 3) {
      pinMode(gpios[i], INPUT_PULLDOWN);
    }
    else {
      pinMode(gpios[i], OUTPUT);
    }
    digitalWrite(gpios[i], HIGH);
  }
}

// the loop function runs over and over again forever
void loop() {
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
