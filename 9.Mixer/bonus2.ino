#include <Arduino.h>
#define MOTOR_PIN 9
#define FIRST_BUTTON_PIN 5
#define BUTTON_COUNT 4 // изменить кол-во кнопок с 3 на 4
#define SPEED_STEP (255 / (BUTTON_COUNT - 1))

unsigned int i = 0;

void setup()
{
    pinMode(MOTOR_PIN, OUTPUT);

    for (int pin = 0; pin < BUTTON_COUNT; ++pin)
        pinMode(pin + FIRST_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{

    if (digitalRead(i + FIRST_BUTTON_PIN))
        continue;

    int speed = i * SPEED_STEP;

    analogWrite(MOTOR_PIN, speed);

    ++i %= BUTTON_COUNT;
}
