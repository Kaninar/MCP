import RPi.GPIO as GPIO

led_pin = 7
button_pin = 3

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led_pin, GPIO.OUT)
GPIO.setup(button_pin, GPIO.IN)

try:
    while True:
        GPIO.output(led_pin, not GPIO.input(button_pin))
except KeyboardInterrupt:
    print("keyboard stop")
finally:
    GPIO.cleanup()

'''
Стандартная схема подключения кнопки на пин в подтягивающем режиме и светодиода. Если на входе 0, то светодиод горит, иначе выключается.
'''