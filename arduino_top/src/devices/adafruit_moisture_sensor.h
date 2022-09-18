#include <Adafruit_seesaw.h>
#include <stdint.h>

#pragma once


typedef uint16_t msensor_reading_t;

typedef struct {
    Adafruit_seesaw* ss = nullptr;
    bool initialized = false;
} msensor_init_t;

typedef msensor_init_t tsensor_init_t;

