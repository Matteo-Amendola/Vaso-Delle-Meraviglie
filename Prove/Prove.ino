#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11

int fotoR = A0;
int valore_fotoR = 0;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte newChar[8] = {
        B00110,
        B01001,
        B01001,
        B00110,
        B00000,
        B00000,
        B00000,
        B00000
};

void setup() {
  //Serial.begin(9600);
  // analogReference(EXTERNAL); // indichiamo al converrtitore AD che deve impiegare la tensione su AREF come valore di riferimento per la conversione
  lcd.createChar(0, newChar);
  lcd.begin(16, 2); // impostiamo numero di colonne e righe
  dht.begin();
  pinMode(fotoR, INPUT);
}

void loop() {
  int t = dht.readTemperature();
  int u = dht.readHumidity();
  
  lcd.print("CIAONE!");
  
  delay(3000);
  lcd.clear();
  delay(300);
  
  lcd.print("Temperatura : ");
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.write((int)0);
  lcd.print("C");

  delay(5000);
  lcd.clear();
  delay(300);

  lcd.print("Umidita' : ");
  lcd.setCursor(0, 1);
  lcd.print(u);
  lcd.print("%");

  delay(5000);
  lcd.clear();
  delay(300);

  //  valore_fotoR = analogRead(fotoR);
  //Serial.println(analogRead(fotoR));
  lcd.print("Luminosita' : ");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(fotoR));
  lcd.print(" Ohm");

  delay(5000);
  lcd.clear();
  delay(300);
}
