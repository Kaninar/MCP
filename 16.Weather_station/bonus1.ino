#include <Arduino.h>

#include <math.h>

#define TERMIST_B 3900

#define VIN 5.0

int minute = 1;

void setup()
{
    Serial.begin(9600);

    Serial.println("Minute\tSecond\tTemperature\t");
}

void loop()
{
    float voltage = analogRead(A0) * VIN / 1024.0;
    float r1 = voltage / (VIN - voltage);

    float temperature = 1. / (1. / (TERMIST_B)*log(r1) + 1. / (25. + 273.)) - 273;

    Serial.print(minute);
    Serial.print("\t");
    Serial.print(millis() / 1000); // дабавлен вывод секунд
    Serial.print("\t");
    Serial.println(temperature);

    delay(1000); // изменена задержка
    ++minute;
}
/*Была изменена задерка для вывода информации и добавлен столбец с выводом секунд.
Минутная задержка уменьшина для ускорения демонстрации работы программы.*/
// https://drive.google.com/file/d/1q9hy2wv88vCGXhjNaXuIuq_w7BisJ-Gm/view?usp=drive_link