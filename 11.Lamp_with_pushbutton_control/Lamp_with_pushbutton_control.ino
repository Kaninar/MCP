#include <Arduino.h>

#define PLUS_BUTTON_PIN 2
#define MINUS_BUTTON_PIN 3
#define LED_PIN 9

int brightness = 100;
bool plusUp = true;
bool minusUp = true;

bool handleClick(int buttonPin, boolean wasUp, int delta)
{
    bool isUp = digitalRead(buttonPin);
    if (wasUp && !isUp)
    {
        delay(10);
        isUp = digitalRead(buttonPin);

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

    plusUp = handleClick(PLUS_BUTTON_PIN, plusUp, +35);
    minusUp = handleClick(MINUS_BUTTON_PIN, minusUp, -35);
}
/* Кнопки подключены к пинам с стягивающим резистором. Функция `handleCick()` проверяет нажат ли любой из пинов, если нажата,
то значение `brightness` изменяется на `delta` согласно указанному значению. Новое значение `brightness` будет выведено при следующей итерации `loop()`
*/
// https://drive.google.com/file/d/1t265Z6a1Qa7KaxkH0kXKWjqhivgB_U_2/view?usp=drive_link