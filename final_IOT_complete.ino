

#include <ESP8266WiFi.h>

int measurePin = A0; ////Connect dust sensor to A0 pin
int ledPower = D6; 
int ledRED = D7;//indicator light

unsigned int samplingTime = 280; 
unsigned int deltaTime = 40; // 
unsigned int sleepTime = 9680; 
//variables
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

const float threshold = 0.40;// threshold value for dustDensity

void setup(){

  Serial.begin(9600);

  pinMode(ledPower,OUTPUT);
  pinMode (ledRED,OUTPUT);
}

void loop(){
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);
  digitalWrite(ledRED,LOW);

  voMeasured = analogRead(measurePin); //// read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);
 
  calcVoltage = voMeasured*(5.0/1024);
  dustDensity = 0.17*calcVoltage-0.1;

 { 
  if
    (dustDensity > threshold)
    {
      digitalWrite(ledRED, HIGH);
      //delay (1000);
      }
      else
{
  digitalWrite(ledRED, LOW);
}    

  }

  Serial.println("Raw Signal Value (0-1023):");
  Serial.println(voMeasured);

  Serial.println("Voltage:");
  Serial.println(calcVoltage);

  Serial.println("Dust Density:");
  Serial.println(dustDensity); 

  delay(3000);

  }
