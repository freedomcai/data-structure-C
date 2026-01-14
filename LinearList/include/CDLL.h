#ifndef CDLL_H
#define CDLL_H
#include <stdbool.h> 

typedef int DataType;
 
typedef struct CDNode{
  DataType data;
  struct CDNode* prior, *next;
}CDNode, *CDLinkList;

bool CDLL_InitList(CDLinkList* L);
bool CDLL_isEmpty(CDLinkList L);
bool CDLL_isTail(CDLinkList L, CDNode* p);
CDNode* CDLL_ReturnTail(CDLinkList L);

CDLinkList CDLL_ListTailInsert(CDLinkList* L);
CDLinkList CDLL_ListHeadInsert(CDLinkList* L);

bool CDLL_InsertNextNode(CDNode* p, CDNode* s);
bool CDLL_DeleteNextNode(CDNode* p);

CDNode* CDLL_GetNode(CDLinkList L, int i);
void CDLL_BackwardTraversal(CDLinkList L, CDNode* p);
void CDLL_ForwardTraversal(CDLinkList L, CDNode* p);

void CDLL_DestroyList(CDLinkList* L);

#endif
