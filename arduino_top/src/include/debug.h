#ifdef DEBUG_SERIAL

#define debug_serial_init(baud) Serial.begin(baud)

#define debug_serial_print(debug_str) if (Serial) Serial.print(debug_str)
#define debug_serial_println(debug_str) if (Serial) Serial.println(debug_str)


#else

#define debug_serial_print(debug_str)
#define debug_serial_println(debug_str)


#endif