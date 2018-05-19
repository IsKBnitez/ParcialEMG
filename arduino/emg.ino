#include <LiquidCrystal.h>

const int sensorvalue = A0;
int value;
int ledv3 = 4;
int leda3 = 7;
int ledr3 = 11;

const int rs = 13, en = 12, d4 = 10, d5 = 9, d6 = 8, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup(){
lcd.begin(16, 2);
lcd.print("Mili Volt:");
Serial.begin(9600);

pinMode(ledv3,OUTPUT);
//pinMode(4,OUTPUT);


pinMode(leda3,OUTPUT);

pinMode(ledr3,OUTPUT);
  
}

void loop(){


int value = analogRead(A0);
lcd.setCursor(0,1);
lcd.print(value);
lcd.print("    ");
Serial.println(value);

delay(1000);









if(value > 150){
  digitalWrite(ledr3 , HIGH);
  
}
else
{
  digitalWrite(ledr3,LOW);
}

if(value > 300){
  digitalWrite(leda3,HIGH);
}

else
{
  digitalWrite(leda3,LOW);
}

if(value > 400){
  digitalWrite(ledv3,HIGH);
  
}
else
{
  digitalWrite(ledv3,LOW);
}






}

