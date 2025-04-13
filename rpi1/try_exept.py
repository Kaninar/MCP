from RPi import GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.OUT)
try:
    while True:
        GPIO.output(23, True)
        sleep(0.5)
        GPIO.output(23, False)
        sleep(0.5)
except KeyboardInterrupt:
     print('program stoped')
    GPIO.cleanup()
