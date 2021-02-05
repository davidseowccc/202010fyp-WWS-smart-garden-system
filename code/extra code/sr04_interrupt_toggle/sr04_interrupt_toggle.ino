const int trigPin = 4;
const int echoPin = 3;

int rLED = 2;
boolean toggleState = 0;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rLED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3), sensorDetect, FALLING);

}

void sensorDetect(){
  if(duration < 900){
    toggleState = !toggleState;
    digitalWrite(rLED, toggleState);
  }
}

void loop() {
  delay(200);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.034/2)-2;
  Serial.println(duration);
}
