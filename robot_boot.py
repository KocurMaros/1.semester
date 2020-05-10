import curses
import RPi.GPIO as GPIO
import time 
import os
from time import sleep

screen = curses.initscr()
curses.noecho()
curses.cbreak()
screen.keypad(True)

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(15 , GPIO.OUT) #motor 1 
GPIO.setup(13 , GPIO.OUT) #motor 1 
GPIO.setup(16 , GPIO.OUT) #motor 2 
GPIO.setup(18 , GPIO.OUT) #motor 2 
GPIO.setup(35, GPIO.OUT) #pwm 1 
GPIO.setup(12, GPIO.OUT) #pwm 2 
GPIO.setup(37, GPIO.OUT) #servo
GPIO.setup(21, GPIO.IN) #photo 1 
GPIO.setup(22, GPIO.IN) #photo 2
GPIO.setup(33, GPIO.IN) # arduino error 


r = GPIO.PWM(35, 100)
l = GPIO.PWM(12, 100)
r.start(0)
l.start(0)

GPIO.output(15, False)
GPIO.output(16, False)
GPIO.output(13, False)
GPIO.output(18, False)

prev_milli = int(round(time.time()*1000)) 
count1 = 0 #pocitadlo otacok jedneho motora 
count2 = 0 #pocitadlo otacok jedneho motora

x = 0
y = 0
g = 32
run = True

def change():
    global prev_milli
    global x
    global y
    global count1
    global count2
    act_milli = int(round(time.time()*1000))
    if((act_milli-prev_milli)>50):
        if count1 != count2:
            if count1 < count2:
                if(y-x)<20:
                    x-=2
            elif count1 > count2:
                if(x-y)<20:
                    y-=2
	prev_milli = act_milli
    if(x<=0):
        x=0
    elif(x>=100):
        x=100
    if(y<=0):
        y=0
    elif(y>=100):
        y=100
    r.ChangeDutyCycle(x)
    l.ChangeDutyCycle(y)
 
def get_spr1(g):   #photo1
    global count1
    count1+=1
    change()

def get_spr2(g):   #photo2
    global count2
    count2+=1
    change()

def direction(dire):
    global x
    global y 
    x = 10
    y = 10
    if dire == 258: #forward
        GPIO.output(15, True)
        GPIO.output(13, False)
        GPIO.output(18, False)
        GPIO.output(16, True)
    elif dire == 259:  #backward
        GPIO.output(15, False)
        GPIO.output(13, True)
        GPIO.output(18, True)
        GPIO.output(16, False)
    elif dire == 260:   #left
        GPIO.output(15, True)
        GPIO.output(13, False)
        GPIO.output(18, True)
        GPIO.output(16, False)
    elif dire == 261:      #right
        GPIO.output(15, False)
        GPIO.output(13, True)
        GPIO.output(18, False)
        GPIO.output(16, True)
    elif dire == 32:       #stop
        GPIO.output(15, False)
        GPIO.output(16, False)
        GPIO.output(13, False)
        GPIO.output(18, False)
        
def speed(spd):
    global x
    global y
    if spd == 108:
        x+=2
        y+=2
    elif spd == 268:
        x-=2
        y-=2
    change()
    
def servo(ser):
    if ser == 118:
        GPIO.output(37, True)
        sleep(0.0005)
        GPIO.output(37, False)
    elif ser == 116:
        GPIO.output(37, True)
        sleep(0.0025)
        GPIO.output(37, False)
        
def error(g):
    r.ChangeDutyCycle(0)
    l.ChangeDutyCycle(0)
    GPIO.output(15, False)
    GPIO.output(16, False)
    GPIO.output(11, False)
    GPIO.output(18, False)
    
def report():
    global x
    global y
    print("x", x," y", y," c1", count1," c2", count2)
    
GPIO.add_event_detect(21, GPIO.RISING, callback=get_spr1)
GPIO.add_event_detect(22, GPIO.RISING, callback=get_spr2)
GPIO.add_event_detect(33, GPIO.RISING, callback=error)

while(run):
    char = screen.getch()
    os.system('cls' if os.name == 'nt' else 'clear')
    global x
    global y
    global count1
    global count2
    if char ==  108 or char == 268:
        spd = char
        speed(spd)
    elif char == 258 or char == 259 or char == 260 or char == 261 or char == 32:
        dire = char
	x = 0
	y = 0
	count1 = 0
	count2 = 0
	change()
        direction(dire)
    elif char == 116 or char == 118:
        ser = char
        servo(ser)
    elif char == 105:
        report()
    elif char == 263:
        GPIO.cleanup()
        curses.nocbreak()
        screen.keypad(0)
        curses.echo()
        curses.endwin()
        run = False
