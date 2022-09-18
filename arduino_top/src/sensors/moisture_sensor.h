/**
 * @file moisture_sensor.h
 * @author ryanthornton
 * @brief Utilities to access moisture sensor
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sensor.h"

#ifdef MSENSOR_ADAFRUIT

  #include "../devices/adafruit_moisture_sensor.h"

#endif

class MSensor : public Sensor{

#ifdef MSENSOR_ADAFRUIT
    Adafruit_seesaw *ss;
#endif

public:
    virtual int init(msensor_init_t &m_init);
    uint16_t read_capacitance(void);

};

