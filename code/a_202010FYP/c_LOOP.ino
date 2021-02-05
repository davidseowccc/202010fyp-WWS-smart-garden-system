//*****loop *****

void loop() {
  voltageSense();
  control();
  sonarSense(trigPin1, echoPin1);
  sensor1 = distance;
  sonarSense(trigPin2, echoPin2);
  sensor2 = distance;
  sonarSense(trigPin3, echoPin3);
  sensor3 = distance;
  sonarSense(trigPin4, echoPin4);
  sensor4 = distance;

  //printCheck();

  orderAssign();
  orderCheck();
  outputSeq();
}
