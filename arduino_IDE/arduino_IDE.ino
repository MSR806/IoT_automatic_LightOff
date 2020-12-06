#include "HC_SR04.h"

HC_SR04 outside(12, 13);
HC_SR04 inside(7, 6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  outside.begin();
  inside.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  outside.read();
  inside.read();
  outside.set_threshold(3900);
  inside.set_threshold(3900);
  before_while = mills();
  while (outside.if_crossed())
  { 
    
    if(inside.if_crossed())
    {
      Serial.println("Entered room");
    }
  }

  if (inside.if_crossed())
  {
    delay(200);
    if(outside.if_crossed())
    {
      Serial.println("Left room");
    }
  }
}
