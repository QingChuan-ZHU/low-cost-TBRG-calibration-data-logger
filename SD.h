#include <SPI.h>
#include <SD.h>

const char* SAVE_DATA_FILE_NAME = "DATA.CSV";
String DATA_Header = "Tips number, Seconds of every tip after system begin, Air humidity, Air Temperauture";
File SaveDATA;


const int chipSelect = 4;

void SDsetup(){

 //   SD.begin(chipSelect);
  
   if (SD.begin(chipSelect)) {
     OLEDlms(" SD OK ");  
     delay(1000);
  }
  else{
     while(1)
   {   OLEDlms(" SD Failed ");  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second}
  }
}
}

void saveDATAln(String data) {

    SaveDATA = SD.open(SAVE_DATA_FILE_NAME, FILE_WRITE);
    
  if (SaveDATA.size() == 0){    
        SaveDATA.println(DATA_Header);
        SaveDATA.flush();
     }

  if (SaveDATA) {
    SaveDATA.println(data);
    SaveDATA.close();
  }    
  else
  {
    while(1)
  {
   OLEDlms(" Save Failed ");  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
    }
    }
}
