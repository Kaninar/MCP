from RPi import GPIO
from time import sleep

ledPin1 = 23
ledPin2 = 24

ledPins= [23, 24]
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(ledPins[0], GPIO.OUT)
GPIO.setup(ledPins[1], GPIO.OUT)

switch = 0

try:
    while True:
        GPIO.output(ledPins[switch], True)
        sleep(0.5)
        GPIO.output(ledPins[switch], False)
        
        switch += 1
        switch %= 2

except KeyboardInterrupt:
     print('program stoped from keyboard')
GPIO.cleanup()
