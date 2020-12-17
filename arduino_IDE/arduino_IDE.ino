#include "HC_SR04.h"

HC_SR04 outside(12, 13);
HC_SR04 inside(7, 6);
int ledPin = 5;

bool inside_activated = false;
bool inside_update = false;
bool outside_activated = false;
bool outside_update = false;

long lastActive_outside = 0;
long lastActive_inside = 0;
long lastprint = 0;
int count = 0;
int last_count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  outside.begin();
  inside.begin();
  pinMode(ledPin, OUTPUT);
  Serial.print("Number of people = ");
  Serial.println(count);
}

void loop() {
  
  //reads Sensor Data
  outside.read();
  inside.read();

  
  outside.set_threshold(3900);
  inside.set_threshold(3900);
  
  /* Check if sensor_value is less than threshold
   and if yes then sets activated variable to true for 1.5s */
  long now = millis();

  //for outside sensor
  if (outside.if_crossed()){
    outside_activated = true;
    outside_update = true;
    lastActive_outside = now;
  }
  else if (now - lastActive_outside > 1500){
    outside_activated = false;
  }

  //for inside sensor
  if (inside.if_crossed()){
    inside_activated = true;
    inside_update = true;
    lastActive_inside = now;
  }
  else if(now - lastActive_inside > 1500){
    inside_activated = false;
  }

  //if the sensor is in a activated state then do this
  if (outside_activated && lastActive_inside - lastActive_outside > 0 && inside_update && outside_update){
    if(inside_activated){
      count ++;
      inside_update = false;
      outside_update = false;

    }
  }

  if (inside_activated && lastActive_outside -lastActive_inside > 0 && inside_update && outside_update){
    if(outside_activated){
      count --;
      inside_update = false;
      outside_update = false;
    }
  }
  
  if(count >0){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }


  // Printing Stuff
  if(count < 0){
    count = 0;
  }
  if(count != last_count){
    if(count == 0){
      Serial.println("Lights OFF");
    }
    else if(last_count == 0 && count >0){
    Serial.println("Lights ON");
    }
    
    Serial.print("Number of people = ");
    Serial.println(count);
    last_count = count;
  }
  
}