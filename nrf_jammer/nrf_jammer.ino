/*
* Arduino nRF24L01 Noise Gen
*                
* by Wilson
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(PC14, PC13); // CE, CSN
RF24 radio2(PA0, PA1);
RF24 radio3(PA2, PA3);

void setup() {
  pinMode(D33, OUTPUT);

  radio.begin();
  radio.setAutoAck(false);  // Very important setting
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();

  delay(1000);
  radio2.begin();
  radio2.setAutoAck(false);
  radio2.setPALevel(RF24_PA_HIGH);
  radio2.setDataRate(RF24_2MBPS);
  radio2.stopListening();
  delay(1000);

  radio3.begin();
  radio3.setAutoAck(false);
  radio3.setPALevel(RF24_PA_HIGH);
  radio3.setDataRate(RF24_2MBPS);
  radio3.stopListening();
  delay(1000);

  digitalWrite(D33, HIGH);
}


void loop() {
  const char text[] = "x"; //just some random string
  radio.setChannel(80);
  radio.writeFast(&text, sizeof(text));
  radio3.setChannel(2);
  radio3.writeFast(&text, sizeof(text));
  radio2.setChannel(26);
  radio2.writeFast(&text, sizeof(text));
}
