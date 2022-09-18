#include "core.h"

#ifdef TARGET_ARDUINO

#include <Arduino.h>

#endif

PlantMonitorCore core;

int system_init(void) {

  int status = 0;

#ifdef DEBUG_SERIAL
  debug_serial_init(115200);
  debug_serial_println("UART connected!");
#endif

  status |= core.init();

  debug_serial_print("Init status: ");
  debug_serial_println(status);

  return status;
}

int PlantMonitorCore::init(void) {
  int status = 0;
  debug_serial_println("Entering core init");
#ifdef DEBUG_LED
  led.init();
  debug_serial_println("LED init complete");
  core.led.led_on(0x00ffff);
#endif
#ifdef TARGET_SUPPORTS_DISPLAY
  debug_serial_println("Configuring display");
  led_display.init();
#endif
#ifdef MSENSOR_ADAFRUIT
  msensor_init_t msi;
  msi.ss = &adafruit_msensor;
#ifdef ENABLE_TSENSOR
  tsensor_init_t &tsi = static_cast<tsensor_init_t&>(msi);
#endif
#endif
  status |= s_moisture.init(msi);
#ifdef ENABLE_TSENSOR
  status |= s_temperature.init(tsi);
#endif
#ifdef ENABLE_LSENSOR
  status |= s_light.init();
#endif

#ifdef DEBUG_LED
  if (status) {
    core.led.led_on(0xff0000);
  } else {
    core.led.led_off();
  }
  
#endif
  return status;
}

int system_loop(void) {
// cycle LED on during non-idle activity
#ifdef DEBUG_LED
  // color argument is only used when target supports it
  core.led.led_on(0x00ff00);
#endif

  uint16_t capacitance = core.s_moisture.read_capacitance();
  debug_serial_print("Capacitance: ");
  debug_serial_println(capacitance);
#ifdef ENABLE_TSENSOR
  float temp_C = core.s_temperature.read_temperature_C();
  debug_serial_print("Temperature (in C): ");
  debug_serial_println(temp_C);
#endif

#ifdef ENABLE_LSENSOR
  float lux = core.s_light.read_lux();
  debug_serial_print("Lux: ");
  debug_serial_println(lux);
#endif

#ifdef TARGET_SUPPORTS_DISPLAY    
  debug_serial_println("Writing display!");
  char buffer[16];
  core.led_display.clear();
  core.led_display.reset_cursor();
  core.led_display.println("PlantMonitor v0.1");
  core.led_display.print("Capacitance: ");
  snprintf(buffer, sizeof(buffer), "%u", capacitance);
  core.led_display.println(buffer);
#ifdef ENABLE_TSENSOR
  core.led_display.print("Temp (C): ");
  snprintf(buffer, sizeof(buffer), "%f", temp_C);
  core.led_display.println(buffer);
#endif
#ifdef ENABLE_LSENSOR
  core.led_display.print("Lux: ");
  snprintf(buffer, sizeof(buffer), "%f", lux);
  core.led_display.println(buffer);
#endif
  core.led_display.update_display();
#endif

// turn off LED before idle
#ifdef DEBUG_LED
  core.led.led_off();
#endif

  delay(5000);

  return 0;
}
