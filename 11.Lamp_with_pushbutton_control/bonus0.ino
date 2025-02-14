#include <Arduino.h>

#define PLUS_BUTTON_PIN 2
#define MINUS_BUTTON_PIN 3
#define LED_PIN 9

int brightness = 100;
bool plusUp = true;
bool minusUp = true;

bool handleClick(int buttonPin, boolean wasUp) // убран параметр delta
{
    bool isUp = digitalRead(buttonPin);

    if (wasUp && !isUp)
    {
        delay(10);
        isUp = digitalRead(buttonPin);

        if (!isUp)
        {
            int delta = buttonPin == PLUS_BUTTON_PIN ? 35 : -35; // добавлено условие с определением текущего пина

            brightness = constrain(brightness + delta, 0, 255);
        }
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
/*В функции `handleClick()` параметр `delta` был убран, для определения шага яркости используется условие со сравнением текущего пина.
 */
// https://drive.google.com/file/d/1su4ACf-1ts_LFLugkRU7xlmVvWSnGm6u/view?usp=drive_link