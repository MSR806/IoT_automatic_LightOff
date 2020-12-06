#ifndef HC_SR04_H
#define HC_SR04_H
#include "arduino.h"

class HC_SR04 {

    //private variables can be accessed by only class functions
    private:
        int _trigPin;
        int _echoPin;
        long _sensorValue;
        int _threshold;

    public:
        HC_SR04(int trigPin, int echoPin);
        void begin();
        void read();
        void set_threshold(int threshold);
        bool if_crossed();
        long sensor_value();
};



#endif