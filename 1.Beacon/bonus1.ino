#include <Arduino.h>

#define LED_PIN = 2;

bool isFirstRun = true;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);

    if (isFirstRun)
    {
        delay(3000);
        isFirstRun = false;
    }
    else
    {
        delay(100);
    }

    digitalWrite(LED_PIN, LOW);
    delay(900);
}
