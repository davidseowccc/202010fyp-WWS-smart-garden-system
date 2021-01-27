//*****function to assign the order of HC-SR04 sensors*****

void orderAssign(){
  if(sensor1 <= senseValue1){
    orderString1 = orderString1 + "S1";
    return;
  }
  if(sensor2 <= senseValue1){
    orderString1 = orderString1 + "S2";
    return;
  }
  if(sensor3 <= senseValue2){
    orderString2 = orderString2 + "S3";
    return;
  }
  if(sensor4 <= senseValue2){
    orderString2 = orderString2 + "S4";
    return;
  }
}
