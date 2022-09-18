/**
 * @file temperature_sensor.h
 * @author ryanthornton
 * @brief Utilities to access temperature sensor
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sensor.h"

#ifdef TSENSOR_ADAFRUIT

  #include "../devices/adafruit_moisture_sensor.h"

#endif

class TSensor : public Sensor{

#ifdef TSENSOR_ADAFRUIT
    Adafruit_seesaw* ss;
#endif

public:
    virtual int init(tsensor_init_t &t_init);
    float read_temperature_C(void);

};
