//*****mp3 player functions*****

void playFirst() {
  execute_CMD(0x3F, 0, 0);
  delay(500);
  setVolume(20);
  delay(500);
  execute_CMD(0x08, 0, 2);
  delay(500);
}

void pause() {
  execute_CMD(0x0E, 0, 0);
  delay(500);
}

void play() {
  execute_CMD(0x0D, 0, 1);
  delay(500);
}

void playNext() {
  execute_CMD(0x01, 0, 1);
  delay(500);
}

void playPrevious() {
  execute_CMD(0x02, 0, 1);
  delay(500);
}

void setVolume(int volume) {
  execute_CMD(0x06, 0, volume); // Set the volume (0x00~0x30)
  delay(2000);
}

// Excecute the command and parameters
void execute_CMD(byte CMD, byte Par1, byte Par2) {
  // Calculate the checksum (2 bytes)
  word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
  // Build the command line
  byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
                            Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte
                          };
  //Send the command line to the module
  for (byte k = 0; k < 10; k++) {
    mySerial.write( Command_line[k]);
  }
}
