#include <com.h>

Com com;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialisation");
  com.init("DVB_CDR", "ROAD_T0_TOP1");
}

void loop() {
  // put your main code here, to run repeatedly:
  com.websocket.loop();

}