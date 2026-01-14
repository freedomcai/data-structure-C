#include <stdio.h>
#include <stdlib.h>
#include "CDLL.h"

bool CDLL_InitList(CDLinkList* L){
  *L = (CDNode*)malloc(sizeof(CDNode));
  if(*L == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  (*L)->prior = *L;
  (*L)->next = *L;
  return true;
}

bool CDLL_isEmpty(CDLinkList L){
  if(L->next == L) return true;
  else return false;
}

bool CDLL_isTail(CDLinkList L, CDNode* p){
  if(p->next == L) return true;
  else return false;
}

CDNode* CDLL_ReturnTail(CDLinkList L){
  CDNode* cur = L;
  while(!CDLL_isTail(L, cur)){
    cur = cur->next;
  }
  return cur;
}

CDLinkList CDLL_ListTailInsert(CDLinkList* L){
  int x;
  *L = (CDLinkList)malloc(sizeof(CDNode));
  (*L)->next = *L;
  (*L)->prior = *L;
  CDNode* s, *r = *L;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (CDNode*)malloc(sizeof(CDNode));
    s->data = x;
    s->prior = r;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = *L;
  (*L)->prior = r;
  return *L;
}

CDLinkList CDLL_ListHeadInsert(CDLinkList* L){
  int x;
  *L = (CDLinkList)malloc(sizeof(CDNode));
  (*L)->next = *L;
  (*L)->prior = *L;
  CDNode* s;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (CDNode*)malloc(sizeof(CDNode));
    s->data = x;
    s->prior = (*L);
    s->next = (*L)->next;
    (*L)->next->prior = s;
    (*L)->next = s;
    scanf("%d", &x);
  }
  return *L; 
}

bool CDLL_InsertNextNode(CDNode* p, CDNode* s){
  if(p == NULL || s == NULL) return false;
  s->next = p->next;
  p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

bool CDLL_DeleteNextNode(CDNode* p){
  if(p == NULL || p->next == NULL) return false;
  CDNode* q = p->next;
  p->next = q->next;
  q->next->prior = p;
  free(q);
  return true;
}

CDNode* CDLL_GetNode(CDLinkList L, int i){
  CDNode* cur = L->next;
  while(--i && cur != L){
    cur = cur->next;
  }
  return cur;
}

void CDLL_BackwardTraversal(CDLinkList L, CDNode* p){
  if(p->next == L) printf("This is NULL!\n");
  CDNode* cur = p->next;
  while(cur != L){
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

void CDLL_ForwardTraversal(CDLinkList L, CDNode* p){
  if(p->prior == L) printf("This is NULL!\n");
  CDNode* cur = p->prior;
  while(cur != L){
    printf("%d ", cur->data);
    cur = cur->prior;
  }
}

void CDLL_DestroyList(CDLinkList* L){
  while((*L)->next != *L){
    CDLL_DeleteNextNode(*L);
  }
  free(*L);
  *L = NULL;
}



