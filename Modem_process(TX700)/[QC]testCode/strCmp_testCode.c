#include <stdio.h>
#include <stdint.h>

const uint8_t OK_MSG[] = "OK";
uint8_t test_arr1[] = "asonwosmldO KshuOqnwjKa!@#ZXC<>)<";
uint8_t test_arr2[] = "asonwosmldshuOqnwjKa!@#ZXC<>OK";
uint8_t test_arr3[] = "asonwosmldOKshuOqnwjKa!@#ZXC<>)<";
uint8_t test_arr4[] = "OKonwosmldO<>)<";

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
int main()
{
    printf("Hello World\r\n");
    uint8_t k = 2;
    k=strCmp(OK_MSG,test_arr1,sizeof(test_arr1),2);// not found
    printf("CASE 1 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr2,sizeof(test_arr2),2);
    printf("CASE 2 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr3,sizeof(test_arr3),2);
    printf("CASE 3 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr4,sizeof(test_arr4),2);
    printf("CASE 4 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr2,sizeof(test_arr2)-2,2);// not found
    printf("CASE 5 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr2,sizeof(test_arr2),0);// not found
    printf("CASE 6 :%d\r\n",k);
    k=strCmp(OK_MSG,0,sizeof(test_arr2),0);// compile Error
    printf("CASE 7 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr2,sizeof(test_arr2),3);
    printf("CASE 8 :%d\r\n",k);
    k=strCmp(0,test_arr2,sizeof(test_arr2),3);
    printf("CASE 9 :%d\r\n",k);
    k=strCmp(OK_MSG,test_arr2,0,2);// not found
    printf("CASE 10 :%d\r\n",k);
    return 0;
}