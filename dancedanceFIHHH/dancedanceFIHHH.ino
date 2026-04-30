#include <Adafruit_CircuitPlayground.h>

unsigned long lastSendTime = 0;
unsigned long pressStartTime = 0;

bool isHolding = false;
String currentDirection = "";

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {

  bool left = CircuitPlayground.leftButton();
  bool right = CircuitPlayground.rightButton();

  unsigned long now = millis();

  // ---------------- DETECT HOLD START ----------------
  if ((left || right) && !isHolding) {
    isHolding = true;
    pressStartTime = now;

    if (left) currentDirection = "LEFT";
    if (right) currentDirection = "RIGHT";
  }

  // ---------------- DETECT RELEASE ----------------
  if (!left && !right) {
    isHolding = false;
    currentDirection = "";
    CircuitPlayground.clearPixels();
  }

  // ---------------- ACCELERATION LOGIC ----------------
  if (isHolding) {

    unsigned long holdTime = now - pressStartTime;

    int sendInterval = 150 - (holdTime / 10);

    // clamp so it doesn’t go crazy fast
    sendInterval = constrain(sendInterval, 20, 150);

    if (now - lastSendTime > sendInterval) {

      Serial.println(currentDirection);

      if (currentDirection == "LEFT") {
        for (int i = 0; i < 10; i++) {
          CircuitPlayground.setPixelColor(i, 0, 0, 255);
        }
        CircuitPlayground.playTone(200, 30);
      }

      if (currentDirection == "RIGHT") {
        for (int i = 0; i < 10; i++) {
          CircuitPlayground.setPixelColor(i, 255, 0, 0);
        }
        CircuitPlayground.playTone(600, 30);
      }

      lastSendTime = now;
    }
  }
}
