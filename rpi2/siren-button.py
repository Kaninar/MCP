from RPi.GPIO import setmode, setup, input, output, PWM, OUT, IN, BOARD, cleanup
from time import sleep

led_pin = 7
button_pin1 = 3
button_pin2 = 5
buzzer_pin = 12

setmode(BOARD)
setup(buzzer_pin, OUT)
setup(led_pin, OUT)
setup(button_pin1, IN)
setup(button_pin2, IN)
buzz = PWM(buzzer_pin, 2000)

try:
    while True:
        if input(button_pin1) ^ input(button_pin2):
            output(led_pin, True)
            buzz.start(50)
        else:
            output(led_pin, False)
            buzz.stop()
except KeyboardInterrupt:
    print("keyboard stop")
finally:
    cleanup()

'''
Код представляет из себя компиляцию из прошлых заданий с добавлением одной допалнительной кнопки.
Проверка на запуск пищалки и светодиода определяется при помощи оператора XOR. 1 - когда любая из кнопок нажата и 0 когда ни одна не нажата, либо обе нажаты.
'''