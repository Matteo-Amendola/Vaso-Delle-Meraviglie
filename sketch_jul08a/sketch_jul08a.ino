#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11

//const int soglia_dracworm = 300; 

int fotoR = A2;
int valore_fotoR = 0;
int dracworm = A0;

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
  Serial.begin(9600);
  // analogReference(EXTERNAL); // indichiamo al converrtitore AD che deve impiegare la tensione su AREF come valore di riferimento per la conversione
  lcd.createChar(0, newChar);
  lcd.begin(16, 2); // impostiamo numero di colonne e righe
  dht.begin();
  pinMode(fotoR, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  //CIAONE();
  //temperatura(dht.readTemperature());
  //umidita(dht.readHumidity());
  //luminosita();
  a();
}
void CIAONE(){
  lcd.print("CIAONE!");

  delay(3000);
  lcd.clear();
  delay(300);
}


int temperatura(int t){ 
  lcd.print("Temperatura : ");
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.write((int)0);
  lcd.print("C");

  delay(5000);
  lcd.clear();
  delay(300);
}

int umidita(int u){
  lcd.print("Umidita' : ");
  lcd.setCursor(0, 1);
  lcd.print(u);
  lcd.print("%");

  delay(5000);
  lcd.clear();
  delay(300);
}

int luminosita(){
  int V = analogRead(fotoR);
  int L = V/100;
  Serial.println(V);
  lcd.print("Luminosita' : ");
  lcd.setCursor(0, 1);
  lcd.print(L);
  lcd.print(" Lux");

  delay(5000);
  lcd.clear();
  delay(300);
}

int a(){
  int ut = analogRead(A0);
  lcd.print("Umidita' terreno : ");
  lcd.setCursor(0, 1);
  lcd.print(ut);

  delay(5000);
  lcd.clear();
  delay(300);
}
