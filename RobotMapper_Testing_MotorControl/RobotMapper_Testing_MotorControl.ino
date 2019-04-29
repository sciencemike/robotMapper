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
float Mag_value = 0;
float Alt_Angle = 0;
float  Lidar_Distance = 0;
// -----------------END Globals---------------------------

void setup() {
  Serial.begin (230400);
  Serial.println ("Setup Started");
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(5);// Change this number to try out alternate conf
  myservo.attach(6);
  initSensors();
  Serial.println ("Setup Completed");
  
}

void loop() {
  
    float opCode = 0;
    int firstDigitOpcode = 0;
    int secondDigitOpcode = 0;

    if (Serial.available()) {
        opCode = Serial.parseInt();
        //opCode = Serial.read();
        if (opCode == 0){
            return;
        }
        firstDigitOpcode = opCode/10000;
        secondDigitOpcode = (opCode-firstDigitOpcode*10000);

        populateValues( firstDigitOpcode, secondDigitOpcode); 
      }
}

float populateValues (float magnet, float height){
    magnet = magnet/10.0;
    height = height/10.0;
    //Serial.println ((String)"Magnet Value = " +magnet);
    //Serial.println ((String)"Height Value = " +height);
    float magnetval = dynamicHeading (magnet);
    float Altitudes = moveServoAngle (height);
    float LazarDist = getLidarDistance();
    dataOutPitchAltDist(magnetval, Altitudes, LazarDist);
}

void dataOutPitchAltDist(float Mag_value, float Alt_Angle,float Lidar_Distance){
  Serial.println((String)Mag_value+':'+Alt_Angle+':'+Lidar_Distance+"           ");
}

float dynamicHeading(float desiredPosition){
    int lowPWMSpeed = 100;
    float distanceFromTarget;
    float deadBand = 4;
    distanceFromTarget = (desiredPosition - getHeadingCheck());
    while (abs(distanceFromTarget) > deadBand)
    {
     if (distanceFromTarget >= 15){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1+sq((distanceFromTarget)/20));              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(7); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
        }
     if (distanceFromTarget <= -15){

          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW); 
          delay(1+sq((distanceFromTarget)/20));
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(7); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
          
        }
        if ((distanceFromTarget < 15)& (distanceFromTarget >= 4)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
        }
     if ((distanceFromTarget <= -4)& (distanceFromTarget > -15)){
          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW); 
          delay(1);
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
        }
        
       if ((distanceFromTarget <= 4) & (distanceFromTarget > 0)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(50); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
        }
    if ((distanceFromTarget >= -4)& (distanceFromTarget < 0)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(50); 
          distanceFromTarget = desiredPosition - getHeadingCheck();
        }
    } 
    //distanceFromTarget = desiredPosition - getHeadingCheck();
    return getHeadingCheck(); 
}

float getHeadingCheck (){
  float heading ;
  heading = getHeading();
  while (heading==0){
    heading = getHeading();
  }
  return (heading);
//  int val2 = getHeading();
//  int val3 = getHeading();
//  int val4 = getHeading();
//  int val5 = getHeading();
//  int val6 = getHeading();
  
//  float aveVal = (val1+val2+val3+val4+val5+val6)/6;
//  return (aveVal);
}

float moveServoAngle(float moveToAngle){
    /*
moveToAngle = 0 .. Vertical
moveToAngle = 45 .. 45 degrees down from vertical
moveToAngle = 90 .. 90 degrees down from vertical
moveToAngle = 135 .. 135 degrees down from vertical
moveToAngle = 180 .. 180 degrees down from vertical
 
*/
    myservo.write(moveToAngle); 
    return getAcceleration();
}

float getLidarDistance (){
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










    
