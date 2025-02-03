#include <Arduino.h>
// 1.Проверьте, попадает ли переданное число в диапазон значений, которые нужно передавать в analogWrite(). Передайте на компьютер сообщение об ошибке, если нет.
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
        char incomingChar = Serial.read();

        if (incomingChar >= '0' && incomingChar <= '9')
        {
            message += incomingChar;
        }
        else if (incomingChar == '\n')
        {
            analogWrite(LED_PIN, message.toInt());

            message = "";
        }
        else
        {
            Serial.println("Error");
        }
    }
}