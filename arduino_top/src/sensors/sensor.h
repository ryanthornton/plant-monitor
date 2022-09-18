/**
 * @file sensor.h
 * @author ryanthornton
 * @brief Base sensor class
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

class Sensor {
protected:
    bool initialized = false;

public:
    bool get_initialized(void) const;
};
