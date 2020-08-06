#include <LiquidCrystal.h>

#include <SparkFunBME280.h>

#include <Wire.h>

BME280 sensor;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Started");

  Wire.begin();
  Serial.println("Wire Online");

  Serial.println(sensor.begin());
  Serial.println("Sensor Online");

  lcd.begin(16, 2);
  Serial.println("LCD Online");
//  lcd.print("Hello, World!");

  sensor.setFilter(4);
  sensor.setTempOverSample(16);
  sensor.setPressureOverSample(16);
  sensor.setHumidityOverSample(16);
  

}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("Humidity: ");
  Serial.print(sensor.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(sensor.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(sensor.readFloatAltitudeFeet(), 1);

  Serial.print(" Temp: ");
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(sensor.readTempF(), 2);

  Serial.println();
//  lcd.setCursor(0, 1);
//  lcd.print(10);

  lcd.setCursor(0, 0); lcd.print("Humd: "); lcd.print(sensor.readFloatHumidity()); lcd.print("  %");
  lcd.setCursor(0, 1); lcd.print("Temp: "); lcd.print(sensor.readTempC()); lcd.print(" "); lcd.print((char)223); lcd.print("C");
  delay(1000);
  lcd.setCursor(0, 1); lcd.print("Temp: "); lcd.print(sensor.readTempF()); lcd.print(" "); lcd.print((char)223); lcd.print("F");
  delay(1000);
}
