#include "Color.h"
#include <Wire.h>

#define COLORADDRESS 0x42

Color color;
byte read;

void requestEvent() {
  Wire.write(color.read(read));
  read = -1;
}

void receiveEvent() {
  byte x = Wire.read();
  if(x>=10) color.begin(x-10, Wire.read());  
  else read = x;
}

void setup() {
  read = -1;
  Wire.begin(COLORADDRESS);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {

}
