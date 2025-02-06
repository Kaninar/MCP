#include <Arduino.h>

#define DATA_PIN 13
#define LATCH_PIN 12
#define CLOCK_PIN 11
#define LDR_PIN A0

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
    pinMode(LDR_PIN, INPUT);
}

void loop()
{
    int lightness = analogRead(LDR_PIN);

    int number = map(lightness, 0, 1023, 0, 9);

    digitalWrite(LATCH_PIN, LOW);

    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segments[number]);

    digitalWrite(LATCH_PIN, HIGH);
}
