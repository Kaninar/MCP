#include <Arduino.h>
// 2. Добавьте еще 2 кнопки и измените программу так, чтобы можно было извлечь 5 различных нот.

#define BUZZER_PIN 13
#define FIRST_KEY_PIN 7
#define KEY_COUNT 5

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    for (int i = 0; i < KEY_COUNT; ++i)
    {
        int keyPin = i + FIRST_KEY_PIN;

        bool keyUp = digitalRead(keyPin);

        if (!keyUp)
        {
            int frequency = 2500 + i * 500;

            tone(BUZZER_PIN, frequency, 20);
        }
    }
}