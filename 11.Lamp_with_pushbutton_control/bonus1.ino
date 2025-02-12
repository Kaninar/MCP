#include <Arduino.h>

#define PLUS_BUTTON_PIN 2
#define MINUS_BUTTON_PIN 3
#define LED_PIN 9

const int BUTTONS[2] = {PLUS_BUTTON_PIN, MINUS_BUTTON_PIN};

int brightness = 100;
bool plusUp = true;
bool minusUp = true;
bool wasUp[2] = {true, true};

int getBrightness(int buttonPin)
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
    analogWrite(LED_PIN, getBrightness());
}
