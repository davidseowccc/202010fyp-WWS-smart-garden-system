const int trigPin = 9;
const int echoPin = 10;

int count = 0;
int state1 = 0, state2 = 0;

int rLED = 4;
int sButton = 2;
byte sButtonState = 0;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(sButton, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(rLED, OUTPUT);
}

void checkSeq(){
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  sButtonState = digitalRead(sButton);

  if(distance <=50){
    state1 = 1;
  }
  else{
    state1 = 0;
  }

  delay(250);
  
  if(sButtonState == HIGH){
    state2 = 1;
  }
  else{
    state2 = 0;
  }

  if((state1 == 1) && (state2 == 1)){
    outputAddSeq();
  }
}

void outputAddSeq(){
  count++;
  Serial.print("No. of visitors: ");
  Serial.println(count);
}

void ledSeq(){
  if(count > 0)
  {
    digitalWrite(rLED, HIGH);
  }
  if(count == 0)
  {
    digitalWrite(rLED, LOW);
  }
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);

  checkSeq();
  ledSeq();

  //Serial.println(distance);
  //Serial.println(sButtonState);
}
