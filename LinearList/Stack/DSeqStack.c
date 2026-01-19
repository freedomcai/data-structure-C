#include <stdio.h>
#include <stdlib.h>
#include "DSS.h"

int cnt = 0;

void DS_InitStack(DSqStack* S){
  DSL_InitList(S);
}

bool DS_IsEmpty(DSqStack S){
  if(S.size == 0) return true;
  else return false;
}

int DS_Size(DSqStack S){
  if(S.size == 0) return 0;
  return S.size - 1;
}

bool DS_Push(DSqStack* S, DataType x){
  if(S->size >= S->capacity){
    // 扩展容量
    S->capacity *= 2;
    S->data = (DataType*)realloc(S->data, S->capacity * sizeof(DataType));
    if (S->data == NULL) {
      printf("内存分配失败!\n");
      exit(1);
    }
    cnt++;
  }
  S->data[S->size++] = x;
  return true;
}

bool DS_PopR(DSqStack* S, DataType* x){
  if(S->size == 0) return false;
  *x = S->data[--S->size];
  return true;
}

bool DS_Pop(DSqStack* S){
  if(S->size == 0) return false;
  --S->size;
  return true;
}

bool DS_GetTop(DSqStack S, DataType* x){
  if(S.size == 0) return false;
  *x = S.data[--S.size];
  return true;
}

void DS_PrintStack(DSqStack S){
  if(S.size == 0) return;
  int tmp = 0;
  while(!DS_IsEmpty(S)){
    if(DS_GetTop(S, &tmp)) printf("%d ", tmp);
    DS_Pop(&S);
  }
  printf("\n");
  printf("The expansion cnt is %d \n", cnt);
  printf("The capacity is %d", S.capacity);
}


