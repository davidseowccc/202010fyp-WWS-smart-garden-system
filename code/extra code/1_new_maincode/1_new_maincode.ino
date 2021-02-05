//DFplayerMini variables
#include "SoftwareSerial.h"
SoftwareSerial mySerial(10, 11);
# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 //Returns info with command 0x41 [0x01: info, 0x00: no info]
# define ACTIVATED LOW

int buttonNext = 2;
int buttonPause = 3;
int buttonPrevious = 4;
boolean isPlaying = false;

//Timer Interrupt variables
int timerCount = 11;

//SR-04 Ultrasonic sensor variables
int pplCount; 
int sensor1, sensor2, sensor3, sensor4;
int orderCache1 = 0, orderCache2 = 0;
int senseValue1 = 90; //TBC there needs to be calibration
int senseValue2 = 90;
long duration, distance;
String orderString1 = "";
String orderString2 = "";
const int echoPin1 = 42;
const int trigPin1 = 43;
const int echoPin2 = 44;
const int trigPin2 = 45;
const int echoPin3 = 46;
const int trigPin3 = 47;
const int echoPin4 = 48;
const int trigPin4 = 49;

//PIR sensor variables
const int PIR = 18;
boolean pirState = false;

//LDR sensor variables
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;
const int ldrPin4 = A4;
int lightValue1 = 550;
int lightValue2 = 550;
int lightValue3 = 550;
int lightValue4 = 550;
int lightLevel;
boolean lightState;

//Voltage sensor variables
const int voltageInput = A0;
float voltage = 0.00;
float Vin = 0.00; 

//System Output variables
volatile byte relayState = LOW;
const int relayK1 = 22;
const int relayK2 = 23;
const int relayK3 = 24;
const int relayK4 = 25;
const int relayK5 = 26;
const int relayK6 = 27;
const int relayK7 = 28;
const int relayK8 = 29;
const int relayK11 = 30;
const int relayK12 = 31;
const int relayK13 = 32;
const int relayK14 = 33;
const int relayK15 = 34;
const int relayK16 = 35;
const int relayK17 = 36;
const int relayK18 = 37;

const int rLED = 6;
const int gLED = 7;

//setup code
void setup() {
  Serial.begin(9600);
  //Ultrasonic sensor
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
 
  //PIR sensor
  pinMode(PIR, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR), pirTrigISR, RISING);
  
  //LDR sensor
  pinMode(ldrPin1, INPUT);

  //Voltage sensor
  pinMode(voltageInput, INPUT);
  
  //DFplayerMini
  pinMode(buttonPause, INPUT);
  digitalWrite(buttonPause,HIGH);
  pinMode(buttonNext, INPUT);
  digitalWrite(buttonNext,HIGH);
  pinMode(buttonPrevious, INPUT);
  digitalWrite(buttonPrevious,HIGH);
  mySerial.begin (9600);
  delay(1000);
  playFirst();
  isPlaying = true;
  
  //relay declare
  pinMode(relayK1, OUTPUT);
  pinMode(relayK2, OUTPUT);
  pinMode(relayK3, OUTPUT);
  pinMode(relayK4, OUTPUT);
  pinMode(relayK5, OUTPUT);
  pinMode(relayK6, OUTPUT);
  pinMode(relayK7, OUTPUT);
  pinMode(relayK8, OUTPUT);
  pinMode(relayK11, OUTPUT);
  pinMode(relayK12, OUTPUT);
  pinMode(relayK13, OUTPUT);
  pinMode(relayK14, OUTPUT);
  pinMode(relayK15, OUTPUT);
  pinMode(relayK16, OUTPUT);
  pinMode(relayK17, OUTPUT);
  pinMode(relayK18, OUTPUT); 
  //relay initialise
  digitalWrite(relayK1, HIGH);
  digitalWrite(relayK2, HIGH);
  digitalWrite(relayK3, HIGH);
  digitalWrite(relayK4, HIGH);
  digitalWrite(relayK5, HIGH);
  digitalWrite(relayK6, HIGH);
  digitalWrite(relayK7, HIGH);
  digitalWrite(relayK8, HIGH);
  digitalWrite(relayK11, HIGH);
  digitalWrite(relayK12, HIGH);
  digitalWrite(relayK13, HIGH);
  digitalWrite(relayK14, HIGH);
  digitalWrite(relayK15, HIGH);
  digitalWrite(relayK16, HIGH);
  digitalWrite(relayK17, HIGH);
  digitalWrite(relayK18, HIGH);

  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  digitalWrite(rLED, LOW);
  digitalWrite(gLED, LOW);
  
  cli();//stop interrupts
  //set timer4 interrupt at 1Hz
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4  = 0;
  OCR4A = 15624/1;
  TCCR4B |= (1 << WGM12);
  TCCR4B |= (1 << CS12) | (1 << CS10);  
  TIMSK4 |= (1 << OCIE4A);
  sei();//allow interrupts
}

ISR(TIMER4_COMPA_vect){
  timerCount++;
}

void pirTrigISR(){
  Serial.println("PIR interrupt Triggered");
  pirState = true;
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  sensor1 = distance;
  SonarSensor(trigPin2, echoPin2);
  sensor2 = distance;
  SonarSensor(trigPin3, echoPin3);
  sensor3 = distance;
  SonarSensor(trigPin4, echoPin4);

  printCheck();

  orderAssign();
  orderCheck();
  outputSeq();
}

//Ultrasonic sensor function
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

//Light sensor funtion
void lightSense(){
  lightLevel = analogRead(ldrPin1);
  if(lightLevel <= lightValue1){
    lightState = false;
    digitalWrite(rLED, HIGH);
    Serial.print("It is DARK outside. Light Level: ");
    Serial.println(lightLevel);
    digitalWrite(rLED, LOW);
  }
  else{
    lightState = true;
    digitalWrite(rLED, LOW);
    Serial.print("It is BRIGHT outside. Light Level: ");
    Serial.println(lightLevel);
    digitalWrite(rLED, HIGH);
  }
}

//Voltage sensor function
void voltageSense(){
  voltage = analogRead(voltageInput);
  Vin = voltage/53.285714;
}

void printCheck(){
  Serial.print("Light Value: ");
  Serial.println(lightLevel);
  Serial.print("Voltage Level: ");
  Serial.println(Vin);
}

//function to assign the order of the SR-04 sensors
void orderAssign(){
  if(sensor1 <= senseValue1){
    orderString1 = orderString1 + "S1";
    delay(50);
    return;
  }
  if(sensor2 <= senseValue1){
    orderString1 = orderString1 + "S2";
    delay(50);
    return;
  }
  if(sensor3 <= senseValue2){
    orderString2 = orderString2 + "S3";
    delay(50);
    return;
  }
  if(sensor4 <= senseValue2){
    orderString2 = orderString2 + "S4";
    delay(50);
    return;
  }
}

//function to check the order of the SR-04 sensors
void orderCheck(){  
  if(orderString1 == "S1S2"){
    Serial.println("Gate 1: Entry Detected");
    orderString1 = "";
    pplCount++;
    Serial.println(pplCount);
    delay(100);
  }
  if(orderString1 == "S2S1"){
    Serial.println("Gate 1: Exit Detected");
    orderString1 = "";
    pplCount--;
    if(pplCount == -1){
      pplCount = 0;
    }
    Serial.println(pplCount);
    delay(100);
  }
  if(orderString1 == "S1S1"){
    //Serial.println(orderString1);
    orderString1 = "S1";
  }
  if(orderString1 == "S2S2"){
    //Serial.println(orderString1);
    orderString1 = "S2";
  }
  if((orderString1 == "S1")||(orderString1 == "S2")){
    orderCache1 += 1;
    if (orderCache1 == 7){
      orderString1 = "";
      orderCache1 = 0;
    }
  }

  if(orderString2 == "S3S4"){
    Serial.println("Gate 2: Entry Detected");
    orderString2 = "";
    pplCount ++;
    Serial.println(pplCount);
    delay(100);
  }
  if(orderString2 == "S4S3"){
    Serial.println("Gate 2: Exit Detected");
    orderString2 = "";
    pplCount--;
    if(pplCount == -1){
      pplCount = 0;
    }   
  }
  if((orderString2 == "S3")||(orderString2 == "S4")){
    orderCache2 += 1;
    if(orderCache2 == 7){
      orderString2 = "";
      orderCache2 = 0;
    }
  }
}

void outputSeq(){
  lightSense();
  if(pirState == true){// OR sensor sense entry
    play();
    if(lightState == false){
      digitalWrite(relayK1, LOW);
      digitalWrite(relayK2, LOW);
      digitalWrite(relayK3, LOW);
      digitalWrite(relayK4, LOW);
      digitalWrite(relayK5, LOW); 
      digitalWrite(relayK6, LOW);
      digitalWrite(relayK7, LOW);
      digitalWrite(relayK8, LOW);
      digitalWrite(relayK11, LOW);
      digitalWrite(relayK12, LOW);
      digitalWrite(relayK13, LOW);
      digitalWrite(relayK14, LOW);
      digitalWrite(relayK15, LOW);
      digitalWrite(relayK16, LOW);
      digitalWrite(relayK17, LOW);
      digitalWrite(relayK18, LOW);
      timerCount = 0;
    }
   }
  pirState = false;
  if(timerCount == 10){
    digitalWrite(relayK1, HIGH);
    digitalWrite(relayK1, HIGH);
    digitalWrite(relayK2, HIGH);
    digitalWrite(relayK3, HIGH);
    digitalWrite(relayK4, HIGH);
    digitalWrite(relayK5, HIGH);
    digitalWrite(relayK6, HIGH);
    digitalWrite(relayK7, HIGH);
    digitalWrite(relayK8, HIGH);
    digitalWrite(relayK11, HIGH);
    digitalWrite(relayK12, HIGH);
    digitalWrite(relayK13, HIGH);
    digitalWrite(relayK14, HIGH);
    digitalWrite(relayK15, HIGH);
    digitalWrite(relayK16, HIGH);
    digitalWrite(relayK17, HIGH);
    digitalWrite(relayK18, HIGH);
  }
}

void playFirst()
{
  execute_CMD(0x3F, 0, 0);
  delay(500);
    setVolume(20);
  delay(500);
  //execute_CMD(0x11,0,0); 
  //delay(500);
  execute_CMD(0x08, 0, 2);
  delay(500);
}

void pause()
{
  execute_CMD(0x0E,0,0);
  delay(500);
}

void play()
{
  execute_CMD(0x0D,0,1); 
  delay(500);
}

void playNext()
{
  execute_CMD(0x01,0,1);
  delay(500);
}

void playPrevious()
{
  execute_CMD(0x02,0,1);
  delay(500);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

// Excecute the command and parameters
void execute_CMD(byte CMD, byte Par1, byte Par2){
// Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
// Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
  Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};
//Send the command line to the module
  for (byte k=0; k<10; k++){ 
    mySerial.write( Command_line[k]);
  }
}
