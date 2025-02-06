#include <Arduino.h>
#include <Servo.h>

#define POT_MAX_ANGLE 270.0

Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int val = analogRead(A0);
    int angle = int(val / 1024.0 * POT_MAX_ANGLE);

    myServo.write(angle);
}
