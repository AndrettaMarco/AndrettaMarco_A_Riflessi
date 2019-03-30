#include <LiquidCrystal.h>

#define led 12
#define buzzer  11
#define pulsante 10

int numrandom;
int numrandom2;
int tempo1;
int tempo2=0;
int Click=0;
int varMillis;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
pinMode (pulsante, INPUT);
pinMode (led, OUTPUT);
pinMode (buzzer, OUTPUT);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("Pronto???");
randomSeed(analogRead(0));
RiflessiLed();
RiflessiSuono();

}

// Riflessi Visivi
void RiflessiLed()
{

numrandom= random(2000, 8000);
delay(numrandom);
digitalWrite(led, HIGH);
tempo1=millis();
while(digitalRead(pulsante)==LOW);
digitalWrite(led, LOW);
lcd.clear();
tempo2=millis();
varMillis = tempo2 - tempo1;
lcd.print(varMillis);
lcd.print(" ms");

}

//Riflessi Sonori
void RiflessiSuono()
{
numrandom2 = random (2000, 8000);
delay(numrandom2);
digitalWrite(buzzer, HIGH);
tone (buzzer, 1000, 000); //Suona alla frequenza di 1000Hz per  secondi
tempo1=millis();
while(Click==0){
Click=digitalRead(pulsante);
if(Click==HIGH){
  noTone(buzzer);
}
lcd.setCursor(0,1);
tempo2=millis();

varMillis = tempo2 - tempo1;
lcd.print(varMillis);
lcd.print(" ms");
}

Click=0;

delay(2000);
 lcd.clear();
if(varMillis<500)
{ 
lcd.print("Sei Passato");}
else{
  lcd.print("Non sei passato");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
}
