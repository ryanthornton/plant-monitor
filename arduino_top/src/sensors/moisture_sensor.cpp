#include "moisture_sensor.h"

int MSensor::init(msensor_init_t& m_init) {
#ifdef MSENSOR_ADAFRUIT
    ss = m_init.ss;
    debug_serial_println("msensor init start");
    if (m_init.initialized) {
        debug_serial_println("sensor already initialized");
        initialized = true;
        return INIT_SUCCESS;
    } else if (!ss->begin(0x36)) {
        debug_serial_println("msensor init error!");
        m_init.initialized = initialized = false;
        return ERROR_MSENSOR_INIT;
    } else { 
        debug_serial_println("msensor init success!");
        m_init.initialized = initialized = true;
        return INIT_SUCCESS;
    }
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
uint16_t MSensor::read_capacitance(void) {
#ifdef MSENSOR_ADAFRUIT
    return ss->touchRead(0);
#else
    return ERROR_TARGET_UNSUPPORTED;
#endif
}
