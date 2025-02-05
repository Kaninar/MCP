#include <Arduino.h>

#define LED_PIN2 2
#define LED_PIN3 3
#define POD_PIN A0

void setup()
{
    pinMode(LED_PIN2, OUTPUT);
    pinMode(LED_PIN3, OUTPUT);
    pinMode(POD_PIN, INPUT);
}

void loop()
{
    int rotation;
    int LED1_brightness;
    int LED2_brightness;

    rotation = analogRead(POD_PIN);
    LED1_brightness = rotation / 4;
    LED2_brightness = LED1_brightness / 8;

    analogWrite(LED_PIN2, LED1_brightness);
    analogWrite(LED_PIN3, LED2_brightness);
}
