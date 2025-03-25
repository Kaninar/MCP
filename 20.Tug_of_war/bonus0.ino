#include <Arduino.h>

#include <Servo.h>

#define BUZZER_PIN 0
#define MAX_SCORE 10
#define BAR_COUNT 10
#define SERVO_PIN 9

Servo myServo;

volatile int score = 0;

void pushP1()
{
    ++score;
}
void pushP2()
{
    --score;
}

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    myServo.attach(9);
    attachInterrupt(INT1, pushP1, FALLING);
    attachInterrupt(INT0, pushP2, FALLING);
}

bool isStart = true;

void loop()
{
    if (isStart)
    {
        tone(BUZZER_PIN, 2000, 1000);
        isStart = false;
    }

    if (abs(score) < MAX_SCORE)
    {
        int angle = constrain((score + MAX_SCORE) * 9, 0, 180);

        myServo.write(angle);
    }
    else
    {
        tone(BUZZER_PIN, 4000, 1000);

        while (true)
        {
        }
    }
}
/*Серво привод подключен к пину 9. Цикл 'while' бы заменён на условное выражение. Флаг 'isStart' определяет должен ли звинеть стартовый писк, вычисляется угол поворота для сервопривода, после чего записывается.*/
// https://drive.google.com/file/d/1I4Nfj-HM9D9Dln3oJZxehv_u4bk8o7y3/view?usp=drive_link