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


RF24 radio(PA0, PA1); // CE, CSN
RF24 radio2(PA2, PA3);
RF24 radio3(PB0, PB1);

void setup() {
  pinMode(PC13, OUTPUT);
  radio.begin();
  radio2.begin();
  radio3.begin();
  radio.powerDown();
  radio2.powerDown();
  radio3.powerDown();
  delay(1000);
  digitalWrite(PC13, LOW);

  radio.powerUp();
  radio.setAutoAck(false);  // Very important setting
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();
  radio.setChannel(80);
  delay(1000);

  radio2.powerUp();
  radio2.setAutoAck(false);
  radio2.setPALevel(RF24_PA_HIGH);
  radio2.setDataRate(RF24_2MBPS);
  radio2.stopListening();
  radio2.setChannel(26);
  delay(1000);

  radio3.powerUp();
  radio3.setAutoAck(false);
  radio3.setPALevel(RF24_PA_HIGH);
  radio3.setDataRate(RF24_2MBPS);
  radio3.stopListening();
  radio3.setChannel(2);
  delay(1000);

  digitalWrite(PC13, HIGH);
}


void loop() {
  byte text = 255; //just some random string
  radio.writeFast(&text, sizeof(text));
  radio3.writeFast(&text, sizeof(text));
  radio2.writeFast(&text, sizeof(text));
}
