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
//最好:O(1) 最坏:O(n) 平均:O(n)
bool LL_ListDeleteR(LinkList* L, int i, DataType* x);
bool LL_ListDelete(LinkList* L, int i);
// O(1) 不能删除最后一个节点
bool LL_DeleteNode(LNode* p);

// O(n)
LNode* LL_GetElem(LinkList L, int i);
LNode* LL_LocateElem(LinkList L, DataType x);
int LL_Length(LinkList L); 

#endif
