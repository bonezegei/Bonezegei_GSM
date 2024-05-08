/*
  This Library is written for GSM
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
  Updated May 2024
*/

#include "Bonezegei_GSM.h"

Bonezegei_GSM::Bonezegei_GSM() {
}

Bonezegei_GSM::Bonezegei_GSM(const HardwareSerial& se) {
  ser = 0;
  s = (HardwareSerial*)&se;
}

Bonezegei_GSM::Bonezegei_GSM(Bonezegei_SoftSerial& serial) {
  ser = 1;
  softserial = (Bonezegei_SoftSerial*)&serial;
}

void Bonezegei_GSM::begin() {
  if(ser==1){
    softserial->begin(9600);
  }
  else{
    s->begin(9600);
  }
}

void Bonezegei_GSM::begin(int baud) {
  if(ser==1){
    softserial->begin(baud);
  }
  else{
    s->begin(baud);
  }
}

void Bonezegei_GSM::sendMessage(const char *number,const char* message) {
  if(ser==1){
    softserial->println("AT+CMGF=1");
    delay(1000);
    softserial->print("AT+CMGS=\"");
    softserial->print(number);
    softserial->println("\"");
    delay(800);
    softserial->println(message);
    delay(500);
    softserial->println((char)26);
    delay(5000);      
  }
  else{
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

}
