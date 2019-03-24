/**
* Lidar and Gimbal and accelerometer data.
* Receive a command
* Query its angular postion.   
* Move to new angle
* Aquire Lidar Distance.
* Return angle and lidar value
*/
#define PanPWM_1 9
#define PanPWM_2 10
#include <Servo.h>
#include <Wire.h>
#include <LIDARLite.h>
Servo myservo;
// Globals
LIDARLite lidarLite;
int cal_cnt = 0;
int dist = 0;

void setup()
{
  Serial.begin(9600); // Initialize serial connection to display distance readings
  Serial.println("Setup Complete");
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(5); // Change this number to try out alternate configurations
  pinMode(PanPWM_1, OUTPUT);
  pinMode(PanPWM_2, OUTPUT);
  myservo.attach(6);
}

void loop()
{
  myservo.write(100);
  digitalWrite(PanPWM_1, 0);
  digitalWrite(PanPWM_2, 1);
  delay(222);
  digitalWrite(PanPWM_1, 0);
  digitalWrite(PanPWM_2, 0);
  
  Serial.print(getLidarDistance());
  Serial.println(" cm");
  delay(1000);
  
  myservo.write(70);
  digitalWrite(PanPWM_1, 1);
  digitalWrite(PanPWM_2, 0);
  delay(222);
  digitalWrite(PanPWM_1, 0);
  digitalWrite(PanPWM_2, 0);
  delay(50);
}

float getLidarDistance ()
{
  int val1 = lidarLite.distance();
  int val2 = lidarLite.distance();
  int val3 = lidarLite.distance();
  int val4 = lidarLite.distance();
  int val5 = lidarLite.distance();
  int val6 = lidarLite.distance();
  int val7 = lidarLite.distance();
  int val8 = lidarLite.distance();  
  int val9 = lidarLite.distance();
  int val10 = lidarLite.distance();
  int val11 = lidarLite.distance();
  int val12 = lidarLite.distance();
  float aveVal = (val1+val2+val3+val12+val4+val5+val6+val7+val8+val9+val10+val11)/12.0;
  return (aveVal);
}

