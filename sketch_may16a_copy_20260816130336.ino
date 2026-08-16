#include <Servo.h>

Servo myServo;

char lastCommand = '\0';

void setup() {
  Serial.begin(9600);
  myServo.attach(9);

  myServo.write(0);   // Default position
  delay(2000);
}

void loop() {

  if (Serial.available() > 0) {

    char cmd;
    while (Serial.available() > 0) {
      cmd = Serial.read();
    }

    if (cmd == lastCommand)
      return;

    lastCommand = cmd;

    // Other object -> immediately go to 0°
    if (cmd == 'o') {
      myServo.write(0);

      while (Serial.available() > 0) {
        Serial.read();
      }
      return;
    }

    int angle;

    if (cmd == 'r')
      angle = 135;      // Ripe tomato
    else if (cmd == 'u')
      angle = 180;      // Unripe tomato
    else
      return;

    // Move servo
    myServo.write(angle);

    // Stay there for 20 seconds
    delay(20000);

    // Return to default position
    myServo.write(0);

    delay(1500);

    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}