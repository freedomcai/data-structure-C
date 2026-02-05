#ifndef LL_H
#define LL_H
#include <stdbool.h>

typedef char DataType;

typedef struct LNode{
  DataType data;
  struct LNode* next;
}LNode;

typedef struct{
  LNode* tail;
  int size;
}LinkList;

void InitList(LinkList* L);
bool isEmpty(LinkList L);

void HeadDelete(LinkList* L);
void TailInsert(LinkList* L);



#endif
