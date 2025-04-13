from RPi import GPIO
from time import sleep

counter = 0
dot = 0.5
dash = 1
ledPin = 23
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.OUT)

try:
    while True:
        GPIO.output(ledPin, True)
        symbol = dot if (int(counter / 3) % 2) == 0 else dash

        sleep(symbol)
        GPIO.output(ledPin, False)

        counter += 1
        
        if counter == 8:
            sleep(dash * 3)
        else:
            sleep(dot)
            
        counter %= 9
        
except KeyboardInterrupt:
     print('program stoped from keyboard')
GPIO.cleanup()
