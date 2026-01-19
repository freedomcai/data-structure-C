#ifndef DSS_H
#define DSS_H
#include "DSL.h"

typedef DSeqList DSqStack;

void DS_InitStack(DSqStack* S);
bool DS_IsEmpty(DSqStack S);

int DS_Size(DSqStack S);

bool DS_Push(DSqStack* S, DataType x);

bool DS_PopR(DSqStack* S, DataType* x);
bool DS_Pop(DSqStack* S);

bool DS_GetTop(DSqStack S, DataType* x);
void DS_PrintStack(DSqStack S);

#endif
