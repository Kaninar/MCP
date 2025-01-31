#include <Arduino.h>
// 1. Измените код, чтобы индикатор отсчитывал десятые секунды.

byte numberSegments[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
};

void setup()
{
    for (int i = 0; i < SEGMENT_COUNT; ++i)
        pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}

void loop()
{
    int number = (millis() / 10000) % 10;

    int mask = numberSegments[number];

    for (int i = 0; i < SEGMENT_COUNT; ++i)
    {
        bool enableSegment = bitRead(mask, i);

        digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    }
}