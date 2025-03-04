#include <Arduino.h>

#include <math.h>

#define FIRST_LED_PIN 2
#define LED_COUNT 10
#define BUZZ_PIN 13

#define TERMIST_B 4300

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
        bool enableSegment = (temperature >= i * 5);
        digitalWrite(i + FIRST_LED_PIN, enableSegment);
    }
    // условие для писка
    if (temperature >= 25)
        tone(BUZZ_PIN, 1500, 100);
}
/*Добавлено условие для сигнала, где температура должна быть больше 25 градусов.*/
// https://drive.google.com/file/d/1qYLf5ibKOUPrNWLXxoloEL7RGGpHPyfp/view?usp=drive_link