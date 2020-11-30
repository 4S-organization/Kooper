#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <SD.h>

// BME280
Adafruit_BME280 bme280;

// Ultrasonic sensor
#define PIN_TRIG 12 // Trig Pin
#define PIN_ECHO 11 // Echo Pin

File dataFile;

// Sd adapter
const int chipSelect = 4;

long duration, cm;

void setup()
{
	Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

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
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);
  cm = (duration / 2) / 29.1;

  Serial.print(cm);
  Serial.println(" sm");
  
	String data = String(bme280.readTemperature()) + ";" + String(bme280.readPressure()) + ";" + String(bme280.readHumidity());
	dataFile.print(data);
	delay(1000);
}
