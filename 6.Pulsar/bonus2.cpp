#include <Arduino.h>

// Измените исходную программу так, чтобы такой же результат был получен без использования операции %, но с применением условного оператора if.

#define CONTROL_PIN 9

int brightness = 0;

void setup()
{
    pinMode(CONTROL_PIN, OUTPUT);
}

void loop()
{
    brightness++;

    if (brightness == 256)
    {
        brightness = 0;
    }

    analogWrite(CONTROL_PIN, brightness);

    delay(10);
}