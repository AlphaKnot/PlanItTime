##Author: Ishaan Kumar
##Importing necessary libraries
##

import RPi.GPIO as GPIO
import time

##FUnction to change output in case the button is pressed
def switch(ev=None):
    GPIO.output(18, GPIO.HIGH)
    print("0")
    GPIO.output(18, GPIO.low)
    exit()

##Using the BCM layout for raspberry pi GPIO pins
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)


##Initialising the pins for I/O
GPIO.setup(18, GPIO.out, initial=GPIO.LOW)
GPIO.setup(23, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(6, GPIO.IN, pull_up_down=GPIO.PUD_UP)


GPIO.output(18, GPIO.HIGH)
time.sleep(0.01)
GPIO.output(18, GPIO.LOW)


##Initialising the states for the program before dial events
counter=0
state=GPIO.input(6)

try: 

##If Button is  pressed, return "0"
    GPIO.add_event_detector(23, GPIO.FALLING, callback=switch)

##Check the direction of rotation and output accordingly; rotate up = 1; rotate down = -1 
    while counter == 0:
        ustate = GPIO.input(6)
        dstate = GPIO.input(22)

        if ustate != state: 
            if dstate != ustate: 
                counter += 1
            else:
                counter -= 1
            
    if counter == 1 or counter == -1:
        print(str(counter))

finally: 
    GPIO.cleanup()





