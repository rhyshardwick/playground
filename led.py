#
# LED test programming
#

from gpiozero import LED, Button
from time import sleep
 
led=LED(17)
button = Button(2)
a = 1

# flashing led
#while True:
#    led.on()
#    sleep(1)
#    led.off()
#    sleep(0.2)

while True:
    button.wait_for_press()
    led.toggle()
    a = a+1
    if a < 10: print('ouch')
    if a > 10: print('that is enough')
    if a == 20: print('bastard'); break
    sleep(0.2)
    
