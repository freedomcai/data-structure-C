#ifndef SSS_H
#define SSS_H
#include "SSL.h"

typedef struct{
  SSeqList ssl; 
  int top;
}SSqStack;

void SS_InitStack(SSqStack* S);
bool SS_IsEmpty(SSqStack S);

int SS_Size(SSqStack S);

bool SS_Push(SSqStack* S, DataType x);

bool SS_PopR(SSqStack* S, DataType* x);
bool SS_Pop(SSqStack* S);

bool SS_GetTop(SSqStack S, DataType* x);
void SS_PrintStack(SSqStack S);


#endif
