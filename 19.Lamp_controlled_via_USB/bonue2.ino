#include <Arduino.h>

#define LED_PIN 9

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available())
    {
        char incomingChar = Serial.read();

        analogWrite(LED_PIN, incomingChar);
    }
}

/*При помощи цикла 'while' происходит проверка на чтение и самое чтение значения с последовательного порта и запись на аналоговый порт.
Яркость задаётся значениями от 0 до 255, что совпадает с типо данных 'char'.*/
//