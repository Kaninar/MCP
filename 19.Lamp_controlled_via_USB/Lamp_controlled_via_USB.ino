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
    }
}
/*'Serial.available()' позволяет проерить если записи в буффере, если так, то поисходит чтение и запиcываем аналоговое значение.
Значения считываются по символу за итерацию и сохраняется в переменной 'message', если это значение от 0 до 9. Если был нажат 'Enter', то значения записываются на аналоговый порт и сообщение обнуляется.*/
// https://drive.google.com/file/d/1H9GT8FGnB4ZvF0E5ZxFy9SF_T3tKAo8e/view?usp=drive_link