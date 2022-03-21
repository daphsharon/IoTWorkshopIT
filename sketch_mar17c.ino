
void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp = analogRead(A0);
  float volt = (temp*(5/1024));
  float mv=volt*1000;
  float degree=mv/10;
  Serial.println(degree);
  delay (100);
}
