#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <SD.h>


Adafruit_BME280 bme280;

File dataFile;

const int chipSelect = 4;

void setup()
{
	Serial.begin(9600);

	if (!bme280.begin(0x76))
	{
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}

	dataFile = SD.open("data.csv", FILE_WRITE);
	if (dataFile)
	{
		dataFile.print("temperature;pressure;humidity");
	}
}

void loop()
{
	String data = String(bme280.readTemperature()) + ";" + String(bme280.readPressure()) + ";" + String(bme280.readHumidity());
	dataFile.print(data);
	delay(1000);
}