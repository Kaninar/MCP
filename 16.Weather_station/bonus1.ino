#include <Arduino.h>

#include <math.h>

#define TERMIST_B 4300

#define VIN 5.0

int minute = 1;

void setup()
{
    Serial.begin(9600);

    Serial.println("Minute\tTemperature");
}

void loop()
{
    float voltage = analogRead(A0) * VIN / 1024.0;
    float r1 = voltage / (VIN - voltage);

    float temperature = 1. / (1. / (TERMIST_B)*log(r1) + 1. / (25. + 273.)) - 273;

    Serial.print(minute);
    Serial.print("\t");
    Serial.print(temperature);
    Serial.print("\t");
    Serial.println(millis());

    delay(10000);
    ++minute;
}
