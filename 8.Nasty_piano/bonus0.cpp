#include <Arduino.h>
// Сделайте так, чтобы наше пианино звучало в диапазоне от 2 кГц до 5 кГц.
#define BUZZER_PIN 13
#define FIRST_KEY_PIN 7
#define KEY_COUNT 3

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    for (int i = 0; i < KEY_COUNT; ++i)
    {
        int keyPin = i + FIRST_KEY_PIN;

        boolean keyUp = digitalRead(keyPin);

        if (!keyUp)
        {
            int frequency = 2000 + i * 1500;

            tone(BUZZER_PIN, frequency, 20);
        }
    }
}
