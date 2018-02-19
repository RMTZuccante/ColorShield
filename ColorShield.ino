#include "Color.h"
#include <Wire.h>

#define COLORADDRESS 42

Color color;

void setup() {
  Wire.begin(COLORADDRESS);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(100);
}

void requestEvent() {
  byte x = color.read();
  Wire.write(x);
}

void receiveEvent() {
  byte x = Wire.read();
  if(x>=10) color.begin(x-10);
}