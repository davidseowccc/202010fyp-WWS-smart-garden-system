//*****The purpose of this code is to test the connections of the sensors, as well as the funtionality of the sensors*****

const int echoPin1 = 46;
const int trigPin1 = 47;
const int echoPin2 = 48;
const int trigPin2 = 49;
const int echoPin3 = 50;
const int trigPin3 = 51;
const int echoPin4 = 52;
const int trigPin4 = 53;

int sensor1, sensor2, sensor3, sensor4;
long duration, distance;

const int PIR = 18;
int pirState;

const int voltPin = A0;
float voltage;
float Vin;

const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;
const int ldrPin4 = A4;
int lightLevel1, lightLevel2, lightLevel3, lightLevel4;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  pinMode(ldrPin4, INPUT);
  pinMode(voltPin, INPUT);
}

void loop() {
  sonarSense(echoPin1, trigPin1);
  sensor1 = distance;
  sonarSense(echoPin2, trigPin2);
  sensor2 = distance;
  sonarSense(echoPin3, trigPin3);
  sensor3 = distance;
  sonarSense(echoPin4, trigPin4);
  sensor4 = distance;

  pirState = digitalRead(PIR);

  lightLevel1 = analogRead(ldrPin1);
  lightLevel2 = analogRead(ldrPin2);
  lightLevel3 = analogRead(ldrPin3);
  lightLevel4 = analogRead(ldrPin4);

  voltage = analogRead(voltPin);
  Vin = voltage/53.285714;
  
  printCheck();
}

void printCheck(){
  delay(500);
  Serial.print("Sensor1: ");
  Serial.println(sensor1);
  Serial.print("Sensor2: ");
  Serial.println(sensor2);
  Serial.print("Sensor3: ");
  Serial.println(sensor3);
  Serial.print("Sensor4: ");
  Serial.println(sensor4);
  Serial.println("");
  Serial.print("PIR State: ");
  Serial.println(pirState);
  Serial.println(""); 
  Serial.print("LDR1: ");
  Serial.println(lightLevel1);
  Serial.print("LDR2: ");
  Serial.println(lightLevel2);
  Serial.print("LDR3: ");
  Serial.println(lightLevel3);
  Serial.print("LDR4: ");
  Serial.println(lightLevel4);
  Serial.println("");
  Serial.print("VoltagePin: ");
  Serial.println(Vin);
  Serial.println(""); 
}

void sonarSense(int echoPin, int trigPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
