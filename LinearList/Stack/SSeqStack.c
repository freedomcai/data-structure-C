#include <stdio.h>
#include "SSS.h"

void SS_InitStack(SSqStack* S){
  S->top = -1;
}

bool SS_IsEmpty(SSqStack S){
  if(S.top == -1) return true;
  else return false;
}

int SS_Size(SSqStack S){
  if(S.top == -1) return 0;
  return S.top;
}

bool SS_Push(SSqStack* S, DataType x){
  if(S->top == MaxSize - 1) return false;
  S->ssl.list[++S->top] = x;
  return true;
}

bool SS_PopR(SSqStack* S, DataType* x){
  if(S->top == -1) return false;
  *x = S->ssl.list[S->top--];
  return true;
}

bool SS_Pop(SSqStack* S){
  if(S->top == -1) return false;
  S->top--;
  return true;
}

bool SS_GetTop(SSqStack S, DataType* x){
  if(S.top == -1) return false;
  *x = S.ssl.list[S.top];
  return true;
}

void SS_PrintStack(SSqStack S){
  if(S.top == -1) return;
  int tmp = 0;
  while(!SS_IsEmpty(S)){
    if(SS_GetTop(S, &tmp)){
      printf("%d ", tmp);
    }
    SS_Pop(&S);
  }
}


