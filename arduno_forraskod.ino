
#include <LiquidCrystal.h>

const int carRed = 2;
const int carYellow = 3;
const int carGreen = 4;

const int pedRed = 5;
const int pedGreen = 6;

const int buttonPin = 7;
const int buzzer = 8;

// LCD bekötés: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);

  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);

  defaultState();
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    pedestrianSequence();
  }
}

void defaultState() {
  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, LOW);

  digitalWrite(pedRed, HIGH);
  digitalWrite(pedGreen, LOW);

  digitalWrite(buzzer, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Autos: ZOLD");
  lcd.setCursor(0, 1);
  lcd.print("Gyalogos: PIROS");
}

void pedestrianSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Keres fogadva");
  lcd.setCursor(0, 1);
  lcd.print("Varakozas...");
  delay(1000);

  // Autós zöld -> sárga
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Autos: SARGA");
  lcd.setCursor(0, 1);
  lcd.print("Megallas");
  delay(2000);

  // Autós sárga -> piros
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Autos: PIROS");
  lcd.setCursor(0, 1);
  lcd.print("Atkelhet!");
  delay(1000);

  // Gyalogos zöld + visszaszámlálás
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);

  for (int sec = 5; sec >= 1; sec--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ATKELHET!");
    lcd.setCursor(0, 1);
    lcd.print("Ido: ");
    lcd.print(sec);
    lcd.print(" mp");

    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(800);
  }

  // Gyalogos zöld villog + buzzer
  for (int i = 0; i < 4; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Figyelem!");
    lcd.setCursor(0, 1);
    lcd.print("Atkeles vege");

    digitalWrite(pedGreen, LOW);
    digitalWrite(buzzer, LOW);
    delay(300);

    digitalWrite(pedGreen, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(300);
  }

  digitalWrite(buzzer, LOW);

  // Gyalogos vissza pirosra
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedRed, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gyalogos: PIROS");
  lcd.setCursor(0, 1);
  lcd.print("Autos indul");
  delay(1000);

  // Autós piros + sárga átmenet
  digitalWrite(carYellow, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Autos:");
  lcd.setCursor(0, 1);
  lcd.print("PIROS+SARGA");
  delay(2000);

  // Autós vissza zöldre
  digitalWrite(carRed, LOW);
  digitalWrite(carYellow, LOW);
  digitalWrite(carGreen, HIGH);

  defaultState();
}
