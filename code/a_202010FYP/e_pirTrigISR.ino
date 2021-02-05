//*****PIR trigger Interrupt Service Routine*****

void pirTrigISR(){
  Serial.println("PIR interrupt Triggered");
  pirState = true;
}
