int temp;
void setup() {
  Serial.begin(9600);
}
void loop() {
  temp= analogRead(A0);
  float volt =temp*(0.0048828125);
  float mv = volt*1000;
  float degree = mv/10;
  Serial.println("Temperature=" );
  Serial.println(degree);
  delay(100);
}
