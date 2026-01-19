#include "LS.h"
#include <stdio.h>

void LS_InitStack(LinkStack* S){
  LL_InitList(&S->ll);
  S->top = -1;
}

bool LS_IsEmpty(LinkStack S){
  if(S.top == -1) return true;
  else return false;
}

int LS_Size(LinkStack S){
  if(S.top == -1) return 0;
  else return S.top;
}

bool LS_Push(LinkStack* S, DataType x){
  HeadInsert(&S->ll, x);
  ++S->top;
  return true;
}

bool LS_PopR(LinkStack* S, DataType* x){
  HeadDeleteR(&S->ll, x);
  --S->top;
  return true;
}

bool LS_Pop(LinkStack* S){
  HeadDelete(&S->ll);
  --S->top;
  return true;
}

bool LS_GetTop(LinkStack S, DataType* x){
  *x = S.ll->next->data;
  return true;
}

void LS_PrintStack(LinkStack S){
  if (LS_IsEmpty(S)){
    printf("栈为空\n");
    return;
  } 
  printf("栈内容（从栈顶到栈底）: ");
  LNode* p = S.ll->next;  // 跳过头节点
  while (p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n"); 
}


