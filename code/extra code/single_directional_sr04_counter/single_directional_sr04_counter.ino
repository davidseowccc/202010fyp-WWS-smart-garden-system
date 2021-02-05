const int trigPin = 9;
const int echoPin = 10;

int count = 0;

int rLED = 4;
int button = 2;
byte buttonState = 0;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rLED, OUTPUT);
  digitalWrite(rLED, LOW);
}
//this function counts UP the no. of people in the garden
void upPrint(){
  count++;
  Serial.print("Number of people in room increased to: ");
  Serial.println(count);
  delay(500);
}
//this function counts DOWN the no. of people in the garden
void downPrint(){
  count--;
  Serial.print("Number of people in room decreased to: ");
  Serial.println(count);
  delay(500);
}
//this function CHECKS to see which sensor receieves an input
void checkSeq(){
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  buttonState = digitalRead(button);
  
  if(distance <= 50){
    upPrint();
  }
  if(buttonState == HIGH){
    downPrint();
  } 
}
//this function controls the OUTPUT of the led depending on the no. of people in the garden
void ledStatus(){
  if(count > 0)
  {
    digitalWrite(rLED, HIGH);
  }
  if(count <= 0){
    digitalWrite(rLED, LOW);
  }
}

void loop() {
  delay(50);
  //SR04 sensor setup
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);

  checkSeq(); //call check function
  ledStatus(); //call output function
  
  //Serial.println(distance);
  //Serial.println(buttonState);

}
