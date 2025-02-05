# MicroControllerProgramming

Если у вас есть, что добавить или вы считаете, что нужноBeacon что-то поменять, то кидайте pull реквесты

1. [Маячок](https://github.com/Kaninar/MCP/blob/main/1.Beacon)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/1.Beacon/Beacon.ino)
    2. Сделайте так, чтобы маячок светился полсекунды, а пауза между вспышками была равна одной секунде.
        - [code](https://github.com/Kaninar/MCP/blob/main/1.Beacon/bonus1.ino)
    3. Измените код примера так, чтобы маячок включался на три секунды после запуска устройства, а затем мигал в стандартном режиме.
        - [code](https://github.com/Kaninar/MCP/blob/main/1.Beacon/bonus1.ino)

2. [Маячок с нарастающей яркостью](https://github.com/Kaninar/MCP/blob/main/2.Beacon_with_increasing_brightness)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/2.Beacon_with_increasing_brightness/Beacon_with_increasing_brightness.ino)
    2. Отключите питание, отключите светодиод от 9-го порта и подключите к 11-му. Измените программу так, чтобы схема снова заработала.
        - [code](https://github.com/Kaninar/MCP/blob/main/2.Beacon_with_increasing_brightness/bonus1.ino)
    3. Измените код программы так, чтобы в течение секунды на светодиод последовательно подавалось усреднённое напряжение 0, 1, 2, 3, 4, 5 В.
        - [code](https://github.com/Kaninar/MCP/blob/main/2.Beacon_with_increasing_brightness/bonus1.ino)
    4. Возьмите еще один светодиод, резистор на 220 Ом и соберите аналогичную схему на этой же макетке, подключив светодиод к пину номер 3 и другому входу GND, измените программу так, чтобы светодиоды мигали в противофазу: первый выключен, второй горит максимально ярко и до противоположного состояния.
        - [code](https://github.com/Kaninar/MCP/blob/main/2.Beacon_with_increasing_brightness/bonus2.ino)

3. [Светильник с управляемой яркостью](https://github.com/Kaninar/MCP/blob/main/3.Lamp_with_controlled_brightness)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/3.Lamp_with_controlled_brightness/Lamp_with_controlled_brightness.ino)
    2. Отключите питание платы, подключите к порту 5 еще один светодиод. Измените код таким образом, чтобы второй светодиод светился на 1/8 от яркости первого.
        - [code](https://github.com/Kaninar/MCP/blob/main/3.Lamp_with_controlled_brightness/bonus1.ino)

4. [Терменвокс](https://github.com/Kaninar/MCP/blob/main/4.Theremin)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/4.Theremin/Theremin.ino)
    2. Уберите из программы чтение датчика освещенности и пропищите азбукой Морзе позывной SOS: три точки, три тире, три точки.
        - [code](https://github.com/Kaninar/MCP/blob/main/4.Theremin/bonus1.ino)
    3. Измените код программы так, чтобы с падением освещенности звук становился ниже (например, падал от 5 кГц до 2,5 кГц).
        - [code](https://github.com/Kaninar/MCP/blob/main/4.Theremin/bonus1.ino)
    4. Измените код программы так, чтобы звук терменвокса раздавался не непрерывно, а 10 раз в секунду с различимыми паузами.
        - [code](https://github.com/Kaninar/MCP/blob/main/4.Theremin/bonus2.ino)

5. [Ночной светильник](https://github.com/Kaninar/MCP/blob/main/5.Night_lamp)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/5.Night_lamp/Night_lamp.ino)
    2. Перепишите программу без использования переменной tooDark с сохранением функционала устройства.
        - [code](https://github.com/Kaninar/MCP/blob/main/5.Night_lamp/bonus1.ino)
    3. Добавьте в схему еще один светодиод. Дополните программу так, чтобы при падении освещенности ниже порогового значения включался один светодиод, а при падении освещенности ниже половины от порогового значения включались оба светодиода.
        - [code](https://github.com/Kaninar/MCP/blob/main/5.Night_lamp/bonus1.ino)
    4. Измените схему и программу так, чтобы светодиоды включались по прежнему принципу, но светились тем сильнее, чем меньше света падает на фоторезистор.
        - [code](https://github.com/Kaninar/MCP/blob/main/5.Night_lamp/bonus2.ino)

6. [Пульсар](https://github.com/Kaninar/MCP/blob/main/6.Pulsar)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/6.Pulsar/Pulsar.ino)
    2. Измените программу так, чтобы яркость шкалы росла только до половины от максимальной.
        - [code](https://github.com/Kaninar/MCP/blob/main/6.Pulsar/bonus1.ino)
    3. Измените программу так, чтобы шкала становилась максимально яркой в три раза быстрее, без изменения функции `delay.`
        - [code](https://github.com/Kaninar/MCP/blob/main/6.Pulsar/bonus1.ino)
    4. Измените исходную программу так, чтобы такой же результат был получен без использования операции `%`, но с применением условного оператора `if`.
         - [code](https://github.com/Kaninar/MCP/blob/main/6.Pulsar/bonus2.ino)

7. [Бегущий огонёк](https://github.com/Kaninar/MCP/blob/main/7.Running_light)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/7.Running_light/Running_light.ino)
    2. Измените код так, чтобы светодиоды переключались раз в секунду.
        - [code](https://github.com/Kaninar/MCP/blob/main/7.Running_light/bonus0.ino)
    3. Не выключая порты, сделайте так, чтобы огонёк бежал только по средним четырем делениям шкалы.
        - [code](https://github.com/Kaninar/MCP/blob/main/7.Running_light/bonus1.ino)
    4. Переделайте программу так, чтобы вместо `int pin = FIRST_LED_PIN + (ms / 120) % 10` перемещением огонька управлял цикл `for`
        - [code](https://github.com/Kaninar/MCP/blob/main/7.Running_light/bonus2.ino)
    5. Не меняя местами провода, измените программу так, чтобы огонёк бегал в обратном направлении.
        - [code](https://github.com/Kaninar/MCP/blob/main/7.Running_light/bonus3.ino)

8. [Мерзкое пианино](https://github.com/Kaninar/MCP/blob/main/8.Nasty_piano)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/8.Nasty_piano/Nasty_piano.ino)
    2. Сделайте так, чтобы наше пианино звучало в диапазоне от 2 кГц до 5 кГц.
        - [code](https://github.com/Kaninar/MCP/blob/main/8.Nasty_piano/bonus1.ino)
    3. Добавьте еще 2 кнопки и измените программу так, чтобы можно было извлечь 5 различных нот.
        - [code](https://github.com/Kaninar/MCP/blob/main/8.Nasty_piano/bonus1.ino)
    4. Подключите кнопки по схеме со стягивающим резистором и измените программу так, чтобы она продолжала работать.
        - [code](https://github.com/Kaninar/MCP/blob/main/8.Nasty_piano/bonus2.ino)

9. [Миксер](https://github.com/Kaninar/MCP/blob/main/9.Mixer)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/9.Mixer/Mixer.ino)
    2. Внесите единственное изменение в программу, после которого максимальной скоростью вращения мотора составит половину от возможной.
        - [code](https://github.com/Kaninar/MCP/blob/main/9.Mixer/bonus1.ino)
    3. Перепишите программу без использования инструкции `continue`.
        - [code](https://github.com/Kaninar/MCP/blob/main/9.Mixer/bonus1.ino)
    4. Добавьте в схему еще одну кнопку, чтобы у миксера стало три режима. Понадобилось ли изменять что-либо в программе?
        - [code](https://github.com/Kaninar/MCP/blob/main/9.Mixer/bonus2.ino)

10. [Кнопочный переключатель](https://github.com/Kaninar/MCP/blob/main/11.Pushbutton_switch)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Pushbutton_switch/Pushbutton_switch.ino)
    2. Измените код так, чтобы светодиод переключался только после отпускания кнопки.
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Pushbutton_switch/bonus1.ino)
    3. Добавьте в схему еще одну кнопку и доработайте код, чтобы светодиод зажигался только при нажатии обеих кнопок.
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Pushbutton_switch/bonus1.ino)

11. [Светильник с кнопочным управлением](https://github.com/Kaninar/MCP/blob/main/11.Lamp_with_pushbutton_control)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Lamp_with_pushbutton_control/Lamp_with_pushbutton_control.ino)
    2. Доработайте код таким образом, чтобы шаг изменения яркости настраивался в одном месте.
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Lamp_with_pushbutton_control/bonus1.ino)
    3. Создайте еще одну функцию и переделайте код так, чтобы одна функция отвечала за отслеживание нажатий, а другая — за вычисление яркости светодиода и возвращала его в `analogWrite`.
        - [code](https://github.com/Kaninar/MCP/blob/main/11.Lamp_with_pushbutton_control/bonus1.ino)

12. [Кнопочные ковбои](https://github.com/Kaninar/MCP/blob/main/12.Pushbutton_cowboys)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/12.Pushbutton_cowboys/Pushbutton_cowboys.ino)
    2. Сделайте напряженный вариант игры: пусть интервал между сигналами будет в диапазоне от 10 до 15 секунд.
        - [code](https://github.com/Kaninar/MCP/blob/main/12.Pushbutton_cowboys/bonus1.ino)
    3. В игре есть лазейка: кнопку можно зажать до сигнала «пли!» и таким образом сразу же выиграть. Дополните программу так, чтобы так выиграть было нельзя.
        - [code](https://github.com/Kaninar/MCP/blob/main/12.Pushbutton_cowboys/bonus1.ino)
    4. Добавьте в игру еще двух ковбоев!
        - [code](https://github.com/Kaninar/MCP/blob/main/12.Pushbutton_cowboys/bonus2.ino)

13. [Секундомер](https://github.com/Kaninar/MCP/blob/main/13.Stopwatch)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/13.Stopwatch/Stopwatch.ino)
    2. Измените код, чтобы индикатор отсчитывал десятые секунды.
        - [code](https://github.com/Kaninar/MCP/blob/main/13.Stopwatch/bonus1.ino)
    3. Поменяйте программу так, чтобы вместо символа «0» отображался символ «А».
        - [code](https://github.com/Kaninar/MCP/blob/main/13.Stopwatch/bonus1.ino)
    4. Дополните схему и программу таким образом, чтобы сегмент-точка включался при прохождении четных чисел и выключался на нечетных.
        - [code](https://github.com/Kaninar/MCP/blob/main/13.Stopwatch/bonus2.ino)

14. [Счётчик нажатий](https://github.com/Kaninar/MCP/blob/main/14.Keystroke_counter)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/14.Keystroke_counter/Keystroke_counter.ino)
    2. Заставьте `shiftOut()` отправлять биты, начиная со старшего, и измените код так, чтобы счетчик по-прежнему показывал арабские цифры.
        - [code](https://github.com/Kaninar/MCP/blob/main/14.Keystroke_counter/bonus1.ino)
    3. Замените кнопку на датчик света (фоторезистор в схеме делителя напряжения) и переделайте программу так, чтобы индикатор цифрой показывал уровень освещенности.
        - [code](https://github.com/Kaninar/MCP/blob/main/14.Keystroke_counter/bonus1.ino)

15. [Комнатный термометр](https://github.com/Kaninar/MCP/blob/main/15.Room_thermometer)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/15.Room_thermometer/Room_thermometer.ino)
    2. Измените код программы таким образом, чтобы индикатор включался при 0 градусов и его показания прирастали на одно деление каждые 5 градусов.
        - [code](https://github.com/Kaninar/MCP/blob/main/15.Room_thermometer/bonus1.ino)
    3. Добавьте в схему пьезопищалку и доработайте программу так, чтобы срабатывала звуковая сигнализация при достижении температуры, например, 25 градусов.
        - [code](https://github.com/Kaninar/MCP/blob/main/15.Room_thermometer/bonus1.ino)

16. [Метеостанция](https://github.com/Kaninar/MCP/blob/main/16.Weather_station)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/16.Weather_station/Weather_station.ino)
    2. Перед таблицей данных о температуре добавьте заголовок (например, "Meteostation").
        - [code](https://github.com/Kaninar/MCP/blob/main/16.Weather_station/bonus1.ino)
    3. Добавьте столбец, содержащий количество секунд, прошедших с момента запуска микроконтроллера. Можно уменьшить интервал передачи данных.
        - [code](https://github.com/Kaninar/MCP/blob/main/16.Weather_station/bonus1.ino)

17. [Пантограф](https://github.com/Kaninar/MCP/blob/main/17.Pantograph)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/17.Pantograph/Pantograph.ino)
    2. Измените программу так, чтобы по мере поворота ручки потенциометра, сервопривод последовательно занимал 8 положений: 45, 135, 87, 0, 65, 90, 180, 150°.
        - [code](https://github.com/Kaninar/MCP/blob/main/17.Pantograph/bonus1.ino)
    3. Предположим, что сервопривод управляет шторкой, и нам нужно поддерживать постоянное количество света в помещении. Создайте такой механизм.
        - [code](https://github.com/Kaninar/MCP/blob/main/17.Pantograph/bonus1.ino)

18. [Тестер батареек](https://github.com/Kaninar/MCP/blob/main/18.Battery_tester)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/18.Battery_tester/Battery_tester.ino)
    2. Создайте секундомер, который будет отсчитывать время, прошедшее с начала работы Arduino и выводить секунды и сотые секунд на экран.
        - [code](https://github.com/Kaninar/MCP/blob/main/18.Battery_tester/bonus1.ino)
    3. Совместите отсчет времени и измерение напряжения. Отобразите все данные на дисплее. Отправляйте их раз в 10 секунд на компьютер. Теперь вы можете выводить без компьютера и проводов любые данные, с которыми работаете, и использовать это как в режиме эксплуатации вашего устройства, так и во время отладки!
        - [code](https://github.com/Kaninar/MCP/blob/main/18.Battery_tester/bonus1.ino)

19. [Светильник, управляемый по USB](https://github.com/Kaninar/MCP/blob/main/19.Lamp_controlled_via_USB)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/19.Lamp_controlled_via_USB/Lamp_controlled_via_USB.ino)
    2. Проверьте, попадает ли переданное число в диапазон значений, которые нужно передавать в analogWrite(). Передайте на компьютер сообщение об ошибке, если нет.
        - [code](https://github.com/Kaninar/MCP/blob/main/19.Lamp_controlled_via_USB/bonus1.ino)
    3. Переделайте программу так, чтобы устройство распознавало текстовые команды, например, «on» и «off», и соответственно включало и выключало светодиод. Вам может пригодиться один из методов String : toLowerCase(yourString) или toUpperCase(yourString),которые возвращают переданную строку yourString, приведенную к нижнему или верхнему регистру соответственно.
        - [code](https://github.com/Kaninar/MCP/blob/main/19.Lamp_controlled_via_USB/bonus1.ino)

21. [Перетягивание каната](https://github.com/Kaninar/MCP/blob/main/21.Tug_of_war)
    1. Скетч
        - [code](https://github.com/Kaninar/MCP/blob/main/21.Tug_of_war/Tug_of_war.ino)
    2. Вместо светодиодной шкалы подключите сервопривод и измените код таким образом, чтобы перетягивание демонстрировалось путем отклонения сервопривода от среднего положения.
        - [code](https://github.com/Kaninar/MCP/blob/main/21.Tug_of_war/bonus1.ino)
