#include <Arduino.h>
// 3. Добавьте в схему еще одну кнопку, чтобы у миксера стало три режима. Понадобилось ли изменять что-либо в программе?
#define MOTOR_PIN 9
#define FIRST_BUTTON_PIN 5
#define BUTTON_COUNT 4 // единственная необходимость - заменить константу количества кнопок с 3 на 4
#define SPEED_STEP (255 / (BUTTON_COUNT - 1))

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

        int speed = i * SPEED_STEP;

        analogWrite(MOTOR_PIN, speed);
    }
}
