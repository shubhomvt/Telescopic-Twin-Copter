
/*ESC calibration sketch for bicopter
   I am using arduino nano
   Sinal pin is connected to pin A0
*/
#include <Servo.h>
#define minvalue 1000
#define maxvalue 2000
#define motor1_pin A0
int time1 = 1000;
Servo motor1;
void setup() {
  Serial.begin(9600);
  Serial.println("Program will test the ESC.");
  Serial.print("\n");
  motor1.attach(motor1_pin);
  Serial.println("Connect the Battery and wait for few seconds ");
  Serial.print("\n");
  Serial.println("Press Any key \n ");
  motor1.writeMicroseconds(maxvalue);
  //Read the inputs
  while (!Serial.available());
  Serial.read();
  Serial.print("Sending maximum value to calibrate :");
  Serial.print("\n");
  Serial.print(maxvalue);
  Serial.print("Sending minimum value to calibrate )");
  Serial.print("\n");
  motor1.writeMicroseconds(minvalue);
  Serial.println("Finally ESC is calibrated");
  Serial.println("*************************");
  Serial.println("Enter between 1000 and 2000 ");
  Serial.print("\n");
  Serial.println("The motor would rotate");
  Serial.print("\n");
  Serial.println("Send 1000 to stop the motor and 2000 for full speed");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    int time1 = Serial.parseInt();
    if (time1 > 999)
    {

      motor1.writeMicroseconds(time1);
      float speed_motor1 = (time1 - 1000) / 10;
      Serial.print("\n");
      Serial.println("Motor speed:"); Serial.print("  "); Serial.print(speed_motor1);
    }
  }

}
