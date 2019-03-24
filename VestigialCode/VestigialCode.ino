void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


//void moveRight(int timeDelay){
//  digitalWrite(motor1Pin1, HIGH); 
//  digitalWrite(motor1Pin2, LOW);   
//  delay(timeDelay);              
//  digitalWrite(motor1Pin1, LOW);  
//  digitalWrite(motor1Pin2, LOW);
//}
//
//void moveLeft(int timeDelay){
//  digitalWrite(motor1Pin1, LOW); 
//  digitalWrite(motor1Pin2, HIGH);   
//  delay(timeDelay);              
//  digitalWrite(motor1Pin1, LOW);  
//  digitalWrite(motor1Pin2, LOW);
//}


//void stateMachine( int Code, int secondDigit){ 
//    switch (Code) {
//        case 0:
//            //Serial.write(Code);
//            break;
//          
//        case 1:    // Get Distance
//            Serial.println(Code);
//            Serial.println(getLidarDistance ());
//            break;
//          
//        case 2:    // Move Right
//            //Serial.println(Code,secondDigit);
//            moveRight(secondDigit);
//            myservo.write(44);
//            break;
//          
//        case 3:  // Move Left
//            //Serial.println(Code,secondDigit);
//            moveLeft(secondDigit);
//            myservo.write(88);
//            break;
//                      
//        case 4:  // Move UP
//            Serial.println(Code,thirdDigit);
//            break; 
//                      
//        case 5:  // Move Down
//            Serial.println(moveUntilHeading(100));
//            break; 
//
//        case 6:  // Move Down
//            Serial.println(getAcceleration());
//            break;
//            
//        case 7:  // Move Down
//            Serial.println(getHeading());
//            break; 
//                   
//        case 8:  // Move Down
//            Serial.println(getHeading());
//            break; 
//                  
//        default:
//            Serial.println("default");
//            break;
//    }
//}

//void continuousScanner (){
//  int dist;
//  digitalWrite(motor1Pin1, HIGH); 
//  digitalWrite(motor1Pin2, LOW);   
//  delay(2);              
//  digitalWrite(motor1Pin1, LOW);  
//  digitalWrite(motor1Pin2, LOW);
//  
// for (pos = 50; pos <= 100; pos += 10) { 
//    myservo.write(pos);              
//    delay(motorPauseDelay);
//    dist = getLidarDistance(); 
//    Serial.print(dist);     
//    Serial.println(" cm");
//  }
//  for (pos = 100; pos >= 50; pos -= 10) { 
//    myservo.write(pos);   
//    delay(motorPauseDelay);            
//    dist = getLidarDistance();      
//    Serial.print(dist);
//    Serial.println(" cm");
//  }
//}



//float moveUntilHeading(float desiredPosition){
//    int lowPWMSpeed = 100;
//    while (abs(desiredPosition - getLidarDistance()) > 20)
//    {
//     // Serial.println("Debug - While outer loop"); 
//      
//      if (desiredPosition - getLidarDistance() > 0){
//          digitalWrite(motor1Pin1, LOW); 
//          digitalWrite(motor1Pin2, HIGH);  
//          delay(1);              
//          digitalWrite(motor1Pin1, LOW);  
//          digitalWrite(motor1Pin2, LOW);
//        }
//      if (desiredPosition - getLidarDistance() < 0){
//          digitalWrite(motor1Pin1, HIGH); 
//          digitalWrite(motor1Pin2, LOW);   
//          delay(1);              
//          digitalWrite(motor1Pin1, LOW);  
//          digitalWrite(motor1Pin2, LOW);
//        }
//     
//    }  
//   while (abs(desiredPosition - getLidarDistance()) > .1)
//    {
////      Serial.println("Debug - While small outer loop"); 
////      Serial.println(getHeading());
//      if (desiredPosition - getLidarDistance() > 0){
//          digitalWrite(motor1Pin1, LOW); 
//          digitalWrite(motor1Pin2, HIGH);  
//          delay(1);              
//          digitalWrite(motor1Pin1, LOW);  
//          digitalWrite(motor1Pin2, LOW);
//          delay(20); 
//        }
//      if (desiredPosition - getLidarDistance() < 0){
//          digitalWrite(motor1Pin1, HIGH); 
//          digitalWrite(motor1Pin2, LOW);   
//          delay(1);              
//          digitalWrite(motor1Pin1, LOW);  
//          digitalWrite(motor1Pin2, LOW);
//          delay(20); 
//        }
//    }
//}
