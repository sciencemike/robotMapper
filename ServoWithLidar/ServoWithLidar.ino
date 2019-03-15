/*
Code by Mike Reid
Sketch of the lidar control system for the RobotMapper.
This program is a small brain on the robot mapper that allows the system
to "See" its environment.   This portion of the code will:
Pan and Tilt the Robot Head.
Fire the Lidar System and receive its data.  Garmin V3.
Send/recieve the data with the main UDOO-Arduino.
The main board sends the commands to the Pro-Micro via serial com
The Pro-Micro pans and tilts the viewing head to the correct location.
The Pro-Micro aquires Lidar positioning.
The Pro-Micro sends the Lidar Positioning back ot the UDOO-Arduino.
Added Functionality will include:
10DOF Accelerometer Data:
This device will allow for the "brain" to specify a XYZ vector that it reqires 
a distance measurement for.  The system will:
Query the Accelerometer:
Calculate shortest movement to get to desired vector:
Move to desired vector.
Query the Accelerometer:
Readjust position if reqired.
Query LIDAR.
Send Distance back to "Brain"

*/
#define  STBY         7
#define  AIN1         3
#define  AIN2         4
#define  BIN1         8
#define  BIN2         9
#define  PWMA         5
#define  PWMB         6
int opCode      = 0;
byte speedofMotors = 50;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(STBY, HIGH);
  Serial.begin(9600);
}

void loop() {
//

    if (Serial.available()) {
        
         //Serial.println("Serial Available");
        opCode = Serial.parseInt();
        //opCode = Serial.read();
        if (opCode == 0){
            return;
        }
        // For debugging
        //Serial.println(opCode);

        stateMachine(opCode, speedofMotors);

      }
//  
//  Serial.println ("Void Loop");
//  digitalWrite(LED_BUILTIN, HIGH);  
//  //motorAMove (false,30);        
//  //motorBMove (true,100);
//  moveForward(speedofMotors);
//  digitalWrite(LED_BUILTIN, LOW);    
//  delay (10);
//  moveReverse(speedofMotors);
//  delay (10);
//  rotateClockwise(speedofMotors);
//  delay (10);
//  rotateCounterClockwise(speedofMotors);
//  delay (10);
}
void stateMachine( int Code,int speedofMotors){ 
    switch (Code) {
        case 0:
            //Serial.write(Code);
            break;
          
        case 1:    // MoveForward
            Serial.println(Code);
            moveForward(speedofMotors);
            break;
          
        case 2:    // Move Reverse
            Serial.println(Code);
            moveReverse(speedofMotors);
            break;
          
        case 333:    // Rotate Clockwise
            Serial.println(Code);
            rotateClockwise(speedofMotors);
            break;
                      
        case 444:    // Rotate Counter Clockwise
            Serial.println(Code);
            rotateCounterClockwise(speedofMotors);
            break;    
                  
        
        default:
            //Serial.write(0x0f);
            //Serial.write(0x0f);
            Serial.println("default");
            break;
    }
}
void moveForward(byte magnitude){
  // this function moves the system forward a certain amount.   Denoted by mm
  // Conversion factor from distance to time.
  // Conversion with feedback
  
  Serial.println ("Forward");
  int timeToFinish = 1000;
  
  // Set motor movement direction
  motorAMove( true,  magnitude);
  motorBMove( true,  magnitude);
  
  // Delay to Move motor a certian amt of time
  delay (timeToFinish);
  // Stop Motor Movement
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void moveReverse(byte magnitude){
  // this function moves the system Reverse a certain amount.   Denoted by mm
  // Conversion factor from distance to time
  // Conversion with feedback
  Serial.println ("Reverse");
  int timeToFinish = 1000;
  // Sets motor directio
  motorAMove( false,  magnitude);
  motorBMove( false, magnitude);
      delay (timeToFinish);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

void rotateClockwise (byte magnitude){  
  // this function moves the system clockwise a certain amount.   Denoted by degrees
  // Conversion factor from time of pulse to degrees 
  // Conversion with feedback
  Serial.println ("Clockwise");
  int timeToFinish = 1000;
  motorAMove( false,  magnitude);
  motorBMove( true,  magnitude);    
  delay (timeToFinish);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

void rotateCounterClockwise (byte magnitude){
  // this function moves the system CounterClockwise a certain amount.   Denoted by degrees
  // Conversion factor from time of pulse to degrees 
  // Conversion with feedback
  Serial.println ("CounterClockwise");
  int timeToFinish = 1000;
  motorAMove( true,  magnitude);
  motorBMove( false,  magnitude);
      delay (timeToFinish);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

void motorAMove( bool isForward, byte magnitude ){
  if (isForward){
    digitalWrite(AIN1, LOW); 
    digitalWrite(AIN2, HIGH); 
    analogWrite(PWMA, magnitude); 
  }
  else {
    digitalWrite(AIN1, HIGH); 
    digitalWrite(AIN2, LOW); 
    analogWrite(PWMA, magnitude); 
  }

}
void motorBMove( bool isForward, byte magnitude){
  if (isForward){
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, HIGH); 
    analogWrite(PWMB, magnitude); 
  }
  else {
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW); 
    analogWrite(PWMB, magnitude); 
  }

}
