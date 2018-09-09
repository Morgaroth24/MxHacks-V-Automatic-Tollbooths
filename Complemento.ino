#include<Servo.h>
const int Trigger = 2;  
const int Echo = 3; 
Servo servoMotor;
void setup() {

 pinMode(13, OUTPUT);
 Serial.begin(9600); 
 pinMode(Trigger, OUTPUT); 
 pinMode(Echo, INPUT);  
 digitalWrite(Trigger, LOW);
 servoMotor.attach(11);
 servoMotor.write(0);
}

void loop() {
   long t; 
  long d; 
  long x;
  do {
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);        
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); 
  d = t/59; 
  delay(100);         
  }while (d>50 || d<1);
 Serial.println(1);
 
 do{
  Serial.println(111);
  if (Serial.available() > 0) {
    x=Serial.read();
    if (x == 115) { 
         servoMotor.write(90);
         delay(10000);               
         servoMotor.write(0);
   }
  }
  
}while(x != 115);
}
