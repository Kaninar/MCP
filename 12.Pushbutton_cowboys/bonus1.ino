#include <Arduino.h>

#define BUZZER_PIN 7
const unsigned char BUTTON_PINS[] = {2, 11};
const unsigned char LED_PINS[] = {8, 13};
#define PLAYER_COUNT 2

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);

    for (char player = 0; player < PLAYER_COUNT; ++player)
    {
        pinMode(LED_PINS[player], OUTPUT);
        pinMode(BUTTON_PINS[player], INPUT_PULLUP);
    }
}

void loop()
{
    delay(random(2000, 7000));

    bool wasUp[] = {digitalRead(BUTTON_PINS[0]), // подняты ли кнопки до сигнала
                    digitalRead(BUTTON_PINS[1])};

    tone(BUZZER_PIN, 500, 250);

    for (char player = 0;; player = (player + 1) % PLAYER_COUNT)
    {
        bool isUp = digitalRead(BUTTON_PINS[player]); // проверка состояния i-ой кнопки

        if (!wasUp[player] & isUp) // проверка на жульничество
            wasUp[player] = true;

        if (!isUp && wasUp[player])
        {
            digitalWrite(LED_PINS[player], HIGH);
            tone(BUZZER_PIN, 4000, 1000);
            delay(1000);
            digitalWrite(LED_PINS[player], LOW);

            break;
        }
    }
}
