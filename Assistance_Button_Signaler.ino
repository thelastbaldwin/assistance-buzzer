//Assistance Buzzer - Button Code
int ledPin = 13;
int buttonPin = 19;
unsigned long mark = 0;
volatile bool active = false;

void setup() {
  Serial1.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggle, LOW);
}

void loop() {
  if(active){
    //update these states to send a signal or not.
    (sin(millis()/300.0) > 0)?sendSignal(true): sendSignal(false); 
  }else{
    digitalWrite(ledPin, LOW);
  }
}

void sendSignal(bool state){
  if(state){
    Serial1.print(1);
    Serial1.print('#');
    digitalWrite(ledPin, HIGH);
  }else{
    Serial1.print(0);
    Serial1.print('#');
    digitalWrite(ledPin, LOW);
  }  
}

void toggle() {
  unsigned long now = millis();
  //debounce
  if(now - mark > 100){
    active = !active;
    sendLogEvent();
  } 
  mark = now;
}

void sendLogEvent()
{
  if(active){
    Keyboard.write('a');
  }else{
    Keyboard.write('b');
  }
}
