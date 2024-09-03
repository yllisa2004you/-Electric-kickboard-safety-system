#define FORCE_SENSOR_PIN A1 // the FSR and 10K pulldown are connected to A0
#define LED 53

int speed = 6;
int In1 = 5;
int In2 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

  pinMode(speed,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  analogWrite(speed,0); // 무회전
}
 
void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  int push_count = 0;
  for(int i = 1;i<=16;i++){
    int value = analogRead(i);
    if(value >=3)
      push_count++;
  }
  Serial.println(push_count);
  if(push_count >= 4){
    digitalWrite(LED,HIGH);
    analogWrite(speed,0);
  }
    
  else{
    analogWrite(speed,255);
    digitalWrite(LED,LOW);
    
  }
    
 
  delay(100);
}