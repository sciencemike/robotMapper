void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int type = 50;
  int spectrum = 100;
  int lensPos = 200;
  int gratingPos = 300;
  
  delay (1000);
  Serial.println((String)"arduino_return={'type':'"+type+"','value':{'spectrum':"+spectrum+",'lens_pos':"+lensPos+",'grating_pos':"+gratingPos+"}};");
}
