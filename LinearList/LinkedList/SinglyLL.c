#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

bool LL_InitList(LinkList* L){
  *L = (LNode*)malloc(sizeof(LNode));
  if(*L == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  (*L)->next = NULL;
  return true;
}

LinkList LL_ListTailInsert(LinkList* L){
  int x;
  *L = (LinkList)malloc(sizeof(LNode));
  (*L)->next = NULL;
  LNode* s, *r = *L;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = NULL;
  return *L;
}

LinkList LL_ListHeadInsert(LinkList* L){
  int x;
  *L = (LinkList)malloc(sizeof(LNode));
  (*L)->next = NULL;
  LNode* s;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = (*L)->next;
    (*L)->next = s;
    scanf("%d", &x);
  }
  return *L; 
}

bool LL_isEmpty(LinkList L){
  if(L->next == NULL) return true;
  else return false;
}

bool LL_ListInsert(LinkList* L, int i, DataType x){
  //在单链表L的第i（1~L's size)个位置插入元素x
  //如果插入成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  LNode* cur = *L;
//  int j = 0;
//  while(cur != NULL && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  if(i == 1) LL_InsertNextNode(*L, x);
  LNode* cur = LL_GetElem(*L, i-1);
//  if(cur == NULL){
//    printf("插入位置i非法!\n");
//    return false;
//  }
//  LNode* newNode = (LNode*)malloc(sizeof(LNode));
//  newNode->data = x;
//  newNode->next = cur->next;
//  cur->next = newNode;
//  return true;
  return LL_InsertNextNode(cur, x);
}

void HeadInsert(LinkList* L, DataType x){
  LNode* s = (LNode*)malloc(sizeof(LNode));
  s->data = x;
  s->next = (*L)->next;
  (*L)->next = s;
}

void HeadDeleteR(LinkList* L, DataType* x){
  if((*L)->next == NULL) printf("It is already empty!");
  LNode* tmp = (*L)->next;
  *x = tmp->data;
  (*L)->next = tmp->next;
  free(tmp); 
}

void HeadDelete(LinkList* L){
  if((*L)->next == NULL) printf("It is already empty!");
  LNode* tmp = (*L)->next;
  (*L)->next = tmp->next;
  free(tmp);
}


//LinkList List_reverse(LinkList L){
//  //基于头插法思想实现逆置函数
//  if(L == NULL || L->next == NULL || L->next->next == NULL){
//    return L;
//  }
//  // 创建新的头节点（临时）
//  LinkList newHead = (LinkList)malloc(sizeof(LNode));
//  newHead->next = NULL;
//
//  LNode* cur = L->next;
//  LNode* tmp;
//  while(cur != NULL){
//    tmp = cur->next;
//    cur->next = newHead->next;
//    newHead->next = cur;
//    cur = tmp;
//  }
//  L->next = newHead->next;
//  free(newHead);
//  return L;
//}

bool LL_InsertNextNode(LNode* p, DataType x){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  LNode* newNode = (LNode*)malloc(sizeof(LNode));
  if(newNode == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  newNode->data = x;
  newNode->next = p->next;
  p->next = newNode;
  return true;
}

bool LL_InsertPriorNode(LNode* p, DataType x){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  LNode* newNode = (LNode*)malloc(sizeof(LNode));
  if(newNode == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  newNode->data = p->data;
  newNode->next = p->next;
  p->next = newNode;
  p->data = x;
  return true;
}

bool LL_ListDeleteR(LinkList* L, int i, DataType* x){
  //在单链表L的第i（1~L's size)个位置删除元素x
  //如果删除成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  LNode* cur = *L;
//  int j = 0;
//  while(cur != NULL && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  LNode* cur = LL_GetElem(*L, i-1);
  if(cur == NULL || cur->next == NULL){
    printf("删除位置i非法!\n");
    return false;
  }
  LNode* tmp = cur->next;
  *x = tmp->data;
  cur->next = tmp->next;
  free(tmp);
  return true;
}

bool LL_ListDelete(LinkList* L, int i){
  //在单链表L的第i（1~L's size)个位置删除元素x
  //如果删除成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  LNode* cur = *L;
//  int j = 0;
//  while(cur != NULL && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  LNode* cur = LL_GetElem(*L, i-1);
  if(cur == NULL || cur->next == NULL){
    printf("删除位置i非法!\n");
    return false;
  }
  LNode* tmp = cur->next;
  cur->next = tmp->next;
  free(tmp);
  return true;
}

//不能删除最后一个元素
bool LL_DeleteNode(LNode* p){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  LNode* tmp = p->next;
  if(tmp != NULL){
    p->data = tmp->data;
    p->next = tmp->next;
  }
  free(tmp);
  return true;
}

LNode* LL_GetElem(LinkList L, int i){
  //在单链表L的第i（1~L's size)个位置查找元素x
  //如果查找成功，返回LNode*，否则返回NULL
  if(i < 1){
    printf("插入位置i非法!\n");
    return NULL;
  }
  LNode* cur = L;
  int j = 0;
  while(cur != NULL && j < i){
    cur = cur->next;
    ++j;
  }
  return cur;
}

LNode* LL_LocateElem(LinkList L, DataType x){
  LNode* cur = L->next;
  while(cur != NULL && cur->data != x) cur = cur->next;
  return cur;
}

int LL_Length(LinkList L){
  int len = 0;
  LNode* cur = L;
  while(cur->next != NULL){
    cur = cur->next;
    ++len;
  }
  return len;
}

void LL_PrintList(LinkList L){
  LNode* cur = L->next;
  while(cur != NULL){
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
  printf("LL_Length is %d\n", LL_Length(L));
}

void LL_reverseList(LinkList L){
  if(L == NULL || L->next == NULL || L->next->next == NULL){
    return;
  }
  LNode* pre = NULL, *cur = L->next;
  while(cur != NULL){
    LNode* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  L->next = pre;
}


