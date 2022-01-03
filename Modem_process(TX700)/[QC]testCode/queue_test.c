#include <stdio.h>
#include <stdint.h>


#define Q_SIZE 1024

#if Q_SIZE > 256
typedef struct{
  uint16_t rear;
  uint16_t front;
  uint8_t buf[Q_SIZE];
}CirQueue;
#else 
typedef struct{
  uint8_t rear;
  uint8_t front;
  uint8_t buf[Q_SIZE];
}CirQueue;
#endif

uint16_t nofComponent(CirQueue* q){
  if((q->rear > q->front)){
    return (q->rear - q->front);//non zero
  }else{
    return (Q_SIZE + q->rear - q->front);// include zero
  }
}
uint8_t isFull(CirQueue* q){
  if(((q->rear +1)%Q_SIZE) != q->front){
    return 1;//not full
  }
  return 0;//full
}
void pushQueue(CirQueue* q,uint8_t num)
{
  q->rear = (q->rear+1) % Q_SIZE;
  q->buf[q->rear]=num;
}
uint8_t popQueue(CirQueue* q){
  q->front = (q->front+1) % Q_SIZE;
  return q->buf[q->front];
}

CirQueue mq={0,};
uint8_t msg[] = "OK";
int main()
{
    printf("Hello World");
    uint16_t k = 2;
    for(k=0;k<Q_SIZE;k++){
        printf("%d\r\n",nofComponent(&mq));
        pushQueue(&mq,(uint8_t)k&0xFF);
    }
    return 0;
}