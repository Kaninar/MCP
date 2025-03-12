#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#define DIODE_DROP 0.7
//                адрес, колонок, строк
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();      // инициализирует дисплей с указанными в конструкторе параметрами
    lcd.backlight(); // включает подсветку
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
/*Чтобы управлять LCD необходимо подключить библиотеку, мы имеем I2C адаптер поэтому необходимо подключать `LiquidCrystal_I2C.h`.
Затем нужно инициализировать объект соответствующего типа. После инициализации можно выводить информацию на дисплей.
Вольтаж определяется в переменной `voltage`. Курсор устанавливается в первой колонке второй строки.
Если напряжение обнаружено, то нужно прибавить прямое падение.*/
// https://drive.google.com/file/d/1nIp2yWdf87u2qZGRYsa6mU-QgpAyx-ku/view?usp=drive_link