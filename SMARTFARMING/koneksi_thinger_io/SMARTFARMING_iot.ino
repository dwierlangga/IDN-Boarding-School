#include <ThingerESP8266.h>
#include <DHT.h>

#define USERNAME "erlanggadwi"
#define DEVICE_ID "smartfarming_iot"
#define DEVICE_CREDENTIAL "XydRGbZ+as&0Dj0m"

#define SSID "IDN Boarding School Pamijahan"
#define SSID_PASSWORD ""

#define DHTPIN D2 
#define DHTTYPE DHT11
#define SOIL_PIN D5 

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(SOIL_PIN, INPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // Kirim data ke Thinger.io
  thing["temperature"] >> outputValue(dht.readTemperature());
  thing["humidity"] >> outputValue(dht.readHumidity());
  thing["soil_status"] >> outputValue(digitalRead(SOIL_PIN)); // 0 = basah, 1 = kering
}

void loop() {
  thing.handle();
}
