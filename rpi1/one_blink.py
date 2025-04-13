from RPi import GPIO
from time import sleep
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.OUT)

GPIO.output(23, True)
sleep(5)
GPIO.output(23, False)
GPIO.cleanup()

'''
`sleep()` - аналог функции `delay()`. `output()` - аналог функции `digitalWrite()`, \
которая принимает `True` как `HIGH` и `False` как `LOW`. `setup()` - аналог функции `pinMode()`.
`cleanup()` - функция необходима для очистки настроек GPIO и не было проблем с работой других программ. В первых строчках происходит импорт необходимых модулей.
'''