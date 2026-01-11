#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"


bool DLL_InitList(DLinkList* L){
  *L = (DNode*)malloc(sizeof(DNode));
  if(*L == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  (*L)->prior = NULL;
  (*L)->next = NULL;
  return true;
}

bool DLL_isEmpty(DLinkList L){
  if(L->next == NULL) return true;
  else return false;
}

DLinkList DLL_ListTailInsert(DLinkList* L){
  int x;
  *L = (DLinkList)malloc(sizeof(DNode));
  (*L)->next = NULL;
  (*L)->prior = NULL;
  DNode* s, *r = *L;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->prior = r;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
  return *L;
}

DLinkList DLL_ListHeadInsert(DLinkList* L){
  int x;
  *L = (DLinkList)malloc(sizeof(DNode));
  (*L)->next = NULL;
  (*L)->prior = NULL;
  DNode* s;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->prior = (*L);
    s->next = (*L)->next;
    if((*L)->next != NULL) (*L)->next->prior = s;
    (*L)->next = s;
    scanf("%d", &x);
  }
  return *L; 
}

bool DLL_InsertNextNode(DNode* p, DNode* s){
  if(p == NULL || s == NULL) return false;
  s->next = p->next;
  if(p->next != NULL) p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

bool DLL_DeleteNextNode(DNode* p){
  if(p == NULL || p->next == NULL) return false;
  DNode* q = p->next;
  p->next = q->next;
  if(q->next != NULL) q->next->prior = p;
  free(p);
  return true;
}

DNode* DLL_GetNode(DLinkList L, int i){
  DNode* cur = L->next;
  while(--i && cur != NULL){
    cur = cur->next;
  }
  return cur;
}

void DLL_BackwardTraversal(DNode* p){
  if(p->next == NULL) printf("This is NULL!\n");
  DNode* cur = p->next;
  while(cur != NULL){
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

void DLL_ForwardTraversal(DNode* p){
  if(p->prior == NULL) printf("This is NULL!\n");
  DNode* cur = p->prior;
  while(cur->prior != NULL){
    printf("%d ", cur->data);
    cur = cur->prior;
  }
}

void DLL_DestroyList(DLinkList* L){
  while((*L)->next != NULL){
    DLL_DeleteNextNode(*L);
  }
  free(*L);
  *L = NULL;
}



