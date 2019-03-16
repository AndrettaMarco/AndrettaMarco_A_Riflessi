#include <LiquidCrystal.h>

#define led 12
#define buzzer  11
#define pulsante 10

int numrandom;
int numrandom2;
int tempo1;
int tempo2=0;
int schiacciato=0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
pinMode (pulsante, INPUT);
pinMode (led, OUTPUT);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("Prima riga");
//lcd.setCursor(0, 1);
//lcd.print("seconda riga");
randomSeed(analogRead(0));
RiflessiLed();
RiflessiSuono();

}


void RiflessiLed()
{
numrandom= random(2000, 8000);
delay(numrandom);
digitalWrite(led, HIGH);
while(digitalRead(pulsante)==LOW);
digitalWrite(led, LOW);
}

void RiflessiSuono()
{
numrandom2 = random (2000, 8000);
delay(numrandom2);
digitalWrite(buzzer, HIGH);
tone (7, 400, 6000); //7 è la porta buzzer; suona alla frequenza di 400Hz per 6 secondi
tempo1=millis();
while(schiacciato==0){
schiacciato=digitalRead(pulsante);
if(schiacciato==HIGH){
tempo2=millis();
noTone(buzzer);
}
}

schiacciato=0;
}

void loop() {
  // put your main code here, to run repeatedly:
}
