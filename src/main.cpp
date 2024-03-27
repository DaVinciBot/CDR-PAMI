#include <com.h>

Com com = Com("DVB_CDR", "ROAD_T0_TOP1");

void setup() {
  Serial.begin(9600);
  com.sendJson();
}

void loop() {
  Serial.println("Connexion en cours");
  if(com.canGo){
    Serial.println("Connexion réussie");
  }

}