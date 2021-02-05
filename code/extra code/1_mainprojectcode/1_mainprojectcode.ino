//CONST INT VARIABLES ARE PORT PINS CONNECTIONS (CONNECT ACCORDINGLY)

//SR-04 Ultrasonic sensor variables
int count;
int sensor1, sensor2;
int senseValue = 90;
long duration, distance;
String orderString = "";
const int trigPin1 = 51;
const int trigPin2 = 53;
const int echoPin1 = 50;
const int echoPin2 = 52;

//PIR sensor variables
const int PIR = 18;
boolean pirState = false;

//System Output variables
const int relayK1 = 22; //
const int relayK2 = 23; //
const int relayK3 = 24; //
const int relayK4 = 25; //
const int relayK5 = 26; //
const int relayK6 = 27; //LED strip Bridge Right
const int relayK7 = 28; //LED strip Bridge Left
const int relayK8 = 29;

//setup code
void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(relayK1, OUTPUT);
  pinMode(relayK2, OUTPUT);
  pinMode(relayK3, OUTPUT);
  pinMode(relayK4, OUTPUT);
  pinMode(relayK5, OUTPUT);
  pinMode(relayK6, OUTPUT);
  pinMode(relayK7, OUTPUT);
  pinMode(relayK8, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PIR), pirTrigISR, RISING);
  attachInterrupt(digitalPinToInterrupt(PIR), pirTrigISR, FALLING);
  digitalWrite(relayK1, HIGH);
  digitalWrite(relayK2, HIGH);
  digitalWrite(relayK3, HIGH);
  digitalWrite(relayK4, HIGH);
  digitalWrite(relayK5, HIGH);
  digitalWrite(relayK6, HIGH);
  digitalWrite(relayK7, HIGH);
  digitalWrite(relayK8, HIGH);
}

//function to test the SR-04 sensors
void sensorPrint(){
  Serial.print("Sensor 1: ");
  Serial.println(sensor1);
  Serial.print("Sensor 2: ");
  Serial.println(sensor2);
  delay(300);
}

//function to test the order of the SR-04 sensors
void orderPrint(){
  Serial.println(orderString);
}

//function to read the input from the SR-04 sensors
void SonarSensor(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //fromula to calculate distance of the sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
}

//function to assign the order of the SR-04 sensors
void orderAssign(){
  if(sensor1 <= senseValue){
    orderString = orderString + "S1";
    delay(50);
    return;
  }
  if(sensor2 <= senseValue){
    orderString = orderString + "S2";
    delay(50);
    return;
  }
}

//function to check the order of the SR-04 sensors
void orderCheck(){  
  if(orderString == "S1S2"){
    Serial.println("Entry Detected");
    orderString = "";
    count++;
    Serial.println(count);
    delay(100);
  }
  if(orderString == "S2S1"){
    Serial.println("Exit Detected");
    orderString = "";
    count--;
    if(count == -1){
      count = 0;
    }
    Serial.println(count);
    delay(100);
  }
  if(orderString == "S1S1"){
    //Serial.println(orderString);
    orderString = "S1";
  }
  if(orderString == "S2S2"){
    //Serial.println(orderString);
    orderString = "S2";
  }
}

//function to check for input from the PIR sensor and set the pirState accordingly (may be replaced with an intterupt)
void pirCheck(){
  if(PIR == 1){
    pirState = true;
  }
  else{
    pirState = false;
  }
}

//Interrupt Service Routine function
void pirTrigISR(){ 
  pirState = true;
}

void pirTrigISRfall(){
  pirState = false;
}

//function for the output sequence for the system
void outputSeq(){
  if((pirState == true) || (count > 0)){
    digitalWrite(relayK1, LOW);
    digitalWrite(relayK2, LOW);
    digitalWrite(relayK3, LOW);
    digitalWrite(relayK4, LOW);
    digitalWrite(relayK5, LOW);
    digitalWrite(relayK6, LOW);
    digitalWrite(relayK7, LOW);
    digitalWrite(relayK8, LOW);
  }
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  sensor1 = distance;
  SonarSensor(trigPin2, echoPin2);
  sensor2 = distance;

  orderAssign();
  orderCheck();
  Serial.println(pirState);
  outputSeq();

  //sensorPrint();
  //Serial.println(orderString);
}
