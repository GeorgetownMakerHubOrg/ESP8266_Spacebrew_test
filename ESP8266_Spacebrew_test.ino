#include <SPI.h>
#include <Spacebrew.h>
#include <Ethernet.h>
#include <WebSocketsClient.h>


// docs here: https://github.com/mattfelsen/spacebrew-esp8266

Spacebrew sb;
// http://192.168.1.96:9000/?server=192.168.1.96
String sb_host = "192.168.1.96";


void setup() {
  // put your setup code here, to run once:
  uint8_t mac[] = {0xa4, 0xe7, 0xee, 0x03, 0xfd, 0x32};
  Ethernet.begin(mac);
  
  //Ethernet.start(mac);//as per the Ethernet library example, where mac is a byte[6]
  sb.connect("192.168.1.96", "ESP8266_1", "Inputs and Outputs?");
  sb.onStringMessage(receivedString);
  sb.addPublish("BoolPub", "boolean");
  sb.addSubscribe("SubStringName", "string");
}


void loop() {
  // put your main code here, to run repeatedly:
  sb.monitor();

}

void receivedString(char* name, char* value){
    Serial.print("[onStringMessage]");
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

