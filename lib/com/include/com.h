#include <Arduino.h>

#include <WiFi.h>
#include <WebSocketsClient.h>

class Com {

public:
    Com(char* ssid, char* password);
    void sendJson();
    void receive();
    void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

private:
    char* ssid;
    char* password;
    char* ip = "192.168.0.104";
    char* name = "PAMI";
    int port = 8080;
    WebSocketsClient webSocket;
    void send_data(char* data);
    void receive_data();
    void wait_for_go();
};