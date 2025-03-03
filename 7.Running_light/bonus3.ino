#include <Arduino.h>
// 4. Не меняя местами провода, измените программу так, чтобы огонёк бегал в обратном направлении.
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

    int pin = LAST_LED_PIN - (ms / 120) % 10;

    digitalWrite(pin, HIGH);
    delay(10);
    digitalWrite(pin, LOW);
}
