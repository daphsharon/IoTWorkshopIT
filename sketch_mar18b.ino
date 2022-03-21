int reading;
void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(A0);
  Serial.print("Reading = ");
  Serial.println(reading);
  delay(1000);
}
