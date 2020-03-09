// code mostly from https://techtutorialsx.com/2016/07/21/esp8266-post-requests/
// deep sleep from https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/
// please note this sleep requires a physical modification on the ESP01
// note the endpoint eg. "http.begin", this matches your endpoint that's receiving the POST request as text

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

bool hasSlept = false;

void setup() {
  Serial.begin(115200); 
}

void connectWifi() {
  WiFi.begin("SSID", "WiFiPass");

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.println("Waiting for connection");
  }
  
  transmit();
}

void transmit() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://your-192-ip-or-domain/esp-emit-solar");
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST("From ESP8266");
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();  
  } else {
    Serial.println("Error in WiFi connection");
  }
}

void loop() {
  connectWifi();
  ESP.deepSleep(60e6);
}