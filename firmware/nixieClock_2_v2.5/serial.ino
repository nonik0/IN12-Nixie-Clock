void serialTick() {
  if (Serial.available() > 0)
  {
    // read input from ESP8266/ESPHome
    static String serialIn = Serial.readString();

    switch (serialIn[0])
    {
    case '0':
        anodeStates[0] = 0;
        anodeStates[1] = 0;
        anodeStates[2] = 0;
        anodeStates[3] = 0;
      break;
    case '1':
        anodeStates[0] = 1;
        anodeStates[1] = 1;
        anodeStates[2] = 1;
        anodeStates[3] = 1;
      break;

    case 'h':
      is24Hour = false;
      break;
    case 'H':
      is24Hour = true;
      break;

    case 'T':
      hrs = (serialIn[1] - '0') * 10 + serialIn[2] - '0';
      mins = (serialIn[3] - '0') * 10 + serialIn[4] - '0';
      secs = (serialIn[5] - '0') * 10 + serialIn[6] - '0';

    case 'B:':
      uint8_t newDim = (serialIn[1] - '0') * 10 + serialIn[2] - '0';
      newDim = newDim > 24 ? 24 : newDim;
      indiDimm[0] = newDim;
      indiDimm[1] = newDim;
      indiDimm[2] = newDim;
      indiDimm[3] = newDim;

    default:
      break;
    }
  }
}