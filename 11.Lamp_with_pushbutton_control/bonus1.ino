#include <Arduino.h>

#define PLUS_BUTTON_PIN 2
#define MINUS_BUTTON_PIN 3
#define LED_PIN 9

const int BUTTONS[2] = {PLUS_BUTTON_PIN, MINUS_BUTTON_PIN};

int brightness = 100;
bool wasUp[2] = {true, true};

int getBrightness()
{
    if (!wasUp[0])
        brightness += 35;

    if (!wasUp[1])
        brightness -= 35;

    brightness = constrain(brightness, 0, 255);

    return brightness;
}

void handleClick()
{
    for (int pin = 0; pin < 2; pin++)
    {
        bool isUp = digitalRead(BUTTONS[pin]);

        delay(10);
        isUp = digitalRead(BUTTONS[pin]);

        wasUp[pin] = isUp;
    }
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(PLUS_BUTTON_PIN, INPUT_PULLUP);
    pinMode(MINUS_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    analogWrite(LED_PIN, getBrightness()); // функция возвращает значение яркости прямо в функцию analogWrite()

    handleClick();
}
/*
Опеределение текущего состояник кнопок происходит в функции `handleClick`. Расчёт яркости происходит отдельно в функции `getBrightness` из записанного состояния кнопок в массиве `wasUp`.
*/
// https://drive.google.com/file/d/1sqKIU250QPInDy3OGYQ9eiJZod9uH4ji/view?usp=drive_link