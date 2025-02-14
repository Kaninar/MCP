#include <Arduino.h>

#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7

byte segments[] = {
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
    int number = (millis() / 1000) % 10;
    int mask = numberSegments[number];

    for (int i = 0; i < SEGMENT_COUNT; ++i)
    {
        boolean enableSegment = bitRead(mask, i);

        digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    }
}
/*Масси байтов `segments` хранит маски для семисегментника. Считываем бит функцией`readBit()`, соответствующий текущему `i` сегменту.
Истина — он установлен (1), подать напряжение на пин, ложь — нет (0). Итерация происходит при помощи цикла `for`. Текущее число опеределяется целочисленным делением на 1000 (1 секунда)
и делением по модулю на 10 (количество возможных знаков).
*/
// https://drive.google.com/file/d/1qjv0JjkdrErsfoEaFEisu6_H0Q97Vurv/view?usp=drive_link