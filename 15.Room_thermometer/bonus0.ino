#include <Arduino.h>

#include <math.h>

#define FIRST_LED_PIN 2
#define LED_COUNT 10

#define TERMIST_B 3950

#define VIN 5.0

void setup()
{
    for (int i = 0; i < LED_COUNT; ++i)
        pinMode(i + FIRST_LED_PIN, OUTPUT);
}

void loop()
{
    float voltage = analogRead(A0) * VIN / 1023.0;
    float r1 = voltage / (VIN - voltage);

    float temperature = 1. / (1. / (TERMIST_B)*log(r1) + 1. / (25. + 273.)) - 273;

    for (int i = 0; i < LED_COUNT; ++i)
    {
        bool enableSegment = (temperature >= i * 5); // одно деление равно 5 теперь
        digitalWrite(i + FIRST_LED_PIN, enableSegment);
    }
}
