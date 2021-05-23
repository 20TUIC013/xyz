# xyz
basic 
#include <SPI.h>
#include <LoRa.h>
#include "DHT.h"
#define DHTPIN A0
void setup() {   
  Serial.begin(9600);
  dht.begin();
  while (!Serial);
 if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1)
    void loop() {
   temp = dht.readTemperature();
   hum = dht.readHumidity();
  LoRa.beginPacket();
  LoRa.print("Humidity: ");
  LoRa.print(hum);
  LoRa.print("c")
  #include <SPI.h>

#include <LoRa.h>

#include <LiquidCrystal.h>

 

const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3; //Mention the pin number for LCD connection

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);//Initialize LCD method

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);

  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {

    Serial.println("Starting LoRa failed!");

    while (1);

  }

}

void loop() {

  // try to parse packet

  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    // received a paket

    Serial.print("Received packet '");

    // read packet

    while (LoRa.available()) {

      char incoming = (char)LoRa.read();

      if (incoming == 'c')

      {

        lcd.setCursor(0, 1);

      }

      else

      {

        lcd.print(incoming);

      }

    }

  }

 

Code for LoRa sender

#include <SPI.h>

#include <LoRa.h>

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int hum;

float temp; //Stores temperature value

int counter = 0;

void setup() {    

  Serial.begin(9600);

  dht.begin();

  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {

    Serial.println("Starting LoRa failed!");

    while (1);

  }

}

void loop() {

  temp = dht.readTemperature();

  hum = dht.readHumidity();

  Serial.print("Sending packet: ");

  Serial.println(counter);

  // send packet

  LoRa.beginPacket();

  LoRa.print("Humidity: ");

  LoRa.print(hum);

  LoRa.print("c");

  LoRa.print("Temperature:");

  LoRa.print(temp);

  LoRa.endPacket();

  counter++;

  delay(5000);

}
