
//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 5     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
float humDH;  //Stores humidity value
float tempDH; //Stores temperature value

void DHT22setup()
{
  dht.begin();
}

void DHT22read()
{
    //Read data and store it to variables hum and temp
    humDH = dht.readHumidity();
    tempDH= dht.readTemperature();
}
