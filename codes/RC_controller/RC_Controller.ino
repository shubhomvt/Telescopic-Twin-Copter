#include "RC.hpp"
RC ch1(2); // Setup pin 2 for input
RC ch2(3); // Setup pin 3 for input
RC ch3(18); // Setup pin 18 for input
RC ch4(19); // Setup pin 19 for input
RC ch5(20); // Setup pin 20 for input
RC ch6(21); // Setup pin 21 for input

void setup() {
    Serial.begin(9600); // Serial for debug
    ch1.begin(true); // ch1 on pin 2 reading RC HIGH duration
    ch2.begin(true); // ch2 on pin 3 reading RC HIGH duration
    ch3.begin(true); // ch3 on pin 18 reading RC HIGH duration
    ch4.begin(true); // ch4 on pin 19 reading RC HIGH duration
    ch5.begin(true); // ch5 on pin 20 reading RC HIGH duration
    ch6.begin(true); // ch6 on pin 21 reading RC HIGH duration
}

void loop() {
   Serial.print("THROTTLE BITCHES!!!! \n");
   Serial.print(ch1.Value());
   Serial.print("\t \n"); 
    /*Serial.print(ch2.getValue());
    Serial.print("\t");
    Serial.print(ch3.getValue());
    Serial.print("\t");
    Serial.print(ch4.getValue());
    Serial.print("\t");
    Serial.print(ch5.getValue());
    Serial.print("\t");
    Serial.print(ch6.getValue());
    Serial.print("\t");
    Serial.println();*/
    delay(100);
}
