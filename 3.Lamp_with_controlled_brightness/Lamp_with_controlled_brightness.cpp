#include <Arduino.h>

#define LED_PIN 2
#define POD_PIN A0

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(POD_PIN, INPUT);
}

void loop()
{
    int rotation;
    int brightness;

    rotation = analogRead(POD_PIN);
    brightness = rotation / 4;

    analogWrite(LED_PIN, brightness);
}
//TODO
