//*****function for the output sequence*****

void outputSeq() {
  lightSense();
  if ((pirState == true) || (gate1State == true) || (gate2State == true)) { //timer starts
    play();
    if (lightState == false) {
      digitalWrite(relayK1, LOW);
      digitalWrite(relayK2, LOW);
      digitalWrite(relayK3, LOW);
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
  if (timerCount == delayDuration) { //timer ends
    digitalWrite(relayK1, HIGH);
    digitalWrite(relayK1, HIGH);
    digitalWrite(relayK2, HIGH);
    digitalWrite(relayK12, HIGH);
    digitalWrite(relayK13, HIGH);
    digitalWrite(relayK14, HIGH);
    digitalWrite(relayK15, HIGH);
    digitalWrite(relayK16, HIGH);
    digitalWrite(relayK17, HIGH);
    digitalWrite(relayK18, HIGH);
  }
  pirState = false;
  gate1State = false;
  gate2State = false;
}
