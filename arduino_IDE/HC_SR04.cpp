#include "HC_SR04.h"

HC_SR04::HC_SR04(int trigPin, int echoPin){
    _trigPin = trigPin;
    _echoPin = echoPin;
}

void HC_SR04::begin(){
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

void HC_SR04::read_senseVal(){
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    _senseVal = pulseIn(_echoPin, HIGH);
}

void HC_SR04::print_senseVal(){
    Serial.println(_senseVal);
    delay(500);
}

//HC_SR04::check(){

//}
