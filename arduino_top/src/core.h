/**
 * Header file for init process and central loop
 */

#include "config/target_config.h"
#include "include/global_defines.h"
#include "include/debug.h"

#ifdef DEBUG_LED
#include "display/led.h"
#endif

#ifdef TARGET_SUPPORTS_DISPLAY
#include "display/display.h"
#endif

#include "sensors/moisture_sensor.h"

#ifdef ENABLE_TSENSOR 
#include "sensors/temperature_sensor.h"
#endif

#ifdef ENABLE_LSENSOR 
#include "sensors/light_sensor.h"
#endif

#ifdef TARGET_PERIPHERAL
#include "networking/peripheral.h"
#elifdef TARGET_HOMEKIT
#include "networking/homekit.h"
#endif


int system_init(void);

int system_loop(void);

class PlantMonitorCore {

#ifdef MSENSOR_ADAFRUIT
    Adafruit_seesaw adafruit_msensor{I2C_PORT};
#endif

public:
    MSensor s_moisture;

#ifdef ENABLE_TSENSOR 
    TSensor s_temperature;
#endif

#ifdef ENABLE_LSENSOR
    LSensor s_light;
#endif

#ifdef DEBUG_LED
    ledPixel led;
#endif

#ifdef TARGET_SUPPORTS_DISPLAY
    ledDisplay led_display;
#endif
    
    int init(void);

    
};
