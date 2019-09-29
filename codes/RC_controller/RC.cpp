#include "RC.hpp"


unsigned long timer[20];
unsigned long timeRC[20];
byte pin1[20];
unsigned int valuex[20];
bool prev_value[20];
bool trigger_value[20];
byte count = 0;


void ISR_generic(byte isr1) {
    unsigned long now = micros();
    bool state_now = digitalRead(pin1[isr1]);
    if (state_now != prev_value[isr1]) {
        if (state_now == trigger_value[isr1]) {
            timer[isr1] = now;
        } else {
            valuex[isr1] = (unsigned int)(now - timer[isr1]);
            timeRC[isr1] = now;
        }
        prev_value[isr1] = state_now;
    }
}

void ISR_0() {
    ISR_generic(0);
}

void ISR_1() {
    ISR_generic(1);
}

void ISR_2() {
    ISR_generic(2);
}

void ISR_3() {
    ISR_generic(3);
}

void ISR_4() {
    ISR_generic(4);
}

void ISR_5() {
    ISR_generic(5);
}

void ISR_6() {
    ISR_generic(6);
}

void ISR_7() {
    ISR_generic(7);
}

void ISR_8() {
    ISR_generic(8);
}

void ISR_9() {
    ISR_generic(9);
}

void ISR_10() {
    ISR_generic(10);
}

void ISR_11() {
    ISR_generic(11);
}

void ISR_12() {
    ISR_generic(12);
}

void ISR_13() {
    ISR_generic(13);
}

void ISR_14() {
    ISR_generic(14);
}

void ISR_15() {
    ISR_generic(15);
}

void ISR_16() {
    ISR_generic(16);
}

void ISR_17() {
    ISR_generic(17);
}

void ISR_18() {
    ISR_generic(18);
}

void ISR_19() {
    ISR_generic(19);
}

RC::RC(byte pin) {
    isr_RC = count;
    count++;
    
    pin1[isr_RC] = pin;
    pinMode(pin1[isr_RC], INPUT);
}

int RC::begin(bool measure_pulse_high) {
    prev_value[isr_RC] = digitalRead(pin1[isr_RC]);
    trigger_value[isr_RC] = measure_pulse_high;
    
    switch (isr_RC) {
        case 0:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_0, CHANGE);
            break;
        case 1:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_1, CHANGE);
            break;
        case 2:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_2, CHANGE);
            break;
        case 3:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_3, CHANGE);
            break;
        case 4:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_4, CHANGE);
            break;
        case 5:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_5, CHANGE);
            break;
        case 6:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_6, CHANGE);
            break;
        case 7:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_7, CHANGE);
            break;
        case 8:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_8, CHANGE);
            break;
        case 9:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_9, CHANGE);
            break;
        case 10:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_10, CHANGE);
            break;
        case 11:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_11, CHANGE);
            break;
        case 12:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_12, CHANGE);
            break;
        case 13:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_13, CHANGE);
            break;
        case 14:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_14, CHANGE);
            break;
        case 15:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_15, CHANGE);
            break;
        case 16:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_16, CHANGE);
            break;
        case 17:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_17, CHANGE);
            break;
        case 18:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_18, CHANGE);
            break;
        case 19:
            attachInterrupt(digitalPinToInterrupt(pin1[isr_RC]), ISR_19, CHANGE);
            break;
        default:
            return -1; // Error.
    }
    return 0; // Success.
}

unsigned int RC::Value() {
    return valuex[isr_RC];
}

void RC::end() {
    detachInterrupt(digitalPinToInterrupt(pin1[isr_RC]));
}

