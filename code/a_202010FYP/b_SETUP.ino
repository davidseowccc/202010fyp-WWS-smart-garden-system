//*****setup*****

void setup() {
  Serial.begin(9600);
  //Ultrasonic sensor
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
 
  //PIR sensor
  pinMode(PIR, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR), pirTrigISR, RISING);
  
  //LDR sensor
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  pinMode(ldrPin4, INPUT);

  //Voltage sensor
  pinMode(voltageInput, INPUT);

  //battery indicator., on/off switch
  pinMode(LEDswitch, INPUT);
  
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

  //battery level LED declare
  pinMode(gLED1, OUTPUT);
  pinMode(gLED2, OUTPUT);
  pinMode(yLED1, OUTPUT);
  pinMode(yLED2, OUTPUT);
  pinMode(rLED1, OUTPUT);
  pinMode(rLED2, OUTPUT);
  //battery level LED initialise
  digitalWrite(gLED1, LOW);
  digitalWrite(gLED2, LOW);
  digitalWrite(yLED1, LOW);
  digitalWrite(yLED2, LOW);
  digitalWrite(rLED1, LOW);
  digitalWrite(rLED2, LOW);
  
  //relay declare
  pinMode(relayK1, OUTPUT); //LED strip (4)
  pinMode(relayK2, OUTPUT); //LED strip (5)
  pinMode(relayK3, OUTPUT); //not in use
  pinMode(relayK4, OUTPUT); //not in use
  pinMode(relayK5, OUTPUT); //not in use
  pinMode(relayK6, OUTPUT); //not in use
  pinMode(relayK7, OUTPUT); //not in use
  pinMode(relayK8, OUTPUT); //not in use
  pinMode(relayK11, OUTPUT); //system shutdown switch
  pinMode(relayK12, OUTPUT); //LED strip (6)
  pinMode(relayK13, OUTPUT); //LED Sign Board
  pinMode(relayK14, OUTPUT); //LED strip (1)
  pinMode(relayK15, OUTPUT); //LED strip (7)
  pinMode(relayK16, OUTPUT); //LED strip (8)
  pinMode(relayK17, OUTPUT); //LED strip (2)
  pinMode(relayK18, OUTPUT); //LED strip (3)
  //relay initialise
  digitalWrite(relayK1, HIGH);
  digitalWrite(relayK2, HIGH);
  digitalWrite(relayK3, HIGH);
  digitalWrite(relayK4, HIGH);
  digitalWrite(relayK5, HIGH);
  digitalWrite(relayK6, HIGH);
  digitalWrite(relayK7, HIGH);
  digitalWrite(relayK8, HIGH);
  digitalWrite(relayK11, LOW); //close the circuit
  digitalWrite(relayK12, HIGH);
  digitalWrite(relayK13, HIGH);
  digitalWrite(relayK14, HIGH);
  digitalWrite(relayK15, HIGH);
  digitalWrite(relayK16, HIGH);
  digitalWrite(relayK17, HIGH);
  digitalWrite(relayK18, HIGH);

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
