from RPi import GPIO
from time import sleep

pirPin = 12
ledPin = 23

GPIO.setmode(GPIO.BCM)
GPIO.setup(pirPin, GPIO.IN)

try:
    while True:
        if GPIO.input(pirPin):
            GPIO.output(23, True)
            sleep(5)
            GPIO.output(23, False)
except KeyboardInterrupt:
    print("programs stoped from keyboard")
    GPIO.cleanup()