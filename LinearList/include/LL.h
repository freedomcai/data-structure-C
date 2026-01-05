#ifndef LL_H
#define LL_H
#include <stdbool.h>

typedef int DataType;

typedef struct LNode{
  DataType data;
  struct LNode* next;
}LNode, *LinkList;

bool LL_InitList(LinkList* L);
bool LL_isEmpty(LinkList L);

// O(1)
bool LL_InsertNextNode(LNode* p, DataType x);
bool LL_InsertPriorNode(LNode* p, DataType x);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool LL_ListInsert(LinkList* L, int i, DataType x);


#endif
