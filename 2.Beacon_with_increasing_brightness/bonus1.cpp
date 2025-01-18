#include <Arduino.h>

#define LED_PIN = 2;

int volt = 0;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    analogWrite(LED_PIN, volt);
    delay(250);

    if (volt >= 255)
    {
        volt -= 51;
    }
    else
    {
        volt += 51;
    }
}
//TODO
