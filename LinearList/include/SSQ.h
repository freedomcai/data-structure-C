#ifndef SSQ_H
#define SSQ_H
#include "SSL.h"

typedef struct{
  SSeqList ssl;
  int front, rear;
  int cnt;
}SSqQueue;

void SQ_InitQueue(SSqQueue* Q);
bool SQ_IsEmpty(SSqQueue* Q);

int SQ_Size(SSqQueue Q);

bool SQ_Push(SSqQueue* Q, DataType x);

bool SQ_PopR(SSqQueue* Q, DataType* x);
bool SQ_Pop(SSqQueue* Q);

DataType SQ_GetFront(SSqQueue Q);
DataType SQ_GetBack(SSqQueue Q);

void SQ_PrintQueue(SSqQueue Q);

#endif
