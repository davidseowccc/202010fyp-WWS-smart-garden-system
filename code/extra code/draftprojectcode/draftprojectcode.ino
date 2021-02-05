int ledG = 12;
int ledY = 11;
int ledR = 10;
int button = 2;
int buttonState = 0;
int timerCount = 0;

void timerCounter(){
  timerCount = timerCount + 1;
}

void setup(){
  Serial.begin(9600);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), timerCounter, RISING);
  }

void loop(){
  digitalWrite(ledG, LOW);
  digitalWrite(ledR, HIGH);
  buttonState = digitalRead(button);

  while(timerCount > 0){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
    timerCount = timerCount - 3;
    Serial.println(timerCount);
    delay(1000);
  }
  
}
