//timer4 will interrupt at 1Hz
const int rLED = 8;
const int PIR = 2;

boolean pirState;
int count = 11;

void setup(){

Serial.begin(9600);

pinMode(rLED, OUTPUT);
digitalWrite(rLED, LOW);

cli();//stop interrupts

//set timer4 interrupt at 1Hz
 TCCR4A = 0;// set entire TCCR1A register to 0
 TCCR4B = 0;// same for TCCR1B
 TCNT4  = 0;//initialize counter value to 0
 // set compare match register for 1hz increments
 OCR4A = 15624/1;// = (16*10^6) / (1*1024) - 1 (must be <65536)
 // turn on CTC mode
 TCCR4B |= (1 << WGM12);
 // Set CS12 and CS10 bits for 1024 prescaler
 TCCR4B |= (1 << CS12) | (1 << CS10);  
 // enable timer compare interrupt
 TIMSK4 |= (1 << OCIE4A);

sei();//allow interrupts

}//end setup

ISR(TIMER4_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
count++;

}
 
void loop(){
  
  pirState = digitalRead(PIR);
  if(pirState == HIGH){
    Serial.println("10 seconds timer start now");
    count = 0;
    digitalWrite(rLED, HIGH);
  }
  if(count == 10){
    Serial.println("10 seconds have passed");
    digitalWrite(rLED, LOW);
  }
}
