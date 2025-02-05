#include <Arduino.h>
// 3.Дополните схему и программу таким образом, чтобы сегмент-точка включался при прохождении четных чисел и выключался на нечетных
#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 8

/*
     --a--
    |     |
    f     b
    |     |
     --g--
    |     |
    e     c
    |     |
     --d--   *DP

*/
// DP  gfedcba
byte numberSegments[10] = {
    0b10111111, // 0
    0b00000110, // 1
    0b11011011, // 2
    0b01001111, // 3
    0b11100110, // 4
    0b01101101, // 5
    0b11111101, // 6
    0b00000111, // 7
    0b11111111, // 8
    0b01101111, // 9
};

void setup()
{
    for (int i = 0; i < SEGMENT_COUNT; ++i)
        pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}

void loop()
{
    int number = (millis() / 1000) % 10;

    int mask = numberSegments[number];

    for (int i = 0; i < SEGMENT_COUNT; ++i)
    {
        bool enableSegment = bitRead(mask, i);

        digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    }
}
