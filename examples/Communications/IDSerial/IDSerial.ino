/* 
  simple serial sketch based on one by @madias
*/
#define ledpin 13
boolean flip=0;
void setup() {

/* 
  currently setup is done by STM32CubeMX 

*/
  
  Serial.begin(9600);
 Serial1.begin(9600);


 pinMode(ledpin,OUTPUT);
}

void loop() {
flip=!flip;
digitalWrite(ledpin,flip);
  Serial.println("Port: Serial0");
  delay(100);
 
 Serial1.println("Port: Serial1");
  delay(100);  // delay in between writes for stability
 
}
