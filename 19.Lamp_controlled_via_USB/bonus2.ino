#include <Arduino.h>

#define LED_PIN 9

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available())
    {
        char incomingChar = Serial.read();

        analogWrite(LED_PIN, incomingChar);
    }
}

/*'Serial.available()' позволяет проерить если записи в буффере, если так, то поисходит чтение и запиcываем аналоговое значение.
Яркость задаётся значениями от 0 до 255, что совпадает с типо данных 'char'.*/
// https://drive.google.com/file/d/1obmGx3CWOxcdIyd_xMgq2g2sViQtPE-R/view?usp=drive_link