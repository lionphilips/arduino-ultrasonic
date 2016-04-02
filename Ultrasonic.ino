#include <Ultrasonic.h>
 
#define pino_trigger 5
#define pino_echo 4
#define led 8
 
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  digitalWrite(led, HIGH);
  delay(cmMsec * 10);

  digitalWrite(led, LOW);
  delay(100);
}
