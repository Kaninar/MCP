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

/*Вместо ознакового чтения происходит чтение строки из буффера. On - включение максимальной яркости, off - отключение, иначе вывод сообщения об ошибке.*/
// https://drive.google.com/file/d/1H0I_6_as6TOgrrDYfuArNgecnsJPcuya/view?usp=drive_link