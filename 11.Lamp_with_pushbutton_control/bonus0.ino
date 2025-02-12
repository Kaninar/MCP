#include <Arduino.h>

#define PLUS_BUTTON_PIN 2
#define MINUS_BUTTON_PIN 3
#define LED_PIN 9

int brightness = 100;
bool plusUp = true;
bool minusUp = true;

bool handleClick(int buttonPin, boolean wasUp)
{
    bool isUp = digitalRead(buttonPin);

    if (wasUp && !isUp)
    {
        delay(10);
        isUp = digitalRead(buttonPin);

        int delta = buttonPin == PLUS_BUTTON_PIN ? 35 : -35;

        if (!isUp)
            brightness = constrain(brightness + delta, 0, 255);
    }

    return isUp;
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(PLUS_BUTTON_PIN, INPUT_PULLUP);
    pinMode(MINUS_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    analogWrite(LED_PIN, brightness);

    plusUp = handleClick(PLUS_BUTTON_PIN, plusUp);
    minusUp = handleClick(MINUS_BUTTON_PIN, minusUp);
}