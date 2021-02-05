//*****HC-SR04 Ultrasonic sensor function*****

void sonarSense(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //formula to calculate distance of the sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
}
