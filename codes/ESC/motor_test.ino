#include <Servo.h>
Servo motor1;
Servo motor2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.attach(2);
  motor2.attach(3);
  motor1.writeMicroseconds(1000);
  motor2.writeMicroseconds(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int speed1=analogRead(A1);
  int speed2=map(speed1,0,1023,1000,2000);
  motor1.writeMicroseconds(speed2); 
  motor2.writeMicroseconds(speed2);

}
