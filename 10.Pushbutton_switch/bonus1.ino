#include <Arduino.h>
// 2. Добавьте в схему еще одну кнопку и доработайте код, чтобы светодиод зажигался только при нажатии обеих кнопок.
#define LED_PIN 13
const int BUTTON_PINS[2] = {3, 4};

bool wasAnyUp = true;
bool ledEnabled = false;

void setup()
{
    pinMode(LED_PIN, OUTPUT);

    pinMode(BUTTON_PINS[0], INPUT_PULLUP);
    pinMode(BUTTON_PINS[1], INPUT_PULLUP);
}

void loop()
{
    bool isAnyUp = digitalRead(BUTTON_PINS[0]) |
                   digitalRead(BUTTON_PINS[1]);

    if (wasAnyUp && !isAnyUp)
    {
        delay(10);

        isAnyUp = digitalRead(BUTTON_PINS[0]) |
                  digitalRead(BUTTON_PINS[1]);

        if (!isAnyUp)
        {
            ledEnabled = !ledEnabled;
            digitalWrite(LED_PIN, ledEnabled);
        }
    }

    wasAnyUp = isAnyUp;
}