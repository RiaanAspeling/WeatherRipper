#include "SSD1306WireDisplay.h"

void TDisplayManager::VextSwitch(bool on) {
    digitalWrite(Vext, on == true ? LOW : HIGH);
}

void TDisplayManager::DisplayReset() {
    digitalWrite(RST_OLED, HIGH);
    delay(1);
    digitalWrite(RST_OLED, LOW);
    delay(1);
    digitalWrite(RST_OLED, HIGH);
    delay(1);
}

TDisplayManager::TDisplayManager() {
    this->gfx = new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, GEOMETRY_64_32);
    pinMode(Vext, OUTPUT);
    pinMode(RST_OLED, OUTPUT);
}

void TDisplayManager::Start() {
    VextSwitch(true);
    DisplayReset();
    gfx->init();
    gfx->flipScreenVertically();
    gfx->setTextAlignment(TEXT_ALIGN_LEFT);
    gfx->setFont(ArialMT_Plain_10);
}

void TDisplayManager::Loop() {
    gfx->display();
}

void TDisplayManager::PrintText(int16_t x, int16_t y, String text) {
    gfx->drawString(x, y, text);
}

void TDisplayManager::ClearDisplay() {
    gfx->clear();
}

