#include <Arduino.h>
#include <Servo.h>

Servo myServo;

const unsigned char angles[]{45, 135, 87, 0, 65, 90, 180, 150};

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int val = analogRead(A0);

    int mapped = map(val, 0, 1023, 0, 8);

    myServo.write(angles[mapped]);

    delay(500);
}
