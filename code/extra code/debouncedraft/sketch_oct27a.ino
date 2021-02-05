int rLED = 10;
int yLED = 11;
int gLED = 12;
int pButton = 2;
int buttonState = 0;
int buttCount = 0;

long lastDebounceTime = 0;
long debounceDelay = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(pButton, INPUT);

  digitalWrite(rLED, LOW);
  digitalWrite(yLED, LOW);
  digitalWrite(gLED, LOW);
}

void loop() {

  buttonState = digitalRead(pButton);
  
  if((millis() - lastDebounceTime) > debounceDelay){
    if(buttonState == HIGH)
      {
        buttCount = buttCount + 1;
     
        if(buttCount == 4)
          {
            buttCount = 1;
          }
      }
   
    if(buttCount == 1)
      {
        digitalWrite(gLED, HIGH);
        digitalWrite(yLED, LOW);
        digitalWrite(rLED, LOW);
      }
    if(buttCount == 2)
      {
        digitalWrite(gLED, LOW);
        digitalWrite(yLED, HIGH);
        digitalWrite(rLED, LOW);
      }
    if(buttCount == 3)
      {
        digitalWrite(gLED, LOW);
        digitalWrite(yLED, LOW);
        digitalWrite(rLED, HIGH);
      }
  }

}
