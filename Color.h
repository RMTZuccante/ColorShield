#ifndef Color_h
#define Color_h

#include <Arduino.h>

#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 12

class Color {
public:
  void begin(byte merror);
  byte read();
private:
  unsigned short readIR();
  unsigned short mirror;
  byte merr;
};

#endif
