#include <Arduino.h>

#define LED_PIN 11
#define LDR_PIN A2
#define POT_PIN A4

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    int lightness = analogRead(LDR_PIN);
    int threshold = analogRead(POT_PIN);

    if (lightness < threshold)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
    delay(1000);
}
