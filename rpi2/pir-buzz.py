import RPi.GPIO as GPIO

pirPin = 12
buzzer_pin = 24

GPIO.setmode(GPIO.BOARD)
GPIO.setup(buzzer_pin, GPIO.OUT)
GPIO.setup(pirPin, GPIO.IN)
buzz = GPIO.PWM(buzzer_pin, 2000)

try:
    while True:
        if GPIO.input(pirPin):
            buzz.start(50)
        else:
            buzz.stop()
except KeyboardInterrupt:
    print("keyboard stop")
finally:
    GPIO.cleanup()

'''
При помощи кода из прошлой лабораторной подключается PIR датчик, а работа пищалки устанавливается при помощи кода из прошлого скетча.
Когда PID датчик обнаруживает движение, то воспроизводится звук, в противном случае отключается.
'''