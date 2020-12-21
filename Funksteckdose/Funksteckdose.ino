/*

A: 000000FFFFF0 -aus
   000000FFFF0F -an

B: 00000F0FFF0F -an
   00000F0FFFF0 -aus

C: 00000FF0FF0F
   00000FF0FFF0

D: 00000FFF0F0F
   00000FFF0FF0
*/

int rc_pin = 3;
int pr_pin = 4;
int seconds = 0;

#include <RCSwitch.h>
RCSwitch sender = RCSwitch();

void setup() {
  Serial.begin(9600);
  sender.enableTransmit(rc_pin);
  sender.setProtocol(1);
  sender.setPulseLength(187);
  pinMode(pr_pin, INPUT);
}

void loop() {
  int val = digitalRead(pr_pin);
  seconds += 1;
  Serial.println(seconds);
  if(val == HIGH){
    Serial.print("Motion detected");
    sender.sendTriState("000000FFFF0F"); //A
    sender.sendTriState("00000F0FFF0F"); //B
    seconds = 0;
  }
  else{
    Serial.println("No Motion");
  }
  if(seconds == 60){
      sender.sendTriState("000000FFFFF0"); //A
      sender.sendTriState("00000F0FFFF0"); //B
  }
  delay(1000);
}
 
