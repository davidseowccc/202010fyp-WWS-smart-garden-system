const int rLED = 13;
const int ldrPin = A0;

int lightValue = 450;
int lightLevel;
boolean lumen;

void setup(){
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop(){
  lightSense();
}

void lightSense(){
  lightLevel = analogRead(ldrPin);
  if(lightLevel <= lightValue){
    lumen = false;
    digitalWrite(rLED, HIGH);
    Serial.print("It is DARK outside. Light Level: ");
    Serial.println(lightLevel);
  }
  else{
    lumen = true;
    digitalWrite(rLED, LOW);
    Serial.print("It is BRIGHT outside. Light Level: ");
    Serial.println(lightLevel);
  }
}
