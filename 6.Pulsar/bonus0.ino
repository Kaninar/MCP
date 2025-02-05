#include <Arduino.h>
// 1. Измените программу так, чтобы яркость шкалы росла только до половины от максимальной.

#define CONTROL_PIN 9

int brightness = 0;

void setup()
{
    pinMode(CONTROL_PIN, OUTPUT);
}

void loop()
{
    brightness = (brightness + 1) % (256 / 2);

    analogWrite(CONTROL_PIN, brightness);

    delay(10);
}
