#include <Adafruit_CircuitPlayground.h>
//Code for touch senser on CPX
//Made by Weitong
int value;
int freq;

void setup() {
  
  //CircuitPlayground.begin();
  //Serial.begin(9600);

}

void loop() {
  //buttonPressed = CircuitPlayground.leftButton();
  // put your main code here, to run repeatedly:
 // value = analogRead(A3);
  //delay(1000);
  //Serial.println(value);
  
  freq=map(value,0,1023,100,1000);
  //CircuitPlayground.playTone(freq,1000);
}