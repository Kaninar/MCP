from RPi import GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
pirPin = 12
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
