#include <Arduino.h>

#include <Servo.h>

Servo myServo;

const unsigned char angles[]{45, 135, 87, 0, 65, 90, 180, 150}; // создан массив

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int val = analogRead(A0);
    int index = int((val / 1023.0) * 7);

    myServo.write(angles[index]);
}
/*Был добавлен массив углов `angels`. При помощи аналогичной формулы, как в скетче, опередяется индекс, для сервопривода*/
// https://drive.google.com/file/d/1uv0emf_IOBFAr75kJuOdD-2QabFoe0eg/view?usp=drive_link