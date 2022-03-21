#define ir 2
#define buzzer 7
int x=0;
void out(){
  digitalWrite(buzzer,HIGH);
}
void setup() {
  // put your setup code here, to run once:
pinMode(ir,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  x=digitalRead(ir);
  if (x==0){
    out();
  }
  if(x>0){
    digitalWrite(buzzer,LOW);
  }
  

  else if(digitalRead(ir)==1){
  digitalWrite(buzzer,LOW);
  }
Serial.println(digitalRead(ir));
delay(100);
}
