#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>
#include <FirebaseESP32.h>

String a;
const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";
#define FIREBASE_HOST "https://project-68c06-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "RYJR9uaBt21R7TTYV9MoX6sdIAjaHXEJAMdYm8sM"
FirebaseData fbdo;
#define DHTPIN 2 
#define DHTTYPE DHT11

void setup()
{
    Serial.begin(115200);
     WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
}
}

void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temp = event.temperature; 

  dht.humidity().getEvent(&event);
  float humidity = event.humidity;
  
   if(Firebase.getInt(fbdo, "/LED")){
    String a = fbdo.stringData();
    Serial.println(a);
   }
   if(a=="1"){
    digitalWrite(2,HIGH);
   }
   if(a=="0"){
    digitalWrite(2,LOW);
   }
   Firebase.setFloat(fbdo,"/temp",temp);
   delay(100);
   Firebase.setFloat(fbdo,"/humi",humi);
   delay(100);
   }
}
