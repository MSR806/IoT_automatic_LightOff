#include "HC_SR04.h"

HC_SR04::HC_SR04(int trigPin, int echoPin){
    _trigPin = trigPin;
    _echoPin = echoPin;
}

void HC_SR04::begin(){
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

void HC_SR04::read(){
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    _sensorValue = pulseIn(_echoPin, HIGH);
}

void HC_SR04::set_threshold(int threshold){
    _threshold = threshold;
}

bool HC_SR04::if_crossed(){
    if (_sensorValue < _threshold)
        return true;
    else
        return false;
}
long HC_SR04::sensor_value(){
    return _sensorValue;
}
 