#include <Arduino.h>

#define BUZZER_PIN 8
const unsigned char BUTTON_PINS[] = {3, 5, 11, 13}; // добалено по два пина
const unsigned char LED_PINS[] = {2, 4, 10, 12};
#define PLAYER_COUNT 4

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

    bool wasUp[PLAYER_COUNT];

    for (char player = 0; player < PLAYER_COUNT; player++)
    {
        wasUp[player] = digitalRead(BUTTON_PINS[player]);
    }

    tone(BUZZER_PIN, 500, 250);

    for (char player = 0;; player = (player + 1) % PLAYER_COUNT)
    {
        bool isUp = digitalRead(BUTTON_PINS[player]);

        if (!wasUp[player] & isUp)
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