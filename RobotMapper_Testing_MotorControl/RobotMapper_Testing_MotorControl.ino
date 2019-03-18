/*
  Robot Mapper Test Motor Control and Lidar

  Tests the pan motor, tilt motor and the Lidar Unit
  
  Created March 15 2019
*/

#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>

// -----------------Globals---------------------------
int motorPauseDelay = 50;
Servo myservo;
LIDARLite lidarLite;
int cal_cnt = 0;
#define motor1Pin1 8
#define motor1Pin2 10
#define motor2Pin1 7
#define motor2Pin2 9
int pos = 0;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin (9600);
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(5);// Change this number to try out alternate conf
  myservo.attach(6);
}

void loop() {
  int dist;
  
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);   
  delay(2);              
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);
  
 for (pos = 50; pos <= 100; pos += 10) { 
    
    myservo.write(pos);              
    delay(motorPauseDelay);
    dist = lidarLite.distance(false); 
    Serial.print(dist);     
    Serial.println(" cm");
    
  }
  for (pos = 100; pos >= 50; pos -= 10) { 
    myservo.write(pos);             
    dist = lidarLite.distance(false);      
    Serial.print(dist);
    Serial.println(" cm");
    delay(motorPauseDelay);  

  }
}
