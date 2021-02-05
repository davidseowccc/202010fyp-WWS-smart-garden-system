//*****function to check and control whether the features of the garden can turn on or off*****

void control() {
  switchState = digitalRead(LEDswitch);
  if (switchState == HIGH) {
    batteryLevelIndicator();
  }
  else {
    digitalWrite(gLED1, LOW);
    digitalWrite(gLED2, LOW);
    digitalWrite(yLED1, LOW);
    digitalWrite(yLED2, LOW);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, LOW);
  }

  if (Vin < 9) {
    digitalWrite(relayK18, HIGH);
  }
  else {
    digitalWrite(relayK18, LOW);
  }
}
