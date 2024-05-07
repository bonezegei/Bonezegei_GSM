/*
  This Library is written for GSM
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
  Lats Update: May 7,2024
*/
#ifndef _BONEZEGEI_GSM_H_
#define _BONEZEGEI_GSM_H_
#include <Arduino.h>
#include <Bonezegei_SoftSerial.h>

class Bonezegei_GSM {
public:

  Bonezegei_GSM();
  Bonezegei_GSM(const HardwareSerial& se);
  Bonezegei_GSM(Bonezegei_SoftSerial& serial);

  void begin();
  void begin(int baud);
  void sendMessage(const char *number,const char* message);

private:
  HardwareSerial *s;
  Bonezegei_SoftSerial* softserial;
  uint8_t ser;  //serial selected 0 for hardware serial and 1 for softserial
};


#endif

