#include "MPU6050_tockn.h"
#include "Arduino.h"

BIMU::BIMU(TwoWire &w){
  wire = &w;
  gCoeff = 0.98f;
  aCoeff = 0.02f; 
}

BIMU::BIMU(TwoWire &w, float Acc_Coefficient, float gC){
  wire = &w;
  gyroCoef = Gyro_Coefficient;
  accCoef = Acc_Coefficient;
  
}

void BIMU::begin(){
  BIMU_write(IMU_GYRO, 0x08);
  BIMU_write(IMU_ACCEL, 0x00);
  BIMU_write(IMU_SMPLRT_DIV, 0x00);
  BIMU_write(IMU_CONFIG, 0x00);
  BIMU_write(IMU_PWR, 0x01);
  this->update();
  angleGyroX = 0;
  angleGyroY = 0;
  angleX = this->AccAngleX();
  angleY = this->AccAngleY();
  preInterval = millis();
}

void BIMU::BIMU_write(byte addr, byte data){
  wire->beginTransmission(IMU_ADDRESS_1);
  wire->write(addr);
  wire->write(data);
  wire->endTransmission();
}

byte BIMU::BIMU_read(byte addr) {
  wire->beginTransmission(IMU_ADDRESS_1);
  wire->write(addr);
  wire->endTransmission(true);
  wire->requestFrom(IMU_ADDRESS_1, 1);
  byte data =  wire->read();
  return data;
}

void BIMU::GyroOffsets(float gyro_x, float gyro_y, float gyro_z){
  offset_gyroX = gyro_x;
  offset_gyroY = gyro_y;
  offset_gyroZ = gyro_z;
}

void BIMU::calcGyroOffsets(bool console, uint16_t delayBefore, uint16_t delayAfter){
  float x = 0, y = 0, z = 0;
  int16_t rx, ry, rz;

  delay(delayBefore);
  if(console){
    Serial.println();
    Serial.println("========================================");
    Serial.println("Calculating gyro offsets");
    Serial.print("DO NOT MOVE BIMU");
  }
  for(int i = 0; i < 3000; i++){
    if(console && i % 1000 == 0){
      Serial.print(".");
    }
    wire->beginTransmission(IMU_ADDRESS_1);
    wire->write(0x43);
    wire->endTransmission(false);
    wire->requestFrom((int)IMU_ADDRESS_1, 6);

    rx = wire->read() << 8 | wire->read();
    ry = wire->read() << 8 | wire->read();
    rz = wire->read() << 8 | wire->read();

    x += ((float)rx) / 65.5;
    y += ((float)ry) / 65.5;
    z += ((float)rz) / 65.5;
  }
  offset_gyroX = x / 3000;
  offset_gyroY = y / 3000;
  offset_gyroZ = z / 3000;

  if(console){
    Serial.println();
    Serial.println("Finished Bitches!!!!!!!");
    Serial.print("X : ");Serial.println(offset_gyroX);
    Serial.print("Y : ");Serial.println(offset_gyroY);
    Serial.print("Z : ");Serial.println(offset_gyroZ);
    Serial.println("Nigga,Program will start after 3 seconds so stfu and wait");
    Serial.print("========================================");
    delay(delayAfter);
  }
}

void BIMU::update(){
  wire->beginTransmission(IMU_ADDRESS_1);
  wire->write(0x3B);
  wire->endTransmission(false);
  wire->requestFrom((int)IMU_ADDRESS_1, 14);

  AccX = wire->read() << 8 | wire->read();
  AccY = wire->read() << 8 | wire->read();
  AccZ = wire->read() << 8 | wire->read();
  Temp = wire->read() << 8 | wire->read();
  GyroX = wire->read() << 8 | wire->read();
  GyroY = wire->read() << 8 | wire->read();
  GyroZ = wire->read() << 8 | wire->read();

  temp = (Temp + 12412.0) / 340.0;

  accX = ((float)AccX) / 16384.0;
  accY = ((float)AccY) / 16384.0;
  accZ = ((float)AccZ) / 16384.0;

  angleAccX = atan2(accY, sqrt(accZ * accZ + accX * accX)) * 360 / 2.0 / PI;
  angleAccY = atan2(accX, sqrt(accZ * accZ + accY * accY)) * 360 / -2.0 / PI;

  gyroX = ((float)rawGyroX) / 65.5;
  gyroY = ((float)rawGyroY) / 65.5;
  gyroZ = ((float)rawGyroZ) / 65.5;

  gyroX -= offset_gyroX;
  gyroY -= offset_gyroY;
  gyroZ -= offset_gyroZ;

  interval = (millis() - preInterval) * 0.001;

  angleGyroX += gyroX * interval;
  angleGyroY += gyroY * interval;
  angleGyroZ += gyroZ * interval;

  angleX = (gCoeff * (angleX + gyroX * interval)) + (aCoeff * angleAccX);
  angleY = (gCoeff * (angleY + gyroY * interval)) + (aCoeff * angleAccY);
  angleZ = angleGyroZ;

  preInterval = millis();

}
