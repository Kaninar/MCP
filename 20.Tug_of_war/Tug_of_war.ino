#include <Arduino.h>

#define BUZZER_PIN 0
#define FIRST_BAR_PIN 4
#define BAR_COUNT 10
#define MAX_SCORE 20

volatile int score = 0;

void pushP1() { ++score; }
void pushP2() { --score; }

void setup()
{
    for (int i = 0; i < BAR_COUNT; ++i)
        pinMode(i + FIRST_BAR_PIN, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);

    attachInterrupt(INT1, pushP1, FALLING);
    attachInterrupt(INT0, pushP2, FALLING);
}

void loop()
{
    tone(BUZZER_PIN, 2000, 1000);

    while (abs(score) < MAX_SCORE)
    {
        int bound = map(score, -MAX_SCORE, MAX_SCORE, 0, BAR_COUNT);
        int left = min(bound, BAR_COUNT / 2 - 1);
        int right = max(bound, BAR_COUNT / 2);
        for (int i = 0; i < BAR_COUNT; ++i)
            digitalWrite(i + FIRST_BAR_PIN, i >= left && i <= right);
    }
    tone(BUZZER_PIN, 4000, 1000);
    while (true)
    {
    }
}
/*При помощи цикла устанавливается выход на каждый пин шкалы, также на пищалку. Затем устанавливаем функции изменения счета на прерывания в режиме FALLING(из HIGH в LOW).
На старте и по завершению игры звучит писк. При помощи цикла 'while' происходит проверка достигли один из игроков максимального счета.
Если нет, то определяется длина линии на шкале относительно текущего счета.*/
// https://drive.google.com/file/d/1q0ANCVC3a8ppsiS2IzLVBCJ6pdcwJYZg/view?usp=drive_link