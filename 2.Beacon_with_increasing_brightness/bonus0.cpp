#include <Arduino.h>

#define LED_PIN = 3; // only pin changed

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    analogWrite(LED_PIN, 85);
    delay(250);
    analogWrite(LED_PIN, 170);

    delay(250);
    analogWrite(LED_PIN, 255);

    delay(250);
}
//TODO
