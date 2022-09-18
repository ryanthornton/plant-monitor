/**
 * @file display.h
 * @author ryanthornton
 * @brief Device-agnostic display class
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

#ifdef DISPLAY_FEATHERWING_OLED

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#endif

class ledDisplay {
#ifdef DISPLAY_FEATHERWING_OLED
    Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
#endif
public:
    int init();
    void update_display();
    void clear();
    void set_cursor(int x, int y);
    void reset_cursor();
    void print(char* text);
    void println(char* text);
};