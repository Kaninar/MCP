#include <Arduino.h>

#define BUTTON_PIN 3
#define LED_PIN 13

bool buttonWasUp = true;
bool ledEnabled = false;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    bool buttonIsUp = digitalRead(BUTTON_PIN);

    if (buttonWasUp && !buttonIsUp)
    {
        delay(10);

        buttonIsUp = digitalRead(BUTTON_PIN);
        if (!buttonIsUp)
        {
            ledEnabled = !ledEnabled;
            digitalWrite(LED_PIN, ledEnabled);
        }
    }

    buttonWasUp = buttonIsUp;
}
/*
Кнопка подключена к пину с потдягивающим резистром. Переменная `buttonIsUp` определяет поднята ли кнопка данный момент или нажата, а переменная `buttonWasUp` хранит прошлое состояние,
т.е. изначально кнопка считается поднятой. Если кнопка была поднята и сейчас она опущена, то считается, что произошло нажатие, но для проверки на дребез происходит небольшая задержка
и повторная проверка текущего состояния. Если кнопка действительно опущена прямо сейчас, то состояние `ledEnabled` меняется на обратное (0 - `LOW` - диод отключен, 1 - `HIGH` - диод включен).
*/
// https://drive.google.com/file/d/1silUEB3Qiyj1n3pdTMRmD7IUaAdU4VOb/view?usp=drive_link