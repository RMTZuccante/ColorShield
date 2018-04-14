#include "Color.h"
#include <Wire.h>

#define COLORADDRESS 0x42

Color color;
byte read;

void requestEvent() {
  byte col = color.read(read);
  Wire.write(col);
  read = 255;
}

void receiveEvent() {
  byte x = Wire.read();
  if(x>=10) color.begin(x-10, Wire.read());  
  else read = x;
}

void setup() {
  read = 255;
  Wire.begin(COLORADDRESS);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  
}
