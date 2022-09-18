/**
 * @file led.h
 * @author ryanthornton
 * @brief Device-agnostic LED class
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "../config/target_config.h"
#include "../include/global_defines.h"
#include "../include/debug.h"

#ifdef LED_ADAFRUIT_NEOPIXEL
#include <Adafruit_NeoPixel.h>
#endif

class ledPixel {

#ifdef LED_ADAFRUIT_NEOPIXEL
    Adafruit_NeoPixel pixels{LED_ADAFRUIT_NEOPIXEL_CNT, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800};
#endif

public:
    int init(void);
    void set_brightness(int brightness);
    void led_on(int color = 0xffffff);
    void led_off();

};  

