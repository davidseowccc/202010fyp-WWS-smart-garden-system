const int echoPin1 = 46;
const int trigPin1 = 47;
const int echoPin2 = 48;
const int trigPin2 = 49;
const int echoPin3 = 50;
const int trigPin3 = 51;
const int echoPin4 = 52;
const int trigPin4 = 53;

int senseValue1 = 80;
int senseValue2 = 80;
int sensor1 = 101, sensor2 = 101, sensor3 = 101, sensor4 = 101;
int orderCache1 = 0, orderCache2 = 0;
long duration, distance;
String orderString1 = "";
String orderString2 = "";


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
  
//  sensorPrint1();
//  sensorPrint2();
  orderAssign();
  orderCheck();
//  Serial.println(sensor3);
  //Serial.println(orderString2);
}

void orderAssign() {
  if (sensor1 <= senseValue1) {
    orderString1 += "S1";
    return;
  }
  if (sensor2 <= senseValue1) {
    orderString1 += "S2";
    return;
  }

  if (sensor3 <= senseValue2) {
    orderString2 += "S3";
    return;
  }
  if (sensor4 <= senseValue2) {
    orderString2 += "S4";
    return;
  }
}

void orderCheck() {
  if (orderString1 == "S1S2") {
    Serial.println("Gate 1: Entry Detected.");
    orderString1 = "";
  }
  if (orderString1 == "S2S1") {
    Serial.println("Gate 1: Exit Detected.");
    orderString1 = "";
  }
  if (orderString1 == "S1S1") {
    orderString1 = "S1";
  }
  if (orderString1 == "S2S2") {
    orderString1 = "S2";
  }

  if (orderString2 == "S3S4") {
    Serial.println("Gate 2: Entry Detected.");
    orderString2 = "";
  }
  if (orderString2 == "S4S3") {
    Serial.println("Gate 2: Exit Detected.");
    orderString2 = "";
  }
  if (orderString2 == "S3S3") {
    orderString2 = "S3";
  }
  if (orderString2 == "S4S4") {
    orderString2 = "S4";
  }

  if (orderString1.length() < 4)
    orderCache1++;
  if (orderCache1 > 15) {
    orderString1 = "";
    orderCache1 = 0;
  }
  if (orderString2.length() < 4)
    orderCache2++;
  if (orderCache2 > 15) {
    orderString2 = "";
    orderCache2 = 0;
  }


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

void sensorPrint1() {
  Serial.print("sensor1: ");
  Serial.println(sensor1);
  delay(250);
  Serial.print("sensor2: ");
  Serial.println(sensor2);
  delay(250);
}

void sensorPrint2() {
  Serial.print("sensor3: ");
  Serial.println(sensor3);
  delay(250);
  Serial.print("sensor4: ");
  Serial.println(sensor4);
  delay(250);
}
