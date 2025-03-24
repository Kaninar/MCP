#include <Arduino.h>

#define LED_PIN 9

String message;

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

        if (incomingChar >= '0' && incomingChar <= '9')
        {
            message += incomingChar;
        }
        else if (incomingChar == '\n')
        {
            int value = message.toInt();

            if (value < 0 || value > 255)
            {
                Serial.println("Error");
            }
            else
            {
                analogWrite(LED_PIN, value);
            }

            message = "";
        }
    }
}

/*Код идентичен тому, что был в скетче, но добавлена проверка на соответствие значений и вывода сообщения об ошибке.*/
// https://drive.google.com/file/d/1H1HS7bvgHyU9dt4AcfHSZHuwLHzyjRzD/view?usp=drive_link