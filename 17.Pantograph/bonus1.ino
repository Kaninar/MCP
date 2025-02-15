#include <Arduino.h>

#include <Servo.h>

Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
    int lightness = analogRead(A0);
    int angle = map(lightness, 0, 1023, 180, 0);

    myServo.write(angle);
}
/*Вместо потаниометра мы принимаем значение с фоторезистрора. При помощи функции `map()` определяем необходимый угол. Чем темнее, тем больше угол и наоборот.*/
// https://drive.google.com/file/d/1q9hy2wv88vCGXhjNaXuIuq_w7BisJ-Gm/view?usp=drive_link