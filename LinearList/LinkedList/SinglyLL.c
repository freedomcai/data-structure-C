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
  LNode* cur = *L;
  int j = 0;
  while(cur != NULL && j < i - 1){
    cur = cur->next;
    ++j;
  }
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



