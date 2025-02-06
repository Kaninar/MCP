#include <Arduino.h>

#define DATA_PIN 13
#define LATCH_PIN 12
#define CLOCK_PIN 11
#define BUTTON_PIN 10

int clicks = 0;
bool buttonWasUp = true;
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
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

byte inverse(byte b) // функция для инверсии байта
{
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;

    return b;
}

void loop()
{
    if (buttonWasUp && !digitalRead(BUTTON_PIN))
    {
        delay(10);
        if (!digitalRead(BUTTON_PIN))
            clicks = (clicks + 1) % 10;
    }

    buttonWasUp = digitalRead(BUTTON_PIN);

    digitalWrite(LATCH_PIN, LOW);
    // bitOrder изменил на MSBFIRST(most significant bit first) — начиная со старшего
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, inverse(segments[clicks]));

    digitalWrite(LATCH_PIN, HIGH);
}
