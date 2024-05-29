#include <Arduino.h>
#include "./Display/SSD1306WireDisplay.h"

TDisplayManager *display = new TDisplayManager();

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  display->Start();
  display->ClearDisplay();

  Serial.println("Starting...");
}

void loop() {
  display->ClearDisplay();
  display->PrintText(0, 0, "Running");
  display->Loop();
  delay(1000);
}
