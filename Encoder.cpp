/*
 * Encoder.cpp
 *
 *  Created on: Sep 4, 2022
 *  Author: shahjesal15, pheonix17, shubh_gajjar07
 */

#include "Encoder.h"

Sensors::Encoder::Encoder(byte inA, byte inB) {
  this->inA = inA;
  this->inB = inB;
}

void Sensors::Encoder::write(long counts) {
  encoderValue = counts;
}

long Sensors::Encoder::read() {
  return encoderValue;
}

void Sensors::Encoder::update() {
  MSB = digitalRead(inA) ? 1 : 0;
  LSB = digitalRead(inB) ? 1 : 0;
  encoded = (MSB << 1) | LSB;
  sum = (lastEncoded << 2) | encoded;
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue--;
  lastEncoded = encoded;
}
