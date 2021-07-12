#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int dracworm = analogRead(A0);
  lcd.print("Umidita'terreno:");
  lcd.setCursor(0, 1);
  lcd.print(dracworm);
  lcd.print(" %");
  delay(100);

}
