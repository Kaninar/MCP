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
/*При помощи целочисленного деления опеределяем количество секунд, а при помощи деления по модулю остаток миллисекунд.
Используея тип `String` созадём строку вида [секунды]:[миллисекунды]. Затем выводим это `str` на дисплей.
Была использована библиотека LCD_1602_RUS для вывода кирилицы на lcd дисплей*/
// https://drive.google.com/file/d/1pnMiCkv27U8d-0XlxGKAi8Ur0Xm9k5Jf/view?usp=drive_link