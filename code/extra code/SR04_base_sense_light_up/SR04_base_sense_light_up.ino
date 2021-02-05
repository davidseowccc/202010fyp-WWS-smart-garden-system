//SR04 pin numbers
const int trigPin = 9;
const int echoPin = 10;
//LED pin numbers
const int gLED = 4;
//define variables
long duration;
int distance;


void setup(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(gLED, OUTPUT);
Serial.begin(9600);
}

void loop(){  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin, LOW);

digitalWrite(gLED, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration*0.034/2;


if(distance < 100){
  digitalWrite(gLED, HIGH);
  delay(2500);
}



Serial.print("Distance: ");
Serial.println(distance);
}
