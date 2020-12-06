#include "HC_SR04.h"

HC_SR04 outside(12, 13);
HC_SR04 inside(7, 6);

long outside_read, inside_read;
int count = 0;

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
  
  outside_read = 1000;
  inside_read = 10000;

  if (outside.if_crossed()){
    outside_read = millis();
    Serial.println("outside");
  }
  if (inside.if_crossed()){
    inside_read = millis();
    Serial.println("Inside");
  }

  if ((outside_read - inside_read) < 1000 && (outside_read - inside_read) > 0){
    Serial.println("Exited the room");
    count --;
    Serial.println(count);
  }

  if ((inside_read - outside_read) < 1000 && (inside_read - outside_read) > 0){
    Serial.println("Entered the room");
    count ++;
    Serial.println(count);
  }
}