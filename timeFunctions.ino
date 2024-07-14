// отправить на индикаторы
void sendTime(byte hours, byte minutes) {
  byte hoursAdj = IS_24_HOUR                   
    ? hours                  
    : (hours + 11) % 12 + 1; 
  indiDigits[0] = (byte)hoursAdj / 10;
  indiDigits[1] = (byte)hoursAdj % 10;

  indiDigits[2] = (byte)minutes / 10;
  indiDigits[3] = (byte)minutes % 10;
}

// для эффектов
void setNewTime() {
  byte hoursAdj = IS_24_HOUR                   
    ? hrs                  
    : (hrs + 11) % 12 + 1; 
  newTime[0] = (byte)hoursAdj / 10;
  newTime[1] = (byte)hoursAdj % 10;

  newTime[2] = (byte)mins / 10;
  newTime[3] = (byte)mins % 10;
}
