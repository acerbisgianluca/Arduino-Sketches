#include <DHT.h> //you need to import the zip which is in the same folder of this sketch

String t; //temperature
String h; //humiduty

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup ()
{
  Serial.begin(9600);
  delay(1000);
}

void loop ()
{
  t = String(dht.readTemperature());
  h = String (dht.readHumidity());
  Serial.println(t + "\t" + h);
  delay(1000);
}
