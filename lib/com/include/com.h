#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>
#include <WebSocketsClient.h>

#include <ArduinoJson.h>

class Com {

public:
    Com();
    Com(char* ssid, char* password);
    void sendMsg(char* msg, char* data);
    void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);
    void init(char* ssid, char* password);
    WebSocketsClient webSocket;
    bool canGo = false;

private:
    char* ssid;
    char* password;
    char* ip = "rc.local";
    char* name = "PAMI";
    int port = 8080;
    WifiMulti multi_wifi;
};

struct Message {
    char* sender;
    char* msg;
    char* data;
    unsigned long ts;
};