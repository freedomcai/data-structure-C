#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"

bool CLL_InitList(CLinkList* L){
  *L = (CLNode*)malloc(sizeof(CLNode));
  if(*L == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  (*L)->next = *L;
  return true;
}

bool CLL_isEmpty(CLinkList L){
  if(L->next == L) return true;
  else return false;
}

bool CLL_isTail(CLinkList L, CLNode* p){
  if(p->next == L) return true;
  else return false;
}

CLNode* CLL_ReturnTail(CLinkList L){
  CLNode* cur = L;
  while(!CLL_isTail(L, cur)){
    cur = cur->next;
  }
  return cur;
}

bool CLL_ListInsert(CLinkList* L, int i, DataType x){
  //在单链表L的第i（1~L's size)个位置插入元素x
  //如果插入成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  CLNode* cur = *L;
//  int j = 0;
//  while(cur != NULL && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  if(i == 1) CLL_InsertNextNode(*L, x);
  CLNode* cur = CLL_GetElem(*L, i-1);
//  if(cur == NULL){
//    printf("插入位置i非法!\n");
//    return false;
//  }
//  CLNode* newNode = (CLNode*)malloc(sizeof(CLNode));
//  newNode->data = x;
//  newNode->next = cur->next;
//  cur->next = newNode;
//  return true;
  return CLL_InsertNextNode(cur, x);
}

CLinkList CLL_ListTailInsert(CLinkList* L){
  int x;
  *L = (CLinkList)malloc(sizeof(CLNode));
  (*L)->next = *L;
  CLNode* s, *r = *L;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (CLNode*)malloc(sizeof(CLNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = *L;
  return *L;
}

CLinkList CLL_ListHeadInsert(CLinkList* L){
  int x;
  *L = (CLinkList)malloc(sizeof(CLNode));
  (*L)->next = *L;
  CLNode* s;

  printf("input -9999 is break!\n");
  scanf("%d", &x);
  while(x != -9999){
    s = (CLNode*)malloc(sizeof(CLNode));
    s->data = x;
    s->next = (*L)->next;
    (*L)->next = s;
    scanf("%d", &x);
  }
  return *L; 
}

//CLinkList CList_reverse(CLinkList L){
//  //基于头插法思想实现逆置函数
//  if(L == L || L->next == L || L->next->next == L){
//    return L;
//  }
//  // 创建新的头节点（临时）
//  LinkList newHead = (CLinkList)malloc(sizeof(CLNode));
//  newHead->next = NULL;
//
//  CLNode* cur = L->next;
//  CLNode* tmp;
//  while(cur != L){
//    tmp = cur->next;
//    cur->next = newHead->next;
//    newHead->next = cur;
//    cur = tmp;
//  }
//  L->next = newHead->next;
//  free(newHead);
//  return L;
//}

bool CLL_InsertNextNode(CLNode* p, DataType x){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  CLNode* newNode = (CLNode*)malloc(sizeof(CLNode));
  if(newNode == NULL){
    printf("内存分配失败!\n");
    return false;
  }
  newNode->data = x;
  newNode->next = p->next;
  p->next = newNode;
  return true;
}

bool CLL_InsertPriorNode(CLNode* p, DataType x){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  CLNode* cur = p->next;
  while(cur->next != p){
    cur = cur->next;
  }
//  CLNode* newNode = (CLNode*)malloc(sizeof(CLNode));
//  if(newNode == NULL){
//    printf("内存分配失败!\n");
//    return false;
//  }
//  newNode->data = x;
//  newNode->next = p;
//  cur->next = newNode;
  CLL_InsertNextNode(cur, x);
  return true;
}

bool CLL_ListDeleteR(CLinkList* L, int i, DataType* x){
  //在单链表L的第i（1~L's size)个位置删除元素x
  //如果删除成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  CLNode* cur = *L;
//  int j = 0;
//  while(cur != *L && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  CLNode* cur = CLL_GetElem(*L, i-1);
  if(cur == *L || cur->next == *L){
    printf("删除位置i非法!\n");
    return false;
  }
  CLNode* tmp = cur->next;
  *x = tmp->data;
  cur->next = tmp->next;
  free(tmp);
  return true;
}

bool CLL_ListDelete(CLinkList* L, int i){
  //在单链表L的第i（1~L's size)个位置删除元素x
  //如果删除成功，返回1，否则返回0
  if(i < 1){
    printf("插入位置i非法!\n");
    return false;
  }
//  CLNode* cur = *L;
//  int j = 0;
//  while(cur != *L && j < i - 1){
//    cur = cur->next;
//    ++j;
//  }
  CLNode* cur = CLL_GetElem(*L, i-1);
  if(cur == *L || cur->next == *L){
    printf("删除位置i非法!\n");
    return false;
  }
  CLNode* tmp = cur->next;
  cur->next = tmp->next;
  free(tmp);
  return true;
}

bool CLL_DeleteNode(CLinkList L, CLNode* p){
  if(p == NULL){
    printf("节点不存在!\n");
    return false;
  }
  CLNode* cur = p->next;
  while(cur->next != p){
    cur = cur->next;
  }
  cur->next = L;
  free(p);
  return true;
}

CLNode* CLL_GetElem(CLinkList L, int i){
  //在单链表L的第i（1~L's size)个位置查找元素x
  //如果查找成功，返回LNode*，否则返回NULL
  if(i < 1){
    printf("插入位置i非法!\n");
    return NULL;
  }
  CLNode* cur = L;
  int j = 0;
  while(cur != L && j < i){
    cur = cur->next;
    ++j;
  }
  return cur;
}


CLNode* CLL_LocateElem(CLinkList L, DataType x){
  CLNode* cur = L->next;
  while(cur != L && cur->data != x) cur = cur->next;
  return cur;
}

int CLL_Length(CLinkList L){
  int len = 0;
  CLNode* cur = L;
  while(cur->next != L){
    cur = cur->next;
    ++len;
  }
  return len;
}

void CLL_PrintList(CLinkList L){
  CLNode* cur = L->next;
  while(cur != L){
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
  printf("CLL_Length is %d\n", CLL_Length(L));
}

void CLL_reverseList(CLinkList L){
  if(L == NULL || L->next == L || L->next->next == L){
    return;
  }
  CLNode* pre = L, *cur = L->next;
  while(cur != L){
    CLNode* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  L->next = pre;
}


