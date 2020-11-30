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
  Serial.println("Inside");
  outside.read_senseVal();
  outside.print_senseVal();
  Serial.println("Outside");
  inside.read_senseVal();
  inside.print_senseVal();
  Serial.println("------------------------------------------------");
}
