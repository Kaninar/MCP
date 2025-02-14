#include <Arduino.h>

#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 8

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
/*Для демонстраци чётных числе можно включить последний бит в массиве масок для каждого чётного числа, либо путем деление переменной `number` на 2 по модулю и побитными операциеями включать послединй бит динамически*/
// https://drive.google.com/file/d/1rKNByMGZBpE3jGUwoaFQTUwh-MV_jofg/view?usp=drive_link