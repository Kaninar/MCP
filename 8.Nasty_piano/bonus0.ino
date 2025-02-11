#include <Arduino.h>

#define BUZZER_PIN 13
#define FIRST_KEY_PIN 7
#define KEY_COUNT 3

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

unsigned char i = 0;

void loop()
{

    int keyPin = i + FIRST_KEY_PIN;

    bool keyUp = digitalRead(keyPin);

    if (!keyUp)
    {
        int frequency = 2000 + i * 1500;

        tone(BUZZER_PIN, frequency, 20);
    }

    ++i %= KEY_COUNT;
}
