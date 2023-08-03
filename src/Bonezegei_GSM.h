/*
  This Library is written for GSM
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/
#ifndef _BONEZEGEI_GSM_H_
#define _BONEZEGEI_GSM_H_
#include <Arduino.h>

class Bonezegei_GSM {
public:

  Bonezegei_GSM();
  Bonezegei_GSM(const HardwareSerial& se);

  void begin();
  void begin(int baud);
  void sendMessage(const char *number,const char* message);

private:
  HardwareSerial *s;
};


#endif

