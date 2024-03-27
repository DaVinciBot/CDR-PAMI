#include "com.h"

Com::Com(char *ssid, char *password)
{
    this->ssid = ssid;
    this->password = password;

    WiFi.begin(ssid, password);
    // wait until connection is established
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        // USE_SERIAL.print(".");
    }

    this->webSocket.begin(ip, port, "/pami?sender=PAMI");
}

void Com::sendJson()
{
    this->webSocket.sendTXT("test");
}

void Com::receive()
{
    // put your code here
}

void Com::webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{

    switch (type)
    {
    case WStype_DISCONNECTED:
        // USE_SERIAL.printf("[WSc] Disconnected!\n");
        break;
    case WStype_CONNECTED:
        // USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

        // send message to server when Connected
        this->webSocket.sendTXT("Connected");
        break;
    case WStype_TEXT:
        // USE_SERIAL.printf("[WSc] get text: %s\n", payload);

        // send message to server
        // webSocket.sendTXT("message here");
        break;
    case WStype_BIN:
        // USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
        // hexdump(payload, length);

        // send data to server
        webSocket.sendTXT("message here");
        break;
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
        break;
    }
}