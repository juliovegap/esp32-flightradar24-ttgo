#pragma once

#define APP_TITLE "FlightRadar"
#define APP_VERSION "1.2"

#define WIFI_SSID "FlightRadar"
#define WIFI_PASSWORD nullptr
#define CONFIG_VERSION "1.5"

// One degree is 110.567 km (69.091 miles)

#define DEGREES_TO_KM 110.567
#define DEGREES_TO_MI 69.091

// Time servers
#define NTP_SERVER_1 "nl.pool.ntp.org"
#define NTP_SERVER_2 "europe.pool.ntp.org"
#define NTP_SERVER_3 "time.nist.gov"
#define NTP_SERVERS NTP_SERVER_1, NTP_SERVER_2, NTP_SERVER_3

// Amsterdam Airport Schiphol
#define DEFAULT_LOCATION "AMS"
#define DEFAULT_LATITUDE 52.308601
#define DEFAULT_LONGITUDE 4.76389
#define DEFAULT_AIR true
#define DEFAULT_GROUND false
#define DEFAULT_GLIDERS true
#define DEFAULT_VEHICLES false
#define DEFAULT_TIMEZONE "Europe/Amsterdam"
#define DEFAULT_METRIC true
#define DEFAULT_BRIGHTNESS 75
// By default take a 10km range
#define DEFAULT_RANGE_LATITUDE 0.1
#define DEFAULT_RANGE_LONGITUDE 0.1

// Charles de Gaulle International Airport
// #define DEFAULT_LOCATION "CDG"
// #define DEFAULT_LATITUDE 49.012798
// #define DEFAULT_LONGITUDE 2.55000
// #define DEFAULT_AIR true
// #define DEFAULT_GROUND false
// #define DEFAULT_GLIDERS true
// #define DEFAULT_VEHICLES false
// #define DEFAULT_TIMEZONE "Europe/Paris"
// #define DEFAULT_METRIC true
// By default take a 10km range
// #define DEFAULT_RANGE_LATITUDE 0.1
// #define DEFAULT_RANGE_LONGITUDE 0.1

// Venice Marco Polo Airport
// #define DEFAULT_LOCATION "VCE"
// #define DEFAULT_LATITUDE 45.50299
// #define DEFAULT_LONGITUDE 12.3519
// #define DEFAULT_AIR true
// #define DEFAULT_GROUND false
// #define DEFAULT_GLIDERS true
// #define DEFAULT_VEHICLES false
// #define DEFAULT_TIMEZONE "Europe/Rome"
// #define DEFAULT_METRIC true
// By default take a 10km range
// #define DEFAULT_RANGE_LATITUDE 0.1
// #define DEFAULT_RANGE_LONGITUDE 0.1

// JFK Airport
// #define DEFAULT_LOCATION "JFK"
// #define DEFAULT_LATITUDE 40.639801
// #define DEFAULT_LONGITUDE -73.7789
// #define DEFAULT_AIR true
// #define DEFAULT_GROUND false
// #define DEFAULT_GLIDERS true
// #define DEFAULT_VEHICLES false
// #define DEFAULT_TIMEZONE "America/New_York"
// #define DEFAULT_METRIC false
// By default take a 5mile range
// #define DEFAULT_RANGE_LATITUDE 0.05
// #define DEFAULT_RANGE_LONGITUDE 0.05

// LAX Airport:
// #define DEFAULT_LOCATION "LAX"
// #define DEFAULT_LATITUDE 33.942501
// #define DEFAULT_LONGITUDE -118.407997
// #define DEFAULT_AIR true
// #define DEFAULT_GROUND false
// #define DEFAULT_GLIDERS true
// #define DEFAULT_TIMEZONE "America/Los_Angeles"
// #define DEFAULT_METRIC false
// By default take a 5mile range
// #define DEFAULT_RANGE_LATITUDE 0.05
// #define DEFAULT_RANGE_LONGITUDE 0.05

// Refresh screen every 10 seconds
constexpr auto flight_milliseconds = 15 * 1000ul;
constexpr auto flight_milliseconds_error = 120 * 1000ul;
constexpr auto flight_milliseconds_noflights = 30 * 1000ul;
// Allow 4 cycles of each flight
constexpr auto display_cycles = 4;

// Heap diagnostics: log free heap periodically so fragmentation trends are visible in the logs
// instead of only showing up as an unexplained crash/hang after days of uptime.
constexpr auto heap_check_milliseconds = 5 * 60 * 1000ul; // every 5 minutes
// Safety net: Strings used throughout flight parsing/display can fragment the heap over long
// uptimes (see get_flights()/flight_info). Below this threshold of free internal heap, prefer a
// clean, controlled restart over risking an allocation failure or corruption-induced hang.
constexpr auto heap_minimum_free_bytes = 20 * 1024ul;
// Belt-and-suspenders: restart on a fixed cadence regardless of heap, during a moment the user is
// unlikely to be watching, so any slow leak/fragmentation/CDC-logging issue never accumulates for
// more than this long between recoveries.
constexpr auto uptime_reboot_milliseconds = 48ul * 60 * 60 * 1000ul; // 48 hours

// Backlight dimming: the backlight LED (TFT_BL) is driven with PWM so the brightness can be changed
constexpr auto backlight_pwm_frequency = 5000;                            // PWM frequency in Hz (outside the audible range)
constexpr auto backlight_pwm_resolution = 8;                              // PWM resolution in bits (duty cycle 0..255)
constexpr auto backlight_max_level = (1 << backlight_pwm_resolution) - 1; // Full brightness
