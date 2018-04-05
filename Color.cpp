#include "Color.h"

void Color::begin(byte merror, byte mcolor) {
  merr = merror;
  mcol = mcolor;
  mirror = readIR();

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

byte Color::read(byte data) {
  switch (data) {
    case 0:
      return read();
    case 1:
      return readIR();
    case 2:
      return readColor();
    default:
      return -1;
  }
}

//@return 0 se sotto non c'è niente, 1 se c'è uno specchio e 2 se è nero.
byte Color::read() {
  byte reflection = readIR();
  return (reflection > mirror - merr && reflection < mirror + merr) ? 1 : readColor() < mcol ? 0 : 2;
}

byte Color::readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  return pulseIn(sensorOut, LOW);
}

byte Color::readIR() {
  byte out = analogRead(A0);
  delay(5);
  out += analogRead(A1);
  return out >> 1;
}
