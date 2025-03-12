#include <Arduino.h>

#include <LCD_1602_RUS.h>

#define DIODE_DROP 0.5

LCD_1602_RUS lcd(0x27, 16, 2);

unsigned char count = 0;

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.print("Время: ");
    lcd.setCursor(0, 1);
    lcd.print("Батарея: ");
}

void loop()
{
    // время
    unsigned long ms = millis();

    unsigned int seconds = ms * 0.001;
    unsigned int milliseconds = ms % 1000;

    String time = String(seconds) + ":" + String(milliseconds);

    // напряжение

    float voltage = analogRead(A0) * 0.009765625;

    if (voltage > 0.1)
        voltage += DIODE_DROP;

    if (millis() * 0.0001 > count)
    {
        Serial.print(time);
        Serial.print('\t');
        Serial.print(voltage);
        Serial.println(" V");

        count++;
    }
    // вывод на дисплей

    lcd.setCursor(7, 0);
    lcd.print(time);

    lcd.setCursor(9, 1);
    lcd.print(voltage, 2);
    lcd.print(" V");
}

/*Объединения скетча и первого самостоятельного задания и вывод инвормации в серийный порт каждые 10 секунд.
Была использована библиотека LCD_1602_RUS для вывода кирилицы на lcd дисплей*/
// https://drive.google.com/file/d/1AfRFqUMXnT27tl7lGHKSeFVk4P1En0ol/view?usp=drive_link