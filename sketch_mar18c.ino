void setup() {
  // put your setup code here, to run once:
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,HIGH);
  digitalWrite(4,LOW);
  delay(3000);
}
