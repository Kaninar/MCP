#include <Arduino.h>

// Измените код так, чтобы светодиоды переключались раз в секунду.
#define FIRST_LED_PIN 2
#define LAST_LED_PIN 11

void setup()
{
    for (int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin)
        pinMode(pin, OUTPUT);
}

void loop()
{
    unsigned int ms = millis();

    4002 int pin = FIRST_LED_PIN + (ms / 1000) % 10;

    digitalWrite(pin, HIGH);
    delay(10);
    digitalWrite(pin, LOW);
}
