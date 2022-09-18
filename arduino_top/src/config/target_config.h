#define TARGET_HUZZAH32
#define DISPLAY_FEATHERWING_OLED

//#define TARGET_QTPY

#define TARGET_ARDUINO
#define MSENSOR_ADAFRUIT
#define TSENSOR_ADAFRUIT
#define ENABLE_TSENSOR

#define LSENSOR_VEML7700

//#define DEBUG_SERIAL
#define DEBUG_LED

#ifdef TARGET_QTPY
  #define LED_ADAFRUIT_NEOPIXEL
  #define LED_ADAFRUIT_NEOPIXEL_CNT 1
  #define USE_SECONDARY_I2C
  #define SECONDARY_I2C_PORT &Wire1
#endif
#ifdef DISPLAY_FEATHERWING_OLED
  #define TARGET_SUPPORTS_DISPLAY
#endif
#ifdef TARGET_NRF52_FEATHER

#endif
#ifdef LSENSOR_VEML7700
  #define ENABLE_LSENSOR
#endif