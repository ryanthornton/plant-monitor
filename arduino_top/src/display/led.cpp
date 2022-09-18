#include "led.h"

#ifdef TARGET_ARDUINO

#include <Arduino.h>

#endif

int ledPixel::init() {
#ifdef LED_ADAFRUIT_NEOPIXEL
#if defined(NEOPIXEL_POWER)
  // If this board has a power control pin, we must set it to output and high
  // in order to enable the NeoPixels. We put this in an #if defined so it can
  // be reused for other boards without compilation errors
  pinMode(NEOPIXEL_POWER, OUTPUT);
  digitalWrite(NEOPIXEL_POWER, HIGH);
#endif
    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    pixels.setBrightness(20); // not so bright
#else
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
#endif
    return 0;
}

void ledPixel::set_brightness(int brightness) {
#ifdef LED_ADAFRUIT_NEOPIXEL
    pixels.setBrightness(brightness);
#endif
}

void ledPixel::led_on(int color) {
#ifdef LED_ADAFRUIT_NEOPIXEL
    pixels.fill(color);
    pixels.show();
#else
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
#endif
}

void ledPixel::led_off() {
#ifdef LED_ADAFRUIT_NEOPIXEL
    pixels.fill();
    pixels.show();
#else
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
#endif
}