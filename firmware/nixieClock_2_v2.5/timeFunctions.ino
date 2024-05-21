// отправить на индикаторы
void sendTime(byte hours, byte minutes) {
  byte hoursAdj = is24Hour                   
    ? hours                  
    : (hours + 11) % 12 + 1; 
  indiDigits[0] = (byte)hoursAdj / 10;
  indiDigits[1] = (byte)hoursAdj % 10;

  indiDigits[2] = (byte)minutes / 10;
  indiDigits[3] = (byte)minutes % 10;
}

// для эффектов
void setNewTime() {
  newTime[0] = (byte)hrs / 10;
  newTime[1] = (byte)hrs % 10;

  newTime[2] = (byte)mins / 10;
  newTime[3] = (byte)mins % 10;
}
