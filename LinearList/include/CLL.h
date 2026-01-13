#ifndef CLL_H
#define CLL_H
#include <stdbool.h>

typedef int DataType;

typedef struct CLNode{
  DataType data;
  struct CLNode* next;
}CLNode, *CLinkList;

bool CLL_InitList(CLinkList* L);
bool CLL_isEmpty(CLinkList L);
bool CLL_isTail(CLinkList L, CLNode* p);
CLNode* CLL_ReturnTail(CLinkList L);

// O(1)
bool CLL_InsertNextNode(CLNode* p, DataType x);
// O(n)
bool CLL_InsertPriorNode(CLNode* p, DataType x);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool CLL_ListInsert(CLinkList* L, int i, DataType x);
CLinkList CLL_ListTailInsert(CLinkList* L);
CLinkList CLL_ListHeadInsert(CLinkList* L);
//LinkList CList_reverse(CLinkList L);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool CLL_ListDeleteR(CLinkList* L, int i, DataType* x);
bool CLL_ListDelete(CLinkList* L, int i);
// O(n)
bool CLL_DeleteNode(CLinkList L, CLNode* p);

// O(n)
CLNode* CLL_GetElem(CLinkList L, int i);
CLNode* CLL_LocateElem(CLinkList L, DataType x);
int CLL_Length(CLinkList L); 
void CLL_PrintList(CLinkList L);
void CLL_reverseList(CLinkList L);

#endif
