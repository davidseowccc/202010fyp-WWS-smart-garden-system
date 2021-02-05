//******function to sense the voltage level of the battery (battery capacity)*****

void voltageSense(){
  voltage = analogRead(voltageInput);
  Vin = voltage/53.285714;
}
