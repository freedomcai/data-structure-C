#ifndef DLL_H
#define DLL_H
#include <stdbool.h> 

typedef int DataType;
 
typedef struct DNode{
  DataType data;
  struct DNode* prior, *next;
}DNode, *DLinkList;

bool DLL_InitList(DLinkList* L);
bool DLL_isEmpty(DLinkList L);

DLinkList DLL_ListTailInsert(DLinkList* L);
DLinkList DLL_ListHeadInsert(DLinkList* L);

bool DLL_InsertNextNode(DNode* p, DNode* s);
bool DLL_DeleteNextNode(DNode* p);

DNode* DLL_GetNode(DLinkList L, int i);
void DLL_BackwardTraversal(DNode* p);
void DLL_ForwardTraversal(DNode* p);

void DLL_DestroyList(DLinkList* L);

#endif
