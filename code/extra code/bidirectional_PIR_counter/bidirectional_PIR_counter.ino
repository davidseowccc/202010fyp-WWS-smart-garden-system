const int pir = 2;
const int pir1 = 3;
const int rLED = 23;
const int gLED = 25;

int count = 0;

boolean pirState = false;
boolean pirState1 = false;

String orderString = "";

void setup() {
pinMode(pir, INPUT);
pinMode(pir1, INPUT);
pinMode(rLED, OUTPUT);
pinMode(gLED, OUTPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(2), pirSense, RISING);
attachInterrupt(digitalPinToInterrupt(3), pirSense1, RISING); 

}

void pirSense(){
  pirState = digitalRead(pir);
  if(pirState == true){
    //Serial.println("PIR 1 Sensed");
    orderString = orderString + "PIR1 ";
    exit;
  }
}

void pirSense1(){
  pirState1 = digitalRead(pir1);
  if(pirState1 == true){
    //Serial.println("PIR 2 Sensed");
    orderString = orderString + "PIR2 ";
    exit;
  }
}

void orderCheck(){
  //Serial.println(orderString);
  if(orderString == "PIR1 PIR2 ")
  {
    count++;
    Serial.println("Entry detected");
    digitalWrite(gLED, HIGH);
    Serial.println(count);
    delay(2500);
    orderString = "";
  }

  if(orderString == "PIR2 PIR1 "){
    count--;
    Serial.println("Exit detected.");
    digitalWrite(rLED, HIGH);
    Serial.println(count);
    delay(2500);
    orderString = "";
  }

  if(orderString == "PIR1 PIR1 "){
    orderString = "";
  }

  if(orderString == "PIR2 PIR2"){
    orderString = "";
  }

  else{
    digitalWrite(rLED, LOW);
    digitalWrite(gLED, LOW);
  }
}

void postiveCount(){
  if(count < 0){
    count = 1;
  }
}

void loop() {
  orderCheck();
  //Serial.println(count);
  //Serial.println(orderString);
}
