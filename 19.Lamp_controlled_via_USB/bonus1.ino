#include <Arduino.h>
// 2.Переделайте программу так, чтобы устройство распознавало текстовые команды,
// например, «on» и «off», и соответственно включало и выключало светодиод.
// Вам может пригодиться один из методов String : toLowerCase(yourString) или toUpperCase(yourString),
// которые возвращают переданную строку yourString, приведенную к нижнему или верхнему регистру соответственно.
#define LED_PIN 9

String message;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available())
    {
        String incomingMessage = Serial.readString();
        incomingMessage.toLowerCase();

        if (incomingMessage == "on")
        {
            analogWrite(LED_PIN, 255);
        }
        else if (incomingMessage == "off")
        {
            analogWrite(LED_PIN, 0);
        }
        else
        {
            Serial.println("Error");
        }
    }
}