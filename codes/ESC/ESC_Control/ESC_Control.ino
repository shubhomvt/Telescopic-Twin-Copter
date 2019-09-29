/*Controlling ESC 
 * Created By Likith
 * Feel Free to change the code according to your requirments
 */
#include <Servo.h>//Using servo library to control ESC   
Servo motor1,motor2;
float angle;//
void setup() {
  motor1.attach(19);//Using nano A0 pin
  delay(0.8);
  //Arming of Drone
  motor1.write(40); 

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.write(angle);

}
