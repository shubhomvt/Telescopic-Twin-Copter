#include <Servo.h>
Servo motor
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.attach(D2);
  motor.writeMicroseconds(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int speed1=analogRead(A1);
  speed2=map(speed1,0,1023,1000,2000);
  motor.writeMicroseconds(speed2); 

}
