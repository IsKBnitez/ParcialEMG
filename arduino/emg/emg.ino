#include <LiquidCrystal.h>

const int sensorvalue = A0;
int value;
int ledv3 = 4;
int leda3 = 7;
int ledr3 = 11;

const int rs = 13, en = 12, d4 = 10, d5 = 9, d6 = 8, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Proyecto:");
  Serial.begin(9600);

  pinMode(ledv3, OUTPUT);
  //pinMode(4,OUTPUT);


  pinMode(leda3, OUTPUT);

  pinMode(ledr3, OUTPUT);

}

int residuo[4] = {0, 0, 0, 0};

void loop() {


  int value = analogRead(A0);

  if(value > 400){
    digitalWrite(ledv3,HIGH);
    digitalWrite(leda3,HIGH);
    digitalWrite(ledr3,HIGH);
  }
  else if(value > 300){
    digitalWrite(ledr3,HIGH);
    digitalWrite(leda3,HIGH);
    digitalWrite(ledv,LOW);
    
  }
  else if(value > 150){
    digitalWrite(ledr3,HIGH);
    digitalWrite(leda3,LOW);
    digitalWrite(ledv3,LOW);
  }
  else
  {
    digitalWrite(ledv3,LOW);
    digitalWrite(leda3,LOW);
    digitalWrite(ledr3,LOW);
  }
  

  for (int i = 0; i <= 3; i++) {
    residuo[i] = value % 10;
    value = value / 10;
  }

  Serial.write('a');
  for (int i = 3; i >= 0; i--) {
    Serial.write(residuo[i]);
  }
  Serial.write('c');

  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("Electro");

 
}

