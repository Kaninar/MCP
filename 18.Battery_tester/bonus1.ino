#include <Arduino.h>
#include <LCD_1602_RUS.h>

#define DIODE_DROP 0.7

LCD_1602_RUS lcd(0x27, 16, 2);

int count = 0;

void setup()
{
    lcd.init();
    // lcd.backlight();
    lcd.print("Время: ");
    lcd.setCursor(0, 1);
    lcd.print("Батарея: ");
}

void loop()
{
    // время
    unsigned long ms = millis();

    unsigned int seconds = ms / 1000;
    unsigned int milliseconds = ms % 1000;

    String time = String(seconds) + ":" + String(milliseconds);

    // напряжение

    float voltage = analogRead(A0) / 1024.0 * 10.0;

    if (voltage > 0.1)
        voltage += DIODE_DROP;

    // вывод на дисплей

    lcd.setCursor(7, 0);
    lcd.print(time);

    lcd.setCursor(9, 1);
    lcd.print(voltage, 2);
    lcd.print(" V");

    // вывод в серийный порт

    if (millis() / 10000 > count)
    {
        Serial.println();
        count++;
    }
}