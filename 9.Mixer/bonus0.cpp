#include <Arduino.h>
// 1. Внесите единственное изменение в программу, после которого максимальной скоростью вращения мотора составит половину от возможной.
#define MOTOR_PIN 9
#define FIRST_BUTTON_PIN 5
#define BUTTON_COUNT 3
#define SPEED_STEP (255 / 2 / (BUTTON_COUNT - 1))

void setup()
{
    pinMode(MOTOR_PIN, OUTPUT);

    for (int i = 0; i < BUTTON_COUNT; ++i)
        pinMode(i + FIRST_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    for (int i = 0; i < BUTTON_COUNT; ++i)
    {
        if (digitalRead(i + FIRST_BUTTON_PIN))
            continue;
        /*
            Любое значение speed > 0 будет меньше в 2 раза.

            Список значений согласно i:
            - 0 -> 0;
            - 1 -> 64;
            - 2 -> 127.
        */

        int speed = i * SPEED_STEP;

        analogWrite(MOTOR_PIN, speed);
    }
}
