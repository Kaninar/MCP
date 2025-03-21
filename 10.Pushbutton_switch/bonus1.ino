#include <Arduino.h>

#define LED_PIN 13
const int BUTTON_PINS[2] = {3, 4};

bool wasAnyUp = true; // была ли поднята любая из кнопок
bool ledEnabled = false;

void setup()
{
    pinMode(LED_PIN, OUTPUT);

    pinMode(BUTTON_PINS[0], INPUT_PULLUP);
    pinMode(BUTTON_PINS[1], INPUT_PULLUP);
}

void loop()
{
    bool isAnyUp = digitalRead(BUTTON_PINS[0]) | // поднята любая из кнопок
                   digitalRead(BUTTON_PINS[1]);

    if (wasAnyUp && !isAnyUp)
    {
        delay(10);

        isAnyUp = digitalRead(BUTTON_PINS[0]) | // уточнение, что любая из кнопок поднята
                  digitalRead(BUTTON_PINS[1]);

        if (!isAnyUp) // если обе опущены
        {
            ledEnabled = !ledEnabled;
            digitalWrite(LED_PIN, ledEnabled);
        }
    }

    wasAnyUp = isAnyUp;
}
/*Вместо проверки одного пина происходит проверка двух, если хоть одна кнопка поднята, то ничего произойдёт. Чтобы событие произошло `isAnyUp` должно быть 0, а `wasAnyUp` 1.
 */
// https://drive.google.com/file/d/1sf_PtDK3uJsFRO2UwJe2zkH6uWJHijBA/view?usp=drive_link