#ifndef LQ_H
#define LQ_H
#include "LL.h"

typedef struct{
  LinkList ll; 
  LNode* front,*rear;
  int size;
}LinkQueue;

void LQ_InitQueue(LinkQueue* Q);
bool LQ_IsEmpty(LinkQueue Q);

int LQ_Size(LinkQueue Q);

bool LQ_Push(LinkQueue* Q, DataType x);

bool LQ_PopR(LinkQueue* Q, DataType* x);
bool LQ_Pop(LinkQueue* Q);

DataType LQ_GetFront(LinkQueue Q);
DataType LQ_GetBack(LinkQueue Q);

void LQ_PrintQueue(LinkQueue Q);

#endif
