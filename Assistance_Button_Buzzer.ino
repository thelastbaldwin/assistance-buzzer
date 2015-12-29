//Assistance Button - Buzzer Code
int ledPin = 13;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sig; 
  
  if(Serial1.available()){
    sig = Serial1.parseInt();
    if(sig == 1){
      digitalWrite(ledPin, HIGH);
    }else{
      digitalWrite(ledPin, LOW);
    }
  }else{
    digitalWrite(ledPin, LOW); 
  }
}

