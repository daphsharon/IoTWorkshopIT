void setup(){
  Serial.begin(115200);
}
void loop(){
  int ldr = analogRead(2);
  Serial.println("LDR:"+String(ldr));
  delay(1000);
}
