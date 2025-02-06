#include <Arduino.h>
// 3. Подключите кнопки по схеме со стягивающим резистором и измените программу так, чтобы она продолжала работать.
#define BUZZER_PIN 13
#define FIRST_KEY_PIN 7
#define KEY_COUNT 3

unsigned char i = 0;

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    int keyPin = i + FIRST_KEY_PIN;

    bool isKeyDown = digitalRead(keyPin);

    if (isKeyDown)
    {
        int frequency = 3000 + i * 1000;

        tone(BUZZER_PIN, frequency, 20);
    }
    ++i %= KEY_COUNT;
}
