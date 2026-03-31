#include <Adafruit_CircuitPlayground.h>

int value;
int freq;


void setup() {
  CircuitPlayground.begin();
}

void loop() {
  value = analogRead(A3);
  //delay(1000);

  Serial.println(value); // Prints "Sensor value: X" then moves to next line
  delay(100);

if (value < 800){
  CircuitPlayground.setPixelColor(0,46,230,201);
  CircuitPlayground.setPixelColor(1,46,230,201);
  CircuitPlayground.setPixelColor(2,46,230,201);
  CircuitPlayground.setPixelColor(3,46,230,201);
  CircuitPlayground.setPixelColor(4,46,230,201);
  CircuitPlayground.setPixelColor(5,46,230,201);
  CircuitPlayground.setPixelColor(6,46,230,201);
  CircuitPlayground.setPixelColor(7,46,230,201);
  CircuitPlayground.setPixelColor(8,46,230,201);
  CircuitPlayground.setPixelColor(9,46,230,201); 
}

else if (value > 800){
  CircuitPlayground.setPixelColor(0,240,12,68);
  CircuitPlayground.setPixelColor(1,240,12,68);
  CircuitPlayground.setPixelColor(2,240,12,68);
  CircuitPlayground.setPixelColor(3,240,12,68);
  CircuitPlayground.setPixelColor(4,240,12,68);
  CircuitPlayground.setPixelColor(5,240,12,68);
  CircuitPlayground.setPixelColor(6,240,12,68);
  CircuitPlayground.setPixelColor(7,240,12,68);
  CircuitPlayground.setPixelColor(8,240,12,68);
  CircuitPlayground.setPixelColor(9,240,12,68);
}

 
}