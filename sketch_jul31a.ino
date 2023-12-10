#include <IRremote.hpp>


IRrecv IR(2);
int led1 =11;
int led2 =10;
int led3 =9;
int led4 =8;
int relay = 13;

void inverter (long x,int y){
if(IR.decodedIRData.decodedRawData==x)
{switch(digitalRead(y)){
  case HIGH:
  digitalWrite(y,LOW);
  break;
  case LOW:
  digitalWrite(y,HIGH);
  break;
}}
}

void setup() {
  // put your setup code here, to run once:
IR.enableIRIn();

Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(IR.decode())
{
Serial.println(IR.decodedIRData.decodedRawData,HEX);

inverter(0xBC43FF00,led1);
inverter(0xB946F30CFF00,led2);
inverter(0xE718FF00,led3);
inverter(0xA15EFF00,led4);
inverter(0xB946FF00,relay);





delay(100);
IR.resume();
}}
