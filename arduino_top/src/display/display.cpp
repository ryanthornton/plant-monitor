#include "display.h"

int ledDisplay::init() {
#ifdef DISPLAY_FEATHERWING_OLED
  display.begin(0x3C, true); // Address 0x3C default

  // text display init
  display.setRotation(1);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.println("PlantMonitor v0.1 init!");
  display.display();
#endif
    return 0;
}

void ledDisplay::update_display() {
#ifdef DISPLAY_FEATHERWING_OLED
  display.display();
#endif
}

void ledDisplay::print(char* text) {
#ifdef DISPLAY_FEATHERWING_OLED
  display.print(text);
#endif 
}

void ledDisplay::println(char* text) {
#ifdef DISPLAY_FEATHERWING_OLED
  display.println(text);
#endif 
}

void ledDisplay::clear() {
#ifdef DISPLAY_FEATHERWING_OLED
  display.clearDisplay();
#endif 
}

void ledDisplay::set_cursor(int x, int y) {
#ifdef DISPLAY_FEATHERWING_OLED
  display.setCursor(x, y);
#endif 
}

void ledDisplay::reset_cursor() {
    set_cursor(0, 0);
}