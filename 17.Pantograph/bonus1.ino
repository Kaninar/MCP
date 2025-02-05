#include <Arduino.h>
// 2. Предположим, что сервопривод управляет шторкой, и нам нужно поддерживать постоянное количество света в помещении. Создайте такой механизм.

#include <Servo.h>

#define POT_MAX_ANGLE 270.0 // макс. угол поворота потенциометра
Servo myServo;

void setup()
{

    myServo.attach(9);
}

void loop()
{
    int val = analogRead(A0);
    int angle = map(val, 1023, 0, 0, 180);

    myServo.write(angle);
}