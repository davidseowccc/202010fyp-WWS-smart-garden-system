//*****function for the output sequence*****

void outputSeq() {
  lightSense();
  if ((pirState == true) || (gate1State == true) || (gate2State == true)) { //timer starts
    play();

    if (lightState == false) {
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
      timerCount = 0;
    }
  }
  if (timerCount == delayDuration) { //timer ends
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
  }
  pirState = false;
  gate1State = false;
  gate2State = false;
}
