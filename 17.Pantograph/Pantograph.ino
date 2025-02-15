#include <Arduino.h>

#include <Servo.h>

#define POT_MAX_ANGLE 270.0

Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int val = analogRead(A0);
    int angle = int(val / 1024.0 * POT_MAX_ANGLE);

    myServo.write(angle);
}
/*Подключаем библиотеку для управления сервоприводом `Servo.h`, затем явно создаём объект типа Servo. Чтобы подключить пин используется функция `attach()`.
Высчитываем угол для сервопривода (180°), при том, что максимальный угол потанциометра - 270° и задаём угол при помощи функции `write()`*/
// https://drive.google.com/file/d/1qIUIxggRfEGyDiqj-gE6pYWjAEpNnKMj/view?usp=drive_link