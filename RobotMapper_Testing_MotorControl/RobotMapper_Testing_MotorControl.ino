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
// -----------------END Globals---------------------------

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin (9600);
  lidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(5);// Change this number to try out alternate conf
  myservo.attach(6);
  initSensors();
}

void loop() {
    //moveUntilHeading(100);
    dynamicHeading(100);
    delay (100);
    float opCode = 0;
    int firstDigitOpcode = 0;
    int secondDigitOpcode = 0;
    int fifthDigitOpcode = 0;
    int seventhDigitOpcode = 0;
    if (Serial.available()) {
        opCode = Serial.parseInt();
        //opCode = Serial.read();
        if (opCode == 0){
            return;
        }
        firstDigitOpcode = opCode/100000;
        secondDigitOpcode = (opCode -firstDigitOpcode *100000)/1000;
        fifthDigitOpcode = (opCode - (firstDigitOpcode*100000 +secondDigitOpcode*1000))/10;
        seventhDigitOpcode = opCode - (firstDigitOpcode*100000 +secondDigitOpcode*1000 +fifthDigitOpcode*10); 
        
        Serial.println (opCode); 
        Serial.println (firstDigitOpcode); 
        Serial.println (secondDigitOpcode); 
        Serial.println (fifthDigitOpcode); 
        Serial.println (seventhDigitOpcode);
        stateMachine(firstDigitOpcode, secondDigitOpcode,fifthDigitOpcode);
      }
}
float moveUntilHeading(float desiredPosition){
    int lowPWMSpeed = 100;
    while (abs(desiredPosition - getLidarDistance()) > 20)
    {
     // Serial.println("Debug - While outer loop"); 
      
      if (desiredPosition - getLidarDistance() > 0){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
        }
      if (desiredPosition - getLidarDistance() < 0){
          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW);   
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
        }
     
    }  
   while (abs(desiredPosition - getLidarDistance()) > .1)
    {
//      Serial.println("Debug - While small outer loop"); 
//      Serial.println(getHeading());
      if (desiredPosition - getLidarDistance() > 0){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
        }
      if (desiredPosition - getLidarDistance() < 0){
          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW);   
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
        }
    }
}

float dynamicHeading(float desiredPosition){
    int lowPWMSpeed = 100;
    float distanceFromTarget;
    float deadBand = 2;
    distanceFromTarget = (desiredPosition - getLidarDistance());
    while (abs(distanceFromTarget) > deadBand)
    {
     if (distanceFromTarget >= 15){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1+sq((distanceFromTarget)/20));              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(7); 
          distanceFromTarget = desiredPosition - getLidarDistance();
        }
     if (distanceFromTarget <= -15){

          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW); 
          delay(1+sq((distanceFromTarget)/20));
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(7); 
          distanceFromTarget = desiredPosition - getLidarDistance();
          
        }
        if ((distanceFromTarget < 15)& (distanceFromTarget >= 4)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
          distanceFromTarget = desiredPosition - getLidarDistance();
        }
     if ((distanceFromTarget <= -4)& (distanceFromTarget > -15)){
          digitalWrite(motor1Pin1, HIGH); 
          digitalWrite(motor1Pin2, LOW); 
          delay(1);
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(20); 
          distanceFromTarget = desiredPosition - getLidarDistance();
        }
        
       if ((distanceFromTarget <= 4) & (distanceFromTarget > 0)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(50); 
          distanceFromTarget = desiredPosition - getLidarDistance();
        }
    if ((distanceFromTarget >= -4)& (distanceFromTarget < 0)){
          digitalWrite(motor1Pin1, LOW); 
          digitalWrite(motor1Pin2, HIGH);  
          delay(1);              
          digitalWrite(motor1Pin1, LOW);  
          digitalWrite(motor1Pin2, LOW);
          delay(50); 
          distanceFromTarget = desiredPosition - getLidarDistance();
        }
    } 
    distanceFromTarget = desiredPosition - getLidarDistance(); 
}

void moveRight(int timeDelay){
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);   
  delay(timeDelay);              
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);
}
void moveLeft(int timeDelay){
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH);   
  delay(timeDelay);              
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);
}
void continuousScanner (){
  int dist;
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);   
  delay(2);              
  digitalWrite(motor1Pin1, LOW);  
  digitalWrite(motor1Pin2, LOW);
  
 for (pos = 50; pos <= 100; pos += 10) { 
    myservo.write(pos);              
    delay(motorPauseDelay);
    dist = getLidarDistance(); 
    Serial.print(dist);     
    Serial.println(" cm");
  }
  for (pos = 100; pos >= 50; pos -= 10) { 
    myservo.write(pos);   
    delay(motorPauseDelay);            
    dist = getLidarDistance();      
    Serial.print(dist);
    Serial.println(" cm");
  }
}

float getLidarDistance ()
{
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

void stateMachine( int Code, int secondDigit, int thirdDigit){ 
    switch (Code) {
        case 0:
            //Serial.write(Code);
            break;
          
        case 1:    // Get Distance
            Serial.println(Code);
            Serial.println(getLidarDistance ());
            break;
          
        case 2:    // Move Right
            //Serial.println(Code,secondDigit);
            moveRight(secondDigit);
            myservo.write(44);
            break;
          
        case 3:  // Move Left
            //Serial.println(Code,secondDigit);
            moveLeft(secondDigit);
            myservo.write(88);
            break;
                      
        case 4:  // Move UP
            Serial.println(Code,thirdDigit);
            break; 
                      
        case 5:  // Move Down
            Serial.println(moveUntilHeading(100));
            break; 

        case 6:  // Move Down
            Serial.println(getAcceleration());
            break;
            
        case 7:  // Move Down
            Serial.println(getHeading());
            break; 
                   
        case 8:  // Move Down
            Serial.println(getHeading());
            break; 
                  
        default:
            Serial.println("default");
            break;
    }
}
