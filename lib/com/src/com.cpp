#include "com.h"

Com::Com(char *ssid, char *password)
{
    this->init(ssid, password);
}

Com::Com()
{
}

void Com::init(char *ssid, char *password)
{
        this->ssid = ssid;
        this->password = password;

        multi_wifi.addAP(ssid, password);

    	while(multi_wifi.run() != WL_CONNECTED) {
    		delay(100);
    	}

        this->webSocket.begin(ip, port, "/pami?sender=PAMI");

        this->webSocket.onEvent([&](WStype_t type, uint8_t *payload, size_t length) {
            this->webSocketEvent(type, payload, length);
        });

        //try ever 5000 again if connection has failed
    	this->webSocket.setReconnectInterval(5000);

}

void Com::sendMsg(char *msg, char *data)
{
    // message is on the JSON form {sender=PAMI,msg=MSG,data=DATA,ts=TIMESTAMP}
    // timestamp
    unsigned long ts = millis();
    // create a JSON object

    /*
    StaticJsonDocument<200> doc;
    doc["sender"] = this->name;
    doc["msg"] = msg;
    doc["data"] = data;
    doc["ts"] = ts;

    // serialize the JSON object
    String json;
    serializeJson(doc, json);
    */
    // send the message
    this->webSocket.sendTXT("aaaaaaaaaaaaaa");
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