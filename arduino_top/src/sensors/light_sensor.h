/**
 * @file light_sensor.h
 * @author ryanthornton
 * @brief Utilities to access light sensor
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sensor.h"

#ifdef LSENSOR_VEML7700
#include <Adafruit_VEML7700.h>
#endif

class LSensor : public Sensor{

#ifdef MSENSOR_ADAFRUIT
    Adafruit_VEML7700 veml{};
#endif

public:
    virtual int init();
    float read_lux(void);

};

