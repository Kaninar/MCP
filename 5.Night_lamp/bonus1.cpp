#include <Arduino.h>

#define RED_LED_PIN 12
#define GREEN_LED_PIN 13
#define LDR_PIN A0
#define POT_PIN A1

long states[2] = {};

long getState(int lightness, int threshold);

void setup()
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop()
{
    int lightness = analogRead(LDR_PIN);
    int threshold = analogRead(POT_PIN);

    states[0] = getState(lightness, threshold);
    states[1] = getState(lightness, threshold / 2);

    digitalWrite(RED_LED_PIN, states[0]);
    digitalWrite(GREEN_LED_PIN, states[1]);
}

long getState(int lightness, int threshold)
{
    if (lightness < threshold)
    {
        return HIGH;
    }

    return LOW;
}
