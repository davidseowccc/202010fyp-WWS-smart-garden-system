int ledG = 12;
int ledY = 11;
int ledR = 10;
int button = 3;
int buttonState = 0;

void setup(){
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop(){
  digitalWrite(ledG, LOW);
  digitalWrite(ledR, LOW);
  buttonState = digitalRead(button);

  if(buttonState == HIGH)
    digitalWrite(ledG, HIGH);
  else
    digitalWrite(ledR, HIGH);
  
}
