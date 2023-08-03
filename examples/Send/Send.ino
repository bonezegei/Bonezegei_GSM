/*
  Simple send Message
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include <Bonezegei_GSM.h>
Bonezegei_GSM gsm(Serial);

void setup() {
  gsm.begin(9600);

  //param 1 mobile number in string form
  //param 2 message
  gsm.sendMessage("00000000","Hello SMS");
}

void loop() {
  // put your main code here, to run repeatedly:

}
