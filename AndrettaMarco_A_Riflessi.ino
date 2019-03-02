int pulsante = 6;
int buzzer = 7;
int led = 8;
int numrandom;
void setup() {
  // put your setup code here, to run once:
pinMode (pulsante, OUTPUT);

Serial.begin(9600);
randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println("Accensione led");
while(Serial.available() == 0){}
numrandom= random(2000, 10000);
Serial.readString();
Serial.println(numrandom);

//Accensione
delay(numrandom);
digitalWrite(led, HIGH);
if (pulsante == HIGH)
{
  pulsante == LOW;
}

setup();
}
