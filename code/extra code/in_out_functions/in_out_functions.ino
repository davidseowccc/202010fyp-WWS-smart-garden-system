const int trigPin = 9;
const int echoPin = 10;

int button = 13;
byte buttState = 0;

const int LED = 4;

long duration;
int distance;

void setup() {
  pinMode(button, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(250);
  digitalWrite(LED, LOW);
  buttState = digitalRead(button);
  
//SR04 presets
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
//duration distance calculations
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

//output

  
  //Serial.print("Distance: ");
  //Serial.println(distance);
  //Serial.print("Button State: ");
  //Serial.println(buttState);
  //Serial.println(" ");
}
