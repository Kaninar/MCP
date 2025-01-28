#include <Arduino.h>

// Измените программу так, чтобы шкала становилась максимально яркой в три раза быстрее, без изменения функции delay.

#define CONTROL_PIN 9

int brightness = 0;

void setup()
{
    pinMode(CONTROL_PIN, OUTPUT);
}

void loop()
{
    brightness = (brightness + 86) % 256;

    analogWrite(CONTROL_PIN, brightness);

    delay(10);
}