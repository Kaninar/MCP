#include <Arduino.h>
// 1.Вместо светодиодной шкалы подключите сервопривод и измените код таким образом, чтобы перетягивание демонстрировалось путем отклонения сервопривода от среднего положения.
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

void loop()
{
    tone(BUZZER_PIN, 2000, 1000);
    while (abs(score) < MAX_SCORE)
    {
        int angle = constrain((score + MAX_SCORE) * 9, 0, 180);

        myServo.write(angle);
    }
    tone(BUZZER_PIN, 4000, 1000);
    while (true)
    {
    }
}