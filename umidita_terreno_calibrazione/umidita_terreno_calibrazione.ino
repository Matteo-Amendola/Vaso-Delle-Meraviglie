#define DIGITAL_PIN 2
#define ANALOG_PIN A0

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
}

void loop() {
  int d = digitalRead(DIGITAL_PIN);
  int a = analogRead(ANALOG_PIN);

  Serial.print("DO: ");
  Serial.print(d ? "HIGH" : "LOW");
  Serial.println(",\tAO: " + String(a));

  delay(500);
}
