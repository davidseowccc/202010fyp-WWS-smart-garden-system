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

void setup() {
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
  pinMode(relayK18, OUTPUT); //kill switch
}

void loop() {
  digitalWrite(relayK1, LOW);
  digitalWrite(relayK2, LOW);
  digitalWrite(relayK3, HIGH);
  digitalWrite(relayK4, HIGH);
  digitalWrite(relayK5, HIGH);
  digitalWrite(relayK6, HIGH);
  digitalWrite(relayK7, HIGH);
  digitalWrite(relayK8, HIGH);
  digitalWrite(relayK11, LOW);
  digitalWrite(relayK12, LOW);
  digitalWrite(relayK13, LOW);
  digitalWrite(relayK14, LOW);
  digitalWrite(relayK15, LOW);
  digitalWrite(relayK16, LOW);
  digitalWrite(relayK17, LOW);
  digitalWrite(relayK18, LOW);
}
