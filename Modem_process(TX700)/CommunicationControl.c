const uint8_t OK_MSG[] = "OK";

uint8_t strCmp(void* target, const void* stringArray, uint16_t searchSize, uint16_t targetSize){
  uint8_t* tar  = target;
  const uint8_t* sArr = stringArray;
  uint16_t serS = searchSize;
  uint16_t tarS = targetSize;
  if(serS == 0){
    return 0xFF;  
  }
  if(tarS == 0){
      return 0xFF;
  }
  if(tarS > serS){
      return 0xFF;
  }
  while(serS >0){
    serS--;
    
    if(tarS > serS+1){
      return 0xFF;
    }
    if(*sArr++ != *tar){
        tar = target;
        tarS = targetSize;
        continue;
    }
    tar++;
    tarS--;
    if(tarS > 0){continue;}
    return 0;
  }
  return 0x1;
}