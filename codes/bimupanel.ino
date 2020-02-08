#include <Wire.h>
#include <Servo.h>
#include <MPU6050_tockn.h>
MPU6050 imu(Wire);
Servo lmotor,rmotor;
float Kp[]={0,0,0,0};
float Ki[]={0,0,0,0};
float Kd[]={0,0,0,0};
float maxspeed[]={2000,2000,2000};
float minspeed[]={1000,1000,1000};
float error[]={0,0,0};
float error_sum[]={0,0,0};
float error_diff[]={0,0,0};
float sampletime,prevtime,prestime,diffrtime;
float desiredangle[]={};
float preverror[]={0,0,0,0};
long timer = 0;
float throttle1,throttle2;
float b[3]={0,0,0};
float Angle[3]={0,0,0};
float out[3]={0,0,0};
int fla=0,i;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  imu.begin();
  imu.calcGyroOffsets(true);
  lmotor.attach(2);
  lmotor.writeMicroseconds(1000);
  rmotor.attach(4);
  rmotor.writeMicroseconds(1000);
  //Serial.println("hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("hello");
  imu.update();
  prevtime = prestime;
  prestime=millis();
  if(fla==0){
    //a[3]={imu.getAngleX(),imu.getAngleY(),getAngleZ()};
     for(int i=0;i<20;i++){
      b[0]+=imu.getAngleX();
      b[1]+=imu.getAngleY();
      b[2]+=imu.getAngleZ();
    }
    b[0]=b[0]/20;
    b[1]=b[1]/20;
    b[2]=b[2]/20;
    fla=1;
    
  }
  diffrtime=(prestime-prevtime)/1000;
  //float corr[3]={imu.getAngleX(),0,0};
  
   if(millis() - timer > 1000){
     for(int i=0;i<3;i++){
       Angle[i]=0;
       //delay(1000);
       //Serial.println(Angle[i]);
       //Serial.println(" ----------------- ");
      }
     for(int i=0;i<20;i++){
        Angle[0]+=imu.getAngleX();
        Angle[1]+=imu.getAngleY();
        Angle[2]+=imu.getAngleZ();
       }
       Angle[0]/=20;
       Angle[1]/=20;
       Angle[2]/=20;
      for(int i=0;i<3;i++){
       Angle[i]=(Angle[i])-b[i];
       //delay(1000);
       //Serial.println(Angle[i]);
       //Serial.println(" ----------------- ");
      }
     /* for(i=0;i<3;i++){
      error[i]= Angle[i]- desiredangle[i];
      error_diff[i]= ((error[i]-preverror[i])/sampletime);
      error_sum[i]+= error[i]*sampletime;
      preverror[i]=error[i];
      out[i]= (Kp[i]*error[i])+(Ki[i]*error_sum[i])+(Kd[i]*error_diff[i]);
      }
      throttle1=1500+out[0];
      throttle2=1500-out[0];
      
      
      if(throttle1>maxspeed[0]){
        throttle1=maxspeed[0];
      }
      if(throttle1<minspeed[0]){
        throttle1=minspeed[0];
      }
      if(throttle2>maxspeed[0]){
        throttle2=maxspeed[0];
      }
      if(throttle2<minspeed[0]){
        throttle2=minspeed[0];
      }
      lmotor.writeMicroseconds(throttle1);
      rmotor.writeMicroseconds(throttle2);
      */
      
      
      
      
   

    Serial.println(Angle[1]);
    delay(800);
    //Serial.println(imu.getAngleX());

 }


}
