#ifndef LS_H
#define LS_H
#include "LL.h"

typedef struct{
  LinkList ll; 
  int top;
}LinkStack;

void LS_InitStack(LinkStack* S);
bool LS_IsEmpty(LinkStack S);

int LS_Size(LinkStack S);

bool LS_Push(LinkStack* S, DataType x);

bool LS_PopR(LinkStack* S, DataType* x);
bool LS_Pop(LinkStack* S);

bool LS_GetTop(LinkStack S, DataType* x);
void LS_PrintStack(LinkStack S);

#endif
