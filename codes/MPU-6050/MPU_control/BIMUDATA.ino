
#include <BIMU.h>
#include <Wire.h>

BIMU imu(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  imu.begin();
  imu.calcGyroOffsets(true);
}

void loop() {
  imu.update();

  if(millis() - timer > 1000){
    
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(imu.getTemp());
    Serial.print("accX : ");Serial.print(imu.aAccX());
    Serial.print("\taccY : ");Serial.print(imu.aAccY());
    Serial.print("\taccZ : ");Serial.println(imu.aAccZ());
  
    Serial.print("gyroX : ");Serial.print(imu.aGyroX());
    Serial.print("\tgyroY : ");Serial.print(imu.aGyroY());
    Serial.print("\tgyroZ : ");Serial.println(imu.aGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(imu.AccAngleX());
    Serial.print("\taccAngleY : ");Serial.println(imu.AccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(imu.GyroAngleX());
    Serial.print("\tgyroAngleY : ");Serial.print(imu.GyroAngleY());
    Serial.print("\tgyroAngleZ : ");Serial.println(imu.GyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(imu.AngleX());
    Serial.print("\tangleY : ");Serial.print(imu.AngleY());
    Serial.print("\tangleZ : ");Serial.println(imu.AngleZ());
    Serial.println("=======================================================\n");
    timer = millis();
    
  }

}
