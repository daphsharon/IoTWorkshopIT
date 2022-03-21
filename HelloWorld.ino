#define trig 4
#define echo 3
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
}
void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration =pulseIn(echo,HIGH);
  int distance =duration*0.034/2;
  Serial.println("distance:"+String(distance)+"cm");
  }
