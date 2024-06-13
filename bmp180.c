/*
    Project name : BMP180 Air Pressure Sensor Module
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-bmp180-air-pressure-sensor-module
*/    


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  sensors_event_t event;
  bmp.getEvent(&event);
  
  if (event.pressure) {
    float temperature;
    bmp.getTemperature(&temperature);
    
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pressure: ");
    Serial.print(event.pressure);
    Serial.println(" Pa");

    Serial.println();
  } else {
    Serial.println("Sensor error");
  }

  delay(2000);
}
