void setup() {
    // put your setup code here, to run once:
    Serial.begin (9600);
    pinMode(LED_BUILTIN, OUTPUT);
    //Serial.println ("Setup Completed");
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
    delay(500);    
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
}

void loop() {
//    // put your main code here, to run repeatedly:
//    int type = 50;
//    int spectrum = 100;
//    int lensPos = 200;
//    int gratingPos = 300;
//    
//    delay (1000);
//    Serial.println((String)"arduino_return={'type':'"+type+"','value':{'spectrum':"+spectrum+",'lens_pos':"+lensPos+",'grating_pos':"+gratingPos+"}};");
    
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
        //Serial.println(opCode);
        //Serial.println (firstDigitOpcode); 
        //Serial.println (secondDigitOpcode) 
      }
      if (firstDigitOpcode == 1111){
          digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(500);                       // wait for a second
          digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
          delay(500);          
          digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(500);                       // wait for a second
          digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
          delay(500); 
          digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(500);                       // wait for a second
          digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
          delay(500);          
          digitalWrite(17, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(500);                       // wait for a second
          digitalWrite(17, LOW);    // turn the LED off by making the voltage LOW
          delay(500); 
      }
}
