#include <LiquidCrystal.h>
#include "i2c_BMP280.h"
#include "i2c.h"
#include "i2c_Sensor.h"

LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
BMP280 bmp280;
float p, t;

void setup() {
  Serial.begin(9600);
  LCD.begin(16, 2);
  LCD.clear();
  bmp280.initialize();
}

void loop() {
  LCD.setCursor(1, 0);
  bmp280.awaitMeasurement();
  bmp280.getPressure(p); 
  bmp280.getTemperature(t);
  LCD.print(p);
  LCD.setCursor(1, 1);
  LCD.print(t);

  delay(1000);
  LCD.clear();
}
