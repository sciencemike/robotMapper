
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 14 13:55:02 2018

@author: super

"""
import sys
import serial
import threading
import time
import math

panValue = 110
tiltValue = 110
def getVectorData():
	arduinoData = str(ser.read(20))
	arduinoData1 = arduinoData.replace('b','')
	arduinoData3 = (arduinoData1.split(':'))
	value1 = float(arduinoData3[0].strip('\''))
	value2 = float(arduinoData3[1])
	value3 = float(arduinoData3[2].strip('\''))
	print (value1)
	return (value1, value2, value3)

def convertToCartesian(vectz):
	#The line joining the origin to the point will be the vector. 
	#Let the scalar length be r. 
	#If the β angle is measured from Y axis towards Z axis and α from X axis towards Y:
	#x=rcosβsinα
	#y=rcosβcosα
	#z=rsinβ
	#math.radians(x)
	AngleX   = vectz[0]
	AngleY   = vectz[1]
	Distance = vectz[2]
	xx = (Distance * math.cos(AngleY) * math.sin(AngleX))
	yy = (Distance * math.cos(AngleY) * math.cos(AngleX))
	zz = (Distance * math.sin(AngleY))
	return (xx, yy, zz)

def createIntCommand(pan, tilt):
	myInt = str.encode(str(pan *100000 + tilt*10))
	#//myIntByte =  str.encode(myInt)
	print (myInt)
	return (myInt)
#ser = serial.Serial("/dev/ttyACM0", baudrate = 9600, timeout = 200000)
ser = serial.Serial("COM35", baudrate = 9600, timeout = 5)
print ("ready To Go")
#myInt = b'11110600'
ser.write(createIntCommand( panValue, tiltValue))
vectors = getVectorData()
cartesian = (convertToCartesian(vectors))
print (cartesian)



# for i in range(200, 1800):
#     for j in range(1000, 2500):
#         servo13.duty_cycle = servo_duty_cycle(j/1000)
#         time.sleep (.01)
#         try:
#             print(convertToCartesian(sensor.distance, i, j))
#         except RuntimeError as e:
#             print("(0, 0, 0)")





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


