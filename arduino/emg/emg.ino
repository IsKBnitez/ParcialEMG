#include <LiquidCrystal.h>

const int sensorvalue = A0;
int value;
int led[3] = {4, 7, 11};
int residuo[4] = {0, 0, 0, 0};
int cantidad = 3;

const int rs = 13, en = 12, d4 = 10, d5 = 9, d6 = 8, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Proyecto:");
  Serial.begin(9600);

  for (int i = 0; i < cantidad; i++) {
    pinMode(led[i], OUTPUT);
  }

}


void loop() {


  int value = analogRead(A0);

  int sectores= map(value,0,1024,0,4);
  sectores = constrain(sectores,0,3);

  
  for(int i = 0; i < cantidad;i++){
    if(i < sectores){
      digitalWrite(led[i],HIGH);
    }
    else 
    {
      digitalWrite(led[i],LOW);
    }
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

