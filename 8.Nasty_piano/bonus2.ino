#include <Arduino.h>
// 3. Подключите кнопки по схеме со стягивающим резистором и измените программу так, чтобы она продолжала работать.
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

        bool isKeyDown = digitalRead(keyPin);

        if (isKeyDown)
        {
            int frequency = 3000 + i * 1000;

            tone(BUZZER_PIN, frequency, 20);
        }
    }
}
