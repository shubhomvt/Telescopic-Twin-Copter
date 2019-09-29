#include <Arduino.h>

class RC {
    byte isr_RC;
    
public:
    RC(byte pin);
    unsigned int Value();
    int begin(bool measure_pulse_high);

    unsigned long timeRC();

    void end();
};
