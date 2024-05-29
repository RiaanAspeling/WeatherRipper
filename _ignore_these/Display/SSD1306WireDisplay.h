#ifndef SSD1306WireDisplay_h
#define SSD1306WireDisplay_h

#include <Arduino.h>
#include <Wire.h>         // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"  // legacy: #include "SSD1306.h"

class TDisplayManager {
    public:
        TDisplayManager();
        void Start();
        void Loop();
        void PrintText(int16_t x, int16_t y, String text);
        // Passthrough methods
        void ClearDisplay();
    private:
        void VextSwitch(bool on);
        void DisplayReset();
        SSD1306Wire *gfx;
};

#endif // SSD1306WireDisplay_h