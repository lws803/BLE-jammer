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


RF24 radio(PC14, PA3); // CE, CSN
RF24 radio2(PA0, PA1);
RF24 radio3(PA2, PB0);

void setup() {
  pinMode(D33, OUTPUT);
  digitalWrite(D33, HIGH);

  radio.begin();
  radio.setAutoAck(false);  // Very important setting
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();
  radio.setChannel(80);
  delay(1000);

  radio2.begin();
  radio2.setAutoAck(false);
  radio2.setPALevel(RF24_PA_HIGH);
  radio2.setDataRate(RF24_2MBPS);
  radio2.stopListening();
  radio2.setChannel(26);
  delay(1000);

  radio3.begin();
  radio3.setAutoAck(false);
  radio3.setPALevel(RF24_PA_HIGH);
  radio3.setDataRate(RF24_2MBPS);
  radio3.stopListening();
  radio3.setChannel(2);
  delay(1000);

  digitalWrite(D33, LOW);
}


void loop() {
  byte text = 255; //just some random string
  radio.writeFast(&text, sizeof(text));
  radio3.writeFast(&text, sizeof(text));
  radio2.writeFast(&text, sizeof(text));
}
