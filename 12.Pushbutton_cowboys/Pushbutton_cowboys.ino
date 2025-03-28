#include <Arduino.h>

#define BUZZER_PIN 12
#define PLAYER_COUNT 2

int buttonPins[PLAYER_COUNT] = {3, 13};
int ledPins[PLAYER_COUNT] = {9, 11};

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
    delay(random(2000, 7000));
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
/*В начале кадой итерации `loop()`(раунда) начинается задержка в промежутки от 2 до 7 секунд, после чего звучит сигнал "пли!". После чего начинается проверка каждого пина на нажатие.
Если кнопка нажата, то загарается соответсвующий диод игрока и горит одну секунду, после чего бесконечный цикл for прерывается и начинается новый раунд.
*/
// https://drive.google.com/file/d/1rSwUJbL6AVbz3qesBWpLXf5f7DspiWEG/view?usp=drive_link