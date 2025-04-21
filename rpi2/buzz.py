import RPi.GPIO as GPIO
from time import sleep

buzzer_pin = 24

GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT)
buzz = GPIO.PWM(buzzer_pin, 2000)

try:
    while True:
        buzz.start(50)
        sleep(3)
        buzz.stop()
        sleep(2)
except KeyboardInterrupt:
    print("keyboard stop")
finally:
    GPIO.cleanup()

'''
При помощи `PWM()` инициализируется пищалка на пине 24 с частотой 2 Кгц, при помощи метода `start()` запускается писк, метод `stop()` прекращает.
'''