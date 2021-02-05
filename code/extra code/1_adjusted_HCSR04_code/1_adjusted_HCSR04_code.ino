
const int echoPin3 = 50;
const int trigPin3 = 51;
const int echoPin4 = 52;
const int trigPin4 = 53;

int senseValue1 = 90;
int senseValue2 = 90;
int sensor1 = 100, sensor2 = 100, sensor3 = 100, sensor4 = 100;
int orderCache1 = 0, orderCache2 = 0;
long duration, distance;
String orderString1 = "";
String orderString2 = "";

void setup(){
  Serial.begin(9600);

  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin4, OUTPUT);
}

void loop(){
  sonarSense(trigPin3, echoPin3);
  sensor3 = distance;
  sonarSense(trigPin4, echoPin4);
  sensor4 = distance;

  orderAssign();
  orderCheck();

  //printCheck();
  Serial.println(orderString1);
  Serial.println(orderString2);
}

void sonarSense(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);                       
  distance = duration*0.034/2;
}

void orderAssign(){
  if(sensor1 <= senseValue1){
    orderString1 += "S1";
    return;
  }
  if(sensor2 <= senseValue1){
    orderString1 += "S2";
    return;
  }

  if(sensor3 <= senseValue2){
    orderString2 += "S3";
    return;
  }
  if(sensor4 <= senseValue2){
    orderString2 += "S4";
    return;
  }
}

void orderCheck(){
  if(orderString1 == "S1S2"){
    orderString1 = "";
    Serial.println("Gate 1: Entry Detected");
  }
  if(orderString1 == "S2S1"){
    orderString1 = "";
    Serial.println("Gate 1: Exit Detected");
  }
  if(orderString1 == "S1S1"){
    orderString1 = "S1";
  }
  if(orderString1 == "S2S2"){
    orderString1 = "S2";
  }
  if((orderString1 == "S1")||(orderString1 == "S2")){
    orderCache1 += 1;
    if (orderCache1 == 15){
      orderString1 = "";
      orderCache1 = 0;
    }
  }

  if(orderString2 == "S3S4"){
    orderString2 = "";
    Serial.println("Gate 2: Entry Detected");
  }
  if(orderString2 == "S4S3"){
    orderString2 = "";
    Serial.println("Gate 2: Exit Detected");
  }
  if(orderString2 == "S3S3"){
    orderString2 = "S3";
  }
  if(orderString2 == "S4S4"){
    orderString2 = "S4";
  }
  if((orderString2 == "S3")||(orderString2 == "S4")){
    orderCache2 += 1;
    if(orderCache2 == 15){
      orderString2 = "";
      orderCache2 = 0;
    }
  }
}

void printCheck(){
  Serial.print("Sensor 1: ");
  Serial.println(sensor1);
  Serial.print("Sensor 2: ");
  Serial.println(sensor2);
  Serial.print("Sensor 3: ");
  Serial.println(sensor3);
  Serial.print("Sensor 4: ");
  Serial.println(sensor4);
}
