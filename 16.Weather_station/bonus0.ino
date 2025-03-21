#include <Arduino.h>

#include <math.h>

#define TERMIST_B 3900

#define VIN 5.0

int minute = 1;

void setup()
{
    Serial.begin(9600);

    Serial.println("Metiostation"); // добавлена эта строчка
    Serial.println("Minute\tTemperature");
}

void loop()
{
    float voltage = analogRead(A0) * VIN / 1024.0;
    float r1 = voltage / (VIN - voltage);

    float temperature = 1. / (1. / (TERMIST_B)*log(r1) + 1. / (25. + 273.)) - 273;

    Serial.print(minute);
    Serial.print("\t");
    Serial.println(temperature);

    delay(1000);
    ++minute;
}
/*Добавлена строчка вывода сообщения "Meteostation" перед заголовками таблицы.
Задержка для для вывода информации уменьшена для ускорения демонстрации процесса.*/
// https://drive.google.com/file/d/1mKQvH3YoEogMyZLeIWWAAS8Zmqi-NtBn/view?usp=drive_link