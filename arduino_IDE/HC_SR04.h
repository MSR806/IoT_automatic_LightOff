#ifndef HC_SR04_H
#define HC_SR04_H
#include "arduino.h"

class HC_SR04 {

    //private variables can be accessed by only class functions
    private:
        int _trigPin;
        int _echoPin;
        long _senseVal;

    public:
        HC_SR04(int trigPin, int echoPin);
        void begin();
        void read_senseVal();
        void print_senseVal();
        //bool check();
};



#endif