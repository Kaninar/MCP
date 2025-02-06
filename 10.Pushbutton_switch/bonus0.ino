#include <Arduino.h>

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

    if (!buttonWasUp && buttonIsUp) // БЫЛА ли кнопка нажата и подята ли она СЕЙЧАС
    {
        delay(10);

        buttonIsUp = digitalRead(BUTTON_PIN); // действительно ли поднята СЕЙЧАС

        if (buttonIsUp)
        {
            ledEnabled = !ledEnabled;
            digitalWrite(LED_PIN, ledEnabled);
        }
    }

    buttonWasUp = buttonIsUp;
}
