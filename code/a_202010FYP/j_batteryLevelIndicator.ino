//*****function to display the appropriate LEDs equivalent to the battery level*****

void batteryLevelIndicator() {
  if (Vin > 11.80) {
    digitalWrite(gLED1, HIGH);
    digitalWrite(gLED2, LOW);
    digitalWrite(yLED1, LOW);
    digitalWrite(yLED2, LOW);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, LOW);
  }
  else if (Vin > 11.30) {
    digitalWrite(gLED1, LOW);
    digitalWrite(gLED2, HIGH);
    digitalWrite(yLED1, LOW);
    digitalWrite(yLED2, LOW);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, LOW);
  }
  else if (Vin > 10.80) {
    digitalWrite(gLED1, LOW);
    digitalWrite(gLED2, LOW);
    digitalWrite(yLED1, HIGH);
    digitalWrite(yLED2, LOW);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, LOW);
  }
  else if (Vin > 10.30) {
    digitalWrite(gLED1, LOW);
    digitalWrite(gLED2, LOW);
    digitalWrite(yLED1, LOW);
    digitalWrite(yLED2, HIGH);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, LOW);
  }
  else if (Vin > 9.80) {
    digitalWrite(gLED1 , LOW);
    digitalWrite(gLED2 , LOW);
    digitalWrite(yLED1 , LOW);
    digitalWrite(yLED2 , LOW);
    digitalWrite(rLED1 , HIGH);
    digitalWrite(rLED2 , LOW);
  }
  else if (Vin > 9.30) {
    digitalWrite(gLED1, LOW);
    digitalWrite(gLED2 , LOW);
    digitalWrite(yLED1 , LOW);
    digitalWrite(yLED2 , LOW);
    digitalWrite(rLED1, LOW);
    digitalWrite(rLED2, HIGH);
  }
}
