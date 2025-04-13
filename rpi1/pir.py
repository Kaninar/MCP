from RPi import GPIO
from time import sleep

pirPin = 12

GPIO.setmode(GPIO.BCM)
GPIO.setup(pirPin, GPIO.IN)

try:
    while True:
        if GPIO.input(pirPin):

            print("Motion Detected!")
        else:
            print("No motion")
        sleep(0.5)
except KeyboardInterrupt:
    print("programs stoped from keyboard")
    GPIO.cleanup()

# Чтение значения с PIR датчика происходит при помощи функции `input()`, 1 - есть движение, 0 - нет.