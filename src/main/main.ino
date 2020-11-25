#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme280;

void setup() {
	Serial.begin(9600);

	if (!bme280.begin(0x76)) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
}

void loop() {
	Serial.print("Temperature = ");
	Serial.print(bme280.readTemperature());
	Serial.println("*C");

	Serial.print("Pressure = ");
	Serial.print(bme280.readPressure() / 100.0F);
	Serial.println("hPa");

	Serial.print("Approx. Altitude = ");
	Serial.print(bme280.readAltitude(SEALEVELPRESSURE_HPA));
	Serial.println("m");

	Serial.print("Humidity = ");
	Serial.print(bme280.readHumidity());
	Serial.println("%");

	Serial.println();
	delay(1000);
}