#include <Servo.h>
Servo motor1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.attach(D2);
  motor2.attach(D3);
  motor1.writeMicroseconds(1000);
  motor2.writeMicroseconds(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int speed1=analogRead(A1);
  speed2=map(speed1,0,1023,1000,2000);
  motor1.writeMicroseconds(speed2); 
  motor2.writeMicroseconds(speed2);

}
