#ifndef BIMU
#define BIMU
#include "Wire.h"
#include "Arduino.h"

#define IMU_PWR        0x6B
#define IMU_ACCEL      0x1C
#define IMU_GYRO       0x1B
#define IMU_HIGH_TEMP  0x42
#define IMU_HIGH_TEMP  0x41
#define IMU_ADDRESS_1  0x68
#define IMU_ADDRESS_2  0x69 //it depends on AD0 pin whether it is HIGH or LOW 
#define IMU_SMPLRT_DIV 0x19
#define IMU_CONFIG     0x1A





class BIMU{
  private:

  TwoWire *wire;

  int16_t AccX, AccY, AccZ, Temp, GyroX,GyroY,GyroZ;

  float offset_gyroX, offset_gyroY, offset_gyroZ;

  float temp, accX, accY, accZ, gyroX, gyroY, gyroZ;

  float angleGyroX, angleGyroY, angleGyroZ,angleAccX, angleAccY, angleAccZ;

  float angleX, angleY, angleZ;

  float interval;
  long preInterval;

  float aCoeff, gCoeff;

  public:
  BIMU(TwoWire &w, float Acc_Coefficient, float Gyro_Coefficient);
  

  void begin();

  void GyroOffsets(float gyro_x, float gyro_y, float gyro_z);

  void BIMU_write(byte addr, byte data);
  byte BIMU_read(byte addr);

  void calcGyroOffsets(bool console = false, uint16_t delayBefore = 1000, uint16_t delayAfter = 3000);
  BIMU(TwoWire &w);
  int16_t rawGyroX()
  {
   return GyroX;
  };

  int16_t rawGyroy(){
  return GyroY;
  };

  int16_t rawGyroz(){
  return GyroZ;
  };

  int16_t rawAccX()
  { 
   return AccX;
  };

  int16_t rawAccY(){
  return AccY;
  };

  int16_t rawAccZ(){
  return AccZ;
  };

  float aGyroX(){
  return gyroX;
  };

  float aGyroY(){
  return gyroY;
  };

  float aGyroZ(){
  return gyroZ;
  };

  float aAccX(){
  return accX;
  };

  float aAccY(){
  return accY;
  };
 
  float aAccZ(){
  return accZ;
  };

  float GyroXoffset(){
  return offset_gyroX;
  };
 
  float GyroYoffset(){
  return offset_gyroY;
  };
 
  float GyroZoffset(){
  return offset_gyroZ;
  };

  int16_t rawTemp(){
   return Temp;
  };

  float getTemp(){
  return temp;
  };

  float GyroAngleX(){
  return angleGyroX;
  };

  float GyroAngleY(){
  return angleGyroY;
  };

  float GyroAngleZ(){
  return angleGyroZ;
  };

  float AccAngleX(){
  return angleAccX;
  };

  float AccAngleY(){
  return angleAccY;
  };
  float AccAnglez(){
  return angleAccZ;
  };

  float AngleX(){
  return angleX;
  };

  float AngleY(){
  return angleY;
  };

  float AngleZ(){
  return angleZ;
  };

  void update();


};
#endif
