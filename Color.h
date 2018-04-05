#ifndef Color_h
#define Color_h

#include <Arduino.h>

#define S0 13
#define S1 12
#define S2 11
#define S3 10
#define sensorOut 17

class Color {
public:
  void begin(byte merror, byte mcolor);
  byte read(byte data);
  byte read();
  byte readIR();
  byte readColor();
private:
  byte mirror;
  byte merr;
  byte mcol;
};

#endif
