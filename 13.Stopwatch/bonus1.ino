#include <Arduino.h>

#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7

byte numberSegments[10] = {
    0b01110111, // A    //отключен сектор d и ключен g
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
    int number = (millis() / 1000) % 10;

    int mask = numberSegments[number];

    for (int i = 0; i < SEGMENT_COUNT; ++i)
    {
        bool enableSegment = bitRead(mask, i);

        digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    }
}
/*Изменена маска для первого знака нижний сегмент (d) отключен и включен средний сегмент (g)*/
// https://drive.google.com/file/d/1r8o0SdLdtkMYGiyKFKV97nKClXEWA3ew/view?usp=drive_link