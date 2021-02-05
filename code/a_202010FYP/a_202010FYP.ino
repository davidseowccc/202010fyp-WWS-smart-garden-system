//*****global variables and pin connections*****

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
int delayDuration = 5; //duration in seconds the outputSeq() will be ON
volatile int timerCount = delayDuration + 1;

//SR-04 Ultrasonic sensor variables and pins
int pplCount;
int sensor1, sensor2, sensor3, sensor4;
int orderCache1 = 0, orderCache2 = 0;
int senseValue1 = 100; //Calibrated values
int senseValue2 = 135; //Calibrated values
long duration, distance;
String orderString1 = "";
String orderString2 = "";
boolean gate1State = false;
boolean gate2State = false;
const int echoPin1 = 46;
const int trigPin1 = 47;
const int echoPin2 = 48;
const int trigPin2 = 49;
const int echoPin3 = 50;
const int trigPin3 = 51;
const int echoPin4 = 52;
const int trigPin4 = 53;

//PIR sensor variables and pins
const int PIR = 18;
volatile boolean pirState = false;

//LDR sensor variables and pins
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;
const int ldrPin4 = A4;
int lightValue1 = 400; //Needs to be calibrated
int lightValue2 = 400; //Needs to be calibrated
int lightValue3 = 400; //Needs to be calibrated
int lightValue4 = 400; //Needs to be calibrated
int lightLevel1, lightLevel2, lightLevel3, lightLevel4;
boolean lightState;

//Voltage sensor variables and pins
const int voltageInput = A0;
float voltage = 0.00;
float Vin = 0.00;

//LED battery level indicator variables and pins
const int gLED1 = 38;
const int gLED2 = 39;
const int yLED1 = 40;
const int yLED2 = 41;
const int rLED1 = 42;
const int rLED2 = 43;

//control() function variables and pins
const int LEDswitch = 4;
boolean switchState;

//System Output variables and pins
byte relayState = HIGH;
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
