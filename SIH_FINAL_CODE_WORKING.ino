
#include "Wire.h"
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include "I2Cdev.h"
#include <MPU6050.h>
#include "VARIABLES.h"
#include "DATAFETCHING.h"
#include "FUNCTION.h"
#include "FALL_DETECTION.h"
// #include "FILTER.h"

void setup() {
  SETUP();
  MPU_SETUP();
  WIFI_SETUP();
  fire_base_connection();
  calculating_BOS();
  BOS_SETPOINT = BOS;
}

void loop() {

  if (millis() - timer > 10) {
    get_anglexyz();
    get_accexyz();
    timer = millis();
  }
  push_data();
  detect_the_fall();
  calculating_BOS();
}
