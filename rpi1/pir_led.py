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

'''
Код аналогичен тому, что был в скетче. Если датчик засек движение, то диод загорается на 5 секунд, затем выключается.
'''