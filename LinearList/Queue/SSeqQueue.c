#include <stdio.h>
#include "SSQ.h"

void SQ_InitQueue(SSqQueue* Q){
  SSL_InitList(&Q->ssl);
  Q->front = Q->rear = 0;
  Q->cnt = 0;
}

bool SQ_IsEmpty(SSqQueue* Q){
  if(Q->rear == Q->front) return true;
  else return false;
}

int SQ_Size(SSqQueue Q){
  return Q.cnt;
}

bool SQ_Push(SSqQueue* Q, DataType x){
  if((Q->rear+1)%MaxSize == Q->front) return false;
  Q->ssl.list[Q->rear] = x;
  Q->rear = (Q->rear+1) % MaxSize;
  ++Q->cnt;
  return true;
}

bool SQ_PopR(SSqQueue* Q, DataType* x){
  if(Q->rear == Q->front) return false;
  *x = Q->ssl.list[Q->front];
  Q->front = (Q->front+1) % MaxSize;
  --Q->cnt;
  return true;
}

bool SQ_Pop(SSqQueue* Q){
  if(Q->rear == Q->front) return false;
  Q->front = (Q->front+1) % MaxSize;
  --Q->cnt;
  return true;
}

DataType SQ_GetFront(SSqQueue Q){
  return Q.ssl.list[Q.front];
}

DataType SQ_GetBack(SSqQueue Q){
  return Q.ssl.list[Q.rear - 1];
}

void SQ_PrintQueue(SSqQueue Q){
  for(int i = Q.front;i != Q.rear;i = (i+1)%MaxSize){
    printf("%d ", Q.ssl.list[i]);
  }
}




