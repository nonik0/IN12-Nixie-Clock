void serialTick() {
  if (Serial.available() > 0)
  {
    // read input from ESP8266/ESPHome
    String serialIn = Serial.readString();
    static byte savedBrightness = 20;

    switch (serialIn[0])
    {
    case '0':
        anodeStates[0] = 0;
        anodeStates[1] = 0;
        anodeStates[2] = 0;
        anodeStates[3] = 0;

        savedBrightness = indiMaxBright;
        indiMaxBright = 0;
        indiDimm[0] = 0;
        indiDimm[1] = 0;
        indiDimm[2] = 0;
        indiDimm[3] = 0;
      break;
    case '1':
        anodeStates[0] = 1;
        anodeStates[1] = 1;
        anodeStates[2] = 1;
        anodeStates[3] = 1;
        indiMaxBright = savedBrightness;
        indiDimm[0] = indiMaxBright;
        indiDimm[1] = indiMaxBright;
        indiDimm[2] = indiMaxBright;
        indiDimm[3] = indiMaxBright;
      break;

    case 'C':
      for(int i = 0; i < 10; i++)
        burnIndicators();
      break;
    case 'F':
      if (++FLIP_EFFECT >= FLIP_EFFECT_NUM) FLIP_EFFECT = 0;
      EEPROM.put(0, FLIP_EFFECT);
      flipTimer.setInterval(FLIP_SPEED[FLIP_EFFECT]);
      for (byte i = 0; i < 4; i++) {
        indiDimm[i] = indiMaxBright;
        anodeStates[i] = 1;
      }
      newTimeFlag = true;
      for (byte i = 0; i < 4; i++) indiDigits[i] = FLIP_EFFECT;
      break;
    case 'L':
      if (++BACKL_MODE >= 3) BACKL_MODE = 0;
      EEPROM.put(1, BACKL_MODE);
      if (BACKL_MODE == 1) {
        setPWM(BACKL, backlMaxBright);
      } else if (BACKL_MODE == 2) {
        digitalWrite(BACKL, 0);
      }
      break;
    case 'G':
      GLITCH_ALLOWED = !GLITCH_ALLOWED;
      EEPROM.put(2, GLITCH_ALLOWED);
      break;

    case 'h':
      is24Hour = false;
      newTimeFlag = true;
      break;
    case 'H':
      is24Hour = true;
      newTimeFlag = true;
      break;

    case 'T':
      hrs = (serialIn[1] - '0') * 10 + serialIn[2] - '0';
      mins = (serialIn[3] - '0') * 10 + serialIn[4] - '0';
      secs = (serialIn[5] - '0') * 10 + serialIn[6] - '0';
      rtc.adjust(DateTime(2024, 05, 20, hrs, mins, secs));
      newTimeFlag = true;
      break;

    case 'B': 
      unsigned int newDimValue = (serialIn[1] - '0') * 10 + serialIn[2] - '0';
      indiMaxBright = newDimValue > 24 ? 24 : newDimValue;
      indiDimm[0] = indiMaxBright;
      indiDimm[1] = indiMaxBright;
      indiDimm[2] = indiMaxBright;
      indiDimm[3] = indiMaxBright;
      break;


    default:
      break;
    }
  }
}