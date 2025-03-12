#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <math.h>

#define TERMIST_B 3900

#define VIN 5.0
#define TESTER_PIN A0
#define TEMP_PIN A1

#define DIODE_DROP 0.7

LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;

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

    // температура

    float tmp_voltage = analogRead(A1) * VIN * 0.0009765625;
    float r1 = tmp_voltage / (VIN - voltage);

    float temperature = 1. / (1. / (TERMIST_B)*log(r1) + 1. / (25. + 273.)) - 273;

    // вывод на дисплей

    lcd.setCursor(7, 0);
    lcd.print(time);

    lcd.setCursor(9, 1);
    lcd.print(voltage);
    lcd.print(" V");

    // вывод в серийный порт

    if (millis() / 10000 > count)
    {
        Serial.print(time);
        Serial.print('\t');
        Serial.print(voltage);
        Serial.print('\t');
        Serial.print(temperature);

        count++;
    }
}
/*За основу была влята задача для самоятоятельного решения №2, добавлена формула для расчёта температуры в цельсиях из эксперимента №16 и соответствующий вывод информации на дисплей и в последовательный порт.*/
// https://drive.google.com/file/d/1Al72yJoYzwrbFNILN8sbF5ksgagTsXPM/view?usp=drive_link