#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <FirebaseESP32.h>

String a;
const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";
#define FIREBASE_HOST "project-68c06-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "RYJR9uaBt21R7TTYV9MoX6sdIAjaHXEJAMdYm8sM"
FirebaseData fbdo;
#define DHTPIN 2 
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup()
{
    pinMode(2,OUTPUT);
    Serial.begin(115200);
     WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        }
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
    dht.begin();
}

void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temp = event.temperature; 

  dht.humidity().getEvent(&event);
  float humidity = event.humidity;

   Firebase.setFloat(fbdo,"/temp",temp);
   delay(100);
   Firebase.setFloat(fbdo,"/humi",humi);
   delay(100);
   
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

   }
}
