#include <Arduino.h>
#include <map>
#include <string>

#define BUZZER_PIN 3
#define LDR_PIN A0

int dot = 250;                     // mc                //точка = ( <=250 мс )
int dash = dot * 3;                // тире = 3 точки
int pauseBetweenElements = dot;    // пауза между элементами одного знака = 1 точка
int pauseBetweenLetters = dot * 3; // пауза между буквами в слове = 3 точки
int pauseBetweenWords = dot * 7;   // пауза между словами = 7 точек

char[] message = "SOS";
std::map<char, string> morse{
    {'S', "---"},
    {'O', "..."}};

// TODO
void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    int val, frequency;

    val = analogRead(LDR_PIN);
    frequency = map(val, 0, 1023, 3500, 4500);

    tone(BUZZER_PIN, frequency, 20);
}
//TODO
