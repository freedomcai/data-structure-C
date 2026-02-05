#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

void InitList(LinkList* L){
  L->tail = NULL;
  L->size = 0;
}

bool LL_isEmpty(LinkList L){
  if(L->size == 0) return true;
  else return false;
}

void HeadDelete(LinkList* L){
  if(L->tail == NULL){
    printf("It is already empty!");
    return;
  }
  
  LNode* head = L->tail->next;
  if(head == L->tail){
    free(L->tail);
    InitList(L);
    return;
  }
  L->tail->next = head->next;
  free(head);
}

void TailInsert(LinkList* L, DataType x){
  LNode* s = (LNode*)malloc(sizeof(LNode));
  s->data = x;
  if(L->tail == NULL) s->next = s;
  else{
    s->next = L->tail->next;
    L->tail->next = s;
  }
  L->tail = s;
}

