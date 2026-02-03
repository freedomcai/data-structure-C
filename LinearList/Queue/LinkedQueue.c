#include <stdlib.h>
#include "LQ.h"

void LQ_InitQueue(LinkQueue* Q){
  LL_InitList(&Q->ll);
  Q->front = Q->rear = Q->ll;
  Q->size = 0;
}

bool LQ_IsEmpty(LinkQueue Q){
  if(Q.front == Q.rear) return true;
  else return false;
}

int LQ_Size(LinkQueue Q){
  return Q.size;
}

bool LQ_Push(LinkQueue* Q, DataType x){
  LNode* tmp = (LNode*)malloc(sizeof(LNode));
  tmp->data = x;
  tmp->next = NULL;
  Q->rear->next = tmp;
  Q->rear = tmp;
  ++Q->size;
  return true;
}

bool LQ_PopR(LinkQueue* Q, DataType* x){
  if(Q->front == Q->rear) return false;
  LNode* tmp = Q->front->next;
  *x = tmp->data;
  Q->front->next = tmp->next;
  if(Q->rear == tmp) Q->rear = Q->front;
  free(tmp);
  --Q->size;
  return true;
}

bool LQ_Pop(LinkQueue* Q){
  if(Q->front == Q->rear) return false;
  LNode* tmp = Q->front->next;
  Q->front->next = tmp->next;
  if(Q->rear == tmp) Q->rear = Q->front;
  free(tmp);
  --Q->size;
  return true;
}

DataType LQ_GetFront(LinkQueue Q){
  if(Q.front->next == NULL) return -1;
  return Q.front->next->data;
}

DataType LQ_GetBack(LinkQueue Q){
  if(Q.rear == Q.front) return -1;
  return Q.rear->data;
}

void LQ_PrintQueue(LinkQueue Q){
  LL_PrintList(Q.ll);
}


