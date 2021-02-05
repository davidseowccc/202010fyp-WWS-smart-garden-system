//*****function to check the order of HC-SR04 sensors*****

void orderCheck() {
    if (orderString1 == "S1S2") {
      Serial.println("Gate 1: Entry Detected.");
      gate1State = true;
      orderString1 = "";
      delay(200);
    }
    if (orderString1 == "S2S1") {
      Serial.println("Gate 1: Exit Detected.");
      orderString1 = "";
      delay(200);
    }
    if (orderString1 == "S1S1") {
      orderString1 = "S1";
    }
    if (orderString1 == "S2S2") {
      orderString1 = "S2";
    }

  if(orderString2 == "S3S4"){
      Serial.println("Gate 2: Entry Detected.");
      gate2State = true;
      orderString2 = "";
      delay(200);
  }
  if(orderString2 == "S4S3"){
    Serial.println("Gate 2: Exit Detected.");
      orderString2 = "";
      delay(200);
  }
  if(orderString2 == "S3S3"){
    orderString2 = "S3";
  }
  if(orderString2 == "S4S4"){
    orderString2 = "S4";
  }

  if (orderString1.length() < 4)
    orderCache1++;
  if (orderCache1 > 15) {
    orderString1 = "";
    orderCache1 = 0;
  }
  if (orderString2.length() < 4)
    orderCache2++;
  if (orderCache2 > 15) {
    orderString2 = "";
    orderCache2 = 0;
  }
}
