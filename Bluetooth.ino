
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Daph123"); //Bluetooth device name
}

void loop() {
  if(SerialBT.available()){
    String data = SerialBT.readString();
    Serial.println("data "+data);
  }
}
