#include <ThingerESP8266.h>

#define USERNAME "erlanggadwi"
#define DEVICE_ID "smartfarming_iot"
#define DEVICE_CREDENTIAL "XydRGbZ+as&0Dj0m"

#define SSID "IDN Boarding School Pamijahan"
#define SSID_PASSWORD ""

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  Serial.begin(115200);

  thing.add_wifi(SSID, SSID_PASSWORD);

}

void loop() {
  thing.handle();
}
