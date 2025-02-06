#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define DIODE_DROP 0.7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.print("Battery voltage:");
}

void loop()
{
    float voltage = analogRead(A0) / 1024.0 * 10.0;

    if (voltage > 0.1)
        voltage += DIODE_DROP;

    lcd.setCursor(0, 1);

    lcd.print(voltage, 2);
    lcd.print(" Volts");
}
