#include <Arduino.h>
// 1. Сделайте напряженный вариант игры: пусть интервал между сигналами будет в диапазоне от 10 до 15 секунд.
#define BUZZER_PIN 7
#define PLAYER_COUNT 2

int buttonPins[PLAYER_COUNT] = {2, 11};
int ledPins[PLAYER_COUNT] = {8, 13};

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    for (int player = 0; player < PLAYER_COUNT; ++player)
    {
        pinMode(ledPins[player], OUTPUT);
        pinMode(buttonPins[player], INPUT_PULLUP);
    }
}

void loop()
{
    delay(random(10000, 15000));
    tone(BUZZER_PIN, 3000, 250);

    for (int player = 0;; player = (player + 1) % PLAYER_COUNT)
    {
        if (!digitalRead(buttonPins[player]))
        {
            digitalWrite(ledPins[player], HIGH);
            tone(BUZZER_PIN, 4000, 1000);
            delay(1000);
            digitalWrite(ledPins[player], LOW);
            break;
        }
    }
}