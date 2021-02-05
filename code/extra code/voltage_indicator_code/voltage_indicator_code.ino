const int voltageInput = A0;
float voltage = 0;
float Vin = 0;

void setup() {
  Serial.begin(9600);
  pinMode(voltageInput, INPUT);
}

void loop() {
  voltage = analogRead(voltageInput);
  Serial.println(voltage);
  Vin = voltage/53.285714;
  Serial.print("Voltage: ");
  Serial.println(Vin);
  delay(1000);
}
