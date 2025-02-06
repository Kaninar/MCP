#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int lightness = analogRead(A0);
    int angle = map(lightness, 0, 1023, 180, 0);

    myServo.write(angle);
}