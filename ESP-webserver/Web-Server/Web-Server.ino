// libraries
#include <FS.h>
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

// credentials
const char* ssid = "NETWORK_NAME";
const char* password = "PASSWORD";

const char* hostname = "IPADDRESS";
const char* IFTTTHostname = "IFTTT_WEBHOOKADDRESS";

AsyncWebServer server(80);
WiFiClientSecure client;

char* serverState = "Off";
bool serverToggle;
bool pingServer;

void setup() {
  Serial.begin(115200);

  // init SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  client.setInsecure();
  client.connect(IFTTTHostname, 403);

  // Print the local IP address
  Serial.println(WiFi.localIP());

  // Initial ping for the server
  getServerPing();

  // configure routes

  // send a file when /index is requested
  server.on("/index", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // return the state of the server
  server.on("/server", HTTP_GET, [](AsyncWebServerRequest * request) {
    pingServer = true;
    request->send_P(200, "text/plain", serverState);
  });

  // load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/style.css", "text/css");
  });

  // set serverToggle true so it runs the method in the loop
  server.on("/toggle_server", HTTP_GET, [](AsyncWebServerRequest * request) {
    serverToggle = true;
    request->send(200, "text/plain", serverState);
  });

  // start the server
  server.begin();
}

void toggleServer() {
  Serial.println(WiFi.localIP());
  if (WiFi.status() == WL_CONNECTED) {
    // http setup
    HTTPClient http;
    http.begin(client, IFTTTHostname);
    http.addHeader("Content-Type", "application/json");

    // send post request
    int httpCode = http.POST("{}");
    String content = http.getString();
    Serial.println(content);
    Serial.println(httpCode);
    http.end();
    if (httpCode == 200) {
      serverToggle = false;
    }
    return;
  }
}

// ping hostname 10 times and set serverState based on result
bool getServerPing() {
  Serial.print("PINGING: ");
  Serial.println(hostname);
  bool pingResult = Ping.ping(hostname, 10);
  if (pingResult) {
    Serial.print("PING SUCCESS!");
    serverState = "Running";
  } else {
    serverState = "Off";
    Serial.print("FAILED! Error code: ");
    Serial.println(pingResult);
  }
  pingServer = false;
  return pingResult;
}

void loop() {
  if (serverToggle) {
    toggleServer();
    getServerPing();
    delay(5000);
  }
  if (pingServer) {
    getServerPing();
  }
}
