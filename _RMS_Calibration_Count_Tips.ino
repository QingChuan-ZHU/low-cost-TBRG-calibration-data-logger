#include "SSD1306.h"
#include "SD.h"
#include "DHT22.h"

const int buttonPin = 7;
const int TBRGPin = 6;
int buttonState = 0;  
int TBRGState = 0;

int sum = 0;
int t = 0;

#define seconds() (millis()/1000)


void setup() {

  pinMode(buttonPin, INPUT);
  pinMode(TBRGPin,INPUT);
  OLEDsetup();
  DHT22setup();
  SDsetup();
  
}

void loop() {

  TBRGState = digitalRead(TBRGPin);
  buttonState = digitalRead(buttonPin);

    if (TBRGState == HIGH) 
  {
  sum = sum + 1;
  t = t + 1; 
  DHT22read();
  String dataSave =String(sum)+ "," + String(seconds()) + "," + String(humDH) + "," + String(tempDH);
  saveDATAln((dataSave));
  delay(300);
  }

      if (buttonState == HIGH) 
  {
  t = 0; 
  delay(300);
  }


  OLEDlms(String(t) + " , " + String(sum));

  }
