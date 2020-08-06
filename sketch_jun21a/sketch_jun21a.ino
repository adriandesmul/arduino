#include <Wire.h>

#include <SparkFunBME280.h>
BME280 mySensor;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading basic values from BME280");

  Wire.begin();
//  Wire.setClock(400000);
  
  mySensor.beginI2C();
}

void loop()
{
  Serial.print("Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(mySensor.readFloatAltitudeFeet(), 1);

  Serial.print(" Temp: ");
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(mySensor.readTempF(), 2);

  Serial.println();

  delay(50);
}
