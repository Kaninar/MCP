#include <Arduino.h>

#define BUZZER_PIN 12
#define PLAYER_COUNT 2

const unsigned char BUTTON_PINS[PLAYER_COUNT] = {3, 13};
const unsigned char LED_PINS[PLAYER_COUNT] = {9, 11};

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    for (int player = 0; player < PLAYER_COUNT; ++player)
    {
        pinMode(LED_PINS[player], OUTPUT);
        pinMode(BUTTON_PINS[player], INPUT_PULLUP);
    }
}

void loop()
{
    delay(random(10000, 15000)); // изменён интервал значений, от 10 до 15 сек

    tone(BUZZER_PIN, 3000, 250);

    for (int player = 0;; player = (player + 1) % PLAYER_COUNT)
    {
        if (!digitalRead(BUTTON_PINS[player]))
        {
            digitalWrite(LED_PINS[player], HIGH);
            tone(BUZZER_PIN, 4000, 1000);
            delay(1000);
            digitalWrite(LED_PINS[player], LOW);

            break;
        }
    }
}
/*Изменён интервал для случайной дительности задержки перед сигналом на [10:15] секунд.*/
// https://drive.google.com/file/d/1ut251iv-9cC4uEmZFwMjXyWLjMWBs2GR/view?usp=drive_link