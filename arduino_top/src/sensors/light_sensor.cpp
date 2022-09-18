#include "light_sensor.h"

int LSensor::init() {
#ifdef LSENSOR_VEML7700
    debug_serial_println("lsensor init start");
    if (!veml.begin(I2C_PORT)) {
        debug_serial_println("lsensor init error!");
        initialized = false;
        return ERROR_LSENSOR_INIT;
    } else { 
        debug_serial_println("lsensor init success!");
        veml.setGain(VEML7700_GAIN_1);
        veml.setIntegrationTime(VEML7700_IT_100MS);
        initialized = true;
        return INIT_SUCCESS;
    }
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
float LSensor::read_lux(void) {
#ifdef LSENSOR_VEML7700
    return veml.readLux();
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
