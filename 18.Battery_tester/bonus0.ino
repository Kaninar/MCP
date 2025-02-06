#include <Arduino.h>

#include <LCD_1602_RUS.h> //библиотека для вывода текста на кириллице

LCD_1602_RUS lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.print("Секундомер");
}

void loop()
{
    unsigned long ms = millis();

    unsigned int seconds = ms / 1000;
    unsigned int milliseconds = ms % 1000;

    String str = String(seconds) + ":" + String(milliseconds);

    lcd.setCursor(0, 1);
    lcd.print(str);
}