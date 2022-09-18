# PlantMonitor
This project is designed to be a system to monitor the conditions of plants.
The eventual goal is a network of microcontrollers with the ability to connect to home automation frameworks and custom monitoring applications.
The general framework should be device-ambiguous, to put as few as possible constraints on potential supported hardware.
Ideally, this project should allow someone with little to no coding / embedded systems experience to purchase off-the-shelf hardware, run an install script, flash their devices in any configuration, then connect to their devices.

## Supported Hardware
Chipsets / Microcontrollers
- ESP32
  - Adafruit Feather "HUZZAH32"
  - Adafruit QT PY
- NRF52832
  - Adafruit Feather NRF52832
Moisture sensor
  - Adafruit I2C soil sensor
Temperature sensor
  - Adafruit I2C soil sensor
Light sensor
  - VEML 7700
Displays
  - FeatherWing OLED - 128x64
  
## Current functionality
- Read sensor data from supported sensors
- Output sensor data on display and via serial
- Configurability to quicky re-build for different hardware setups

## Future functionality
1. BLE peripheral support
   - Send data from peripheral devices to central device
   - First instance of central device will simply be a home server so I can analyze capacitance change over time  
   - Analyze power drain when in peripheral mode - battery should last for at least the time between watering
2. Central device BLE support
   - Set up some devices as central devices which can aggregate data
   - These devices would presumably be plugged in
3. Central device WiFi support
   - Add in support for wifi-capable chipsets
4. Google Home / Apple Homekit / other home automation support
5. Custom phone application
