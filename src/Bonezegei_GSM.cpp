/*
  This Library is written for GSM
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include "Bonezegei_GSM.h"

Bonezegei_GSM::Bonezegei_GSM() {
}

Bonezegei_GSM::Bonezegei_GSM(const HardwareSerial& se) {
  s = (HardwareSerial*)&se;
}

void Bonezegei_GSM::begin() {
  s->begin(9600);
}

void Bonezegei_GSM::begin(int baud) {
  s->begin(baud);
}

void Bonezegei_GSM::sendMessage(const char *number,const char* message) {
  s->println("AT+CMGF=1");
  delay(1000);
  s->print("AT+CMGS=\"");
  s->print(number);
  s->println("\"");
  delay(800);
  s->println(message);
  delay(500);
  s->println((char)26);
  delay(5000);
}
