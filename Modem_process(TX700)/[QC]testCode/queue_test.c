#include <stdio.h>
#include <stdint.h>


int main()
{
    printf("Hello World");
    uint8_t k = 2;
    printf("%d",k);
    return 0;
}
#define Q_SIZE 256

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

uint8_t isEmpty(CirQueue* q){
  if((q->rear - q->front)>0){
    return 1;//not empty
  }
  return 0;// empty
}
uint8_t isFull(CirQueue* q){
  if(((q.rear +1)%Q_SIZE) != q.front){
    return 1;//not full
  }
  return 0;//full
}
void pushQueue(CirQueue* q,uint8_t num)
{
  q->rear = (q->rear+1) % Q_SIZE;
  circular_Queue[q->rear]=num;
}
uint8_t popQueue(CirQueue* q){
  q->front = (q->front+1) % Q_SIZE;
  return circular_Queue[q->front];
}