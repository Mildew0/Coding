#include <Adafruit_CircuitPlayground.h>

int value;
float X, Y, Z;


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  value = analogRead(A3);
  //detects touch

  Serial.println(value); // Prints "Sensor value: X" then moves to next line
  delay(100);

if (value < 800){    //if not being touched lights are blue
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

else if (value > 800){   //if touched turn red
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
 X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

    float totalAccel = abs(X) + abs(Y) + abs(Z); //shake detection
  bool shaken = totalAccel > 20;  

  Serial.print("Touch: ");
  Serial.print(value);
  Serial.print("  Accel: ");
  Serial.println(totalAccel);

  

  if (value > 800 || shaken) {
    CircuitPlayground.playTone(440, 100); // play sound if shaken
  }
 if (value > 800 || shaken) {   //if shaken turn red
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

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);



 }

 
}