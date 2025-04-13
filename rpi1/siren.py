from RPi import GPIO
from time import sleep

ledPins= [23, 24]
switch = False

GPIO.setmode(GPIO.BCM)
GPIO.setup(ledPins[0], GPIO.OUT)
GPIO.setup(ledPins[1], GPIO.OUT)

try:
    while True:
        GPIO.output(ledPins[switch], True)
        sleep(0.5)
        GPIO.output(ledPins[switch], False)
        switch = not switch

except KeyboardInterrupt:
     print('program stoped from keyboard')
GPIO.cleanup()

# Номера пинов светодиодов занесены в список. Переключение между ними происходит при помощи переменной `switch`, которая поочередно меняет значения.