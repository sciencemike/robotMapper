
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 14 13:55:02 2018

@author: super

"""
import sys
import serial
import threading
import time

#ser = serial.Serial("/dev/ttyACM0", baudrate = 9600, timeout = 200000)
ser = serial.Serial("COM35", baudrate = 9600, timeout = 5)
print ("ready To Go")
# print (b'11112222')
myInt = b'11110600'
print (myInt)
#ser.write(myInt) 
ser.write(myInt)
arduinoData = str(ser.read(20))

print (arduinoData)
arduinoData1 = arduinoData.replace('b','')
#arduinoData2 = arduinoData1.strip('\"')
arduinoData3 = (arduinoData1.split(':'))
value1 = float(arduinoData3[0].strip('\''))
value2 = float(arduinoData3[1])
value3 = float(arduinoData3[2].strip('\''))
print (value1)
print (value2)
print (value3)

#print (int(myInt))

# time.sleep(2)
# myInt = b'10011100'
# print (myInt)
# ser.write(myInt) 

ser.close()   

####


# def stateMachine(int i):
#     ser.write(b'\0x01')
#     dataCheck = ser.read(1)
#     if (dataCheck != 1):
#                 pass #throw error
#     return dataCheck

# def handler():
#     while 1:
#         arduinoData = ser.read(1)
#         if arduinoData is not b'':
#             focus = stateMachine(arduinoData[0])

# #t = threading.Thread(target= GUI_Thread , name = "thread1", args = ())
# t2 = threading.Thread(target= handler, name = "thread2", args = ())

# #t.start()
# t2.start()


