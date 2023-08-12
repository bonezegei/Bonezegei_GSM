/*
  Simple send Message with Debug for AT commands
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  Serail0 will provide the output for debuggin
  While serial1 will control the GSM
*/


#include <Bonezegei_GSM.h>
Bonezegei_GSM gsm(Serial1);

void setup() {
  gsm.begin(9600);

  Serial.begin(9600);

  //param 1 mobile number in string form
  //param 2 message
  gsm.sendMessage("00000000","Hello SMS");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }

   if (Serial.available()) {
    Serial1.write(Serial.read());
  }
}
