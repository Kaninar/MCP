#include <Arduino.h>
// 1. Измените код так, чтобы светодиод переключался только после отпускания кнопки.
#define BUTTON_PIN 3
#define LED_PIN 13

bool buttonWasUp = true;
bool ledEnabled = false;

void setup()
{
    Serial.begin(4400);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    bool buttonIsUp = digitalRead(BUTTON_PIN);

    if (!buttonWasUp && buttonIsUp) // была ли кнопка нажата и подята ли она сейчас
    {
        delay(10);

        buttonIsUp = digitalRead(BUTTON_PIN); // действительно ли поднята сейчас

        if (buttonIsUp)
        {
            ledEnabled = !ledEnabled;
            digitalWrite(LED_PIN, ledEnabled);
        }
    }

    buttonWasUp = buttonIsUp;
}
