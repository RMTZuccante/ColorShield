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
  void begin(uint8_t merror, uint8_t mcolor);
  uint8_t read(uint8_t data);
  uint8_t read();
  uint16_t readIR();
  uint8_t readColor();
private:
  uint16_t mirror;
  uint8_t merr;
  uint8_t mcol;
};

#endif
