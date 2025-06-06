#include <Arduino.h>

#define BUZZER_PIN 3
#define LDR_PIN A0

int dot = 250;
int dash = dot * 3;
int pauseBetweenWords = dot * 7;

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

int pauses[] = {dot, dot, dot, dash, dash, dash, dot, dot, dot};
int counter = 0;

void loop()
{
    int val, frequency;

    val = analogRead(LDR_PIN);
    frequency = map(val, 0, 1023, 2500, 2500);
    tone(BUZZER_PIN, frequency, pauses[counter]);
    if (counter == 9)
    {
        delay(pauses[counter++] + pauseBetweenWords);
    }
    delay(pauses[counter++] + dot);
    counter %= 9;
}