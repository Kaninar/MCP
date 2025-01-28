#include <Arduino.h>
// Переделайте программу так, чтобы вместо int pin = FIRST_LED_PIN + (ms / 120) % 10 перемещением огонька управлял цикл for
#define FIRST_LED_PIN 2
#define LAST_LED_PIN 11

void setup()
{

    for (int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin)
        pinMode(pin, OUTPUT);
}

void loop()
{
    for (int pin = FIRST_LED_PIN, ms;
         pin <= LAST_LED_PIN, ms = millis();
         pin = FIRST_LED_PIN + (ms / 120) % 10)
    {
        digitalWrite(pin, HIGH);
        delay(10);
        digitalWrite(pin, LOW);
    }
}
