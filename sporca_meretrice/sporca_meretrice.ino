#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val_cad = 0; // valore della conversione analogico digitale
float f_temperatura = 0;

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL); // indichiamo al converrtitore AD che deve impiegare la tensione su AREF come valore di riferimento per la conversione
  lcd.begin(16, 2); // impostiamo numero di colonne e righe 
}

void loop() {
  lcd.print("CIAONE!");
  delay(2000);

  for(int L=0; L<10000; L++) {
    lcd.clear();
  
    for(byte TheCycle; TheCycle<100; TheCycle++){
      val_cad += analogRead(0);
    }

    val_cad /= 100; // eseguiamo la media dei 100 valori
    f_temperatura = ((val_cad * 0.0032) - 0.5) / 0.01; // calcoliamo la temperatura in °C
  
    lcd.print("Temperatura:");
  
    lcd.setCursor(0,1);
  
    lcd.print(f_temperatura,1);
    lcd.print("C");

    delay(5000);

    if(L >= 999) L=0;
  }

   
    
/*  for(int i=0; i<122; i++){
    delay(500);
    lcd.print(i); // stampiamo il numero di secondi dall'ultimo reset
    Serial.print(i);
  }
*/
}
