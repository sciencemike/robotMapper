
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 14 13:55:02 2018

@author: super
This code reads in the value of the pins.
Then it tells where it is on the gui.
For example if the focus is on RamFluor button.
If user hits enter or back.  The system checks forward or back.

"""
import sys
#import struct
import serial
import threading
import time

ser = serial.Serial("/dev/ttyACM0", baudrate = 9600, timeout = 200000)
print ("ready To Go")
ser.write(b'\0x01')
time.sleep(2)
ser.write(b'\0x02')
def stateMachine(int i):
    ser.write(b'\0x01')
    dataCheck = ser.read(1)
    if (dataCheck != 1):
                pass #throw error
    return dataCheck

def handler():
    while 1:
        arduinoData = ser.read(1)
        if arduinoData is not b'':
            focus = stateMachine(arduinoData[0])

#t = threading.Thread(target= GUI_Thread , name = "thread1", args = ())
t2 = threading.Thread(target= handler, name = "thread2", args = ())

#t.start()
t2.start()

