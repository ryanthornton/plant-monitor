#include "temperature_sensor.h"

int TSensor::init(tsensor_init_t& t_init) {
#ifdef TSENSOR_ADAFRUIT
    ss = t_init.ss;
    if (t_init.initialized) {
        debug_serial_println("sensor already initialized");
        initialized = true;
        return INIT_SUCCESS;
    } else if (!ss->begin(0x36)) {
        t_init.initialized = initialized = false;
        debug_serial_println("tsensor init error!");
        return ERROR_TSENSOR_INIT;
    } else { 
        debug_serial_println("tsensor init success!");
        t_init.initialized = initialized = true;
        return INIT_SUCCESS;
    }
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
float TSensor::read_temperature_C(void) {
#ifdef TSENSOR_ADAFRUIT
    return ss->getTemp();
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
