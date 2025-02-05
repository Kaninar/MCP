#include <Arduino.h>
// 2. Не выключая порты, сделайте так, чтобы огонёк бежал только по средним четырем делениям шкалы.

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

    int offet = 3;
    int count = 4;
    int pin = FIRST_LED_PIN + offet + (ms / 120) % count;

    digitalWrite(pin, HIGH);
    delay(10);
    digitalWrite(pin, LOW);
}