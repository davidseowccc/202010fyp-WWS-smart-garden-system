//*****function to sense light in the garden*****

void lightSense() {
  lightLevel1 = analogRead(ldrPin1);
  lightLevel2 = analogRead(ldrPin2);
  lightLevel3 = analogRead(ldrPin3);
  lightLevel4 = analogRead(ldrPin4);

  if ((lightLevel1 <= lightValue1) || (lightLevel2 <= lightValue2) || (lightLevel3 <= lightValue3) || (lightLevel4 <= lightValue4)) {
    lightState = false; //garden is dark
  }
  else {
    lightState = true; //garden is bright
  }
}
