#include <SPI.h>

int dataPin = 11;
int clockPin = 13;
int lachPin = 8;

byte bt[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(lachPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  
  digitalWrite(lachPin, LOW);
  for(int i=0;i<8;i++)
  {
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
  }  
  digitalWrite(lachPin, HIGH);
}

void writeByte(byte * value)
{
  
}


void loop()
{
  digitalWrite(lachPin, LOW);
  for(int i=7;i>=0;i--)
    shiftOut(dataPin, clockPin, LSBFIRST, bt[i]);
  digitalWrite(lachPin, HIGH);
}
