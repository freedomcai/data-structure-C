#ifndef SLL_H
#define SLL_H
#include <stdbool.h>

#define MaxSize 100

typedef int DataType;

typedef struct Node{
  DataType data;
  int next;
}Node;

typedef struct {
    Node nodes[MaxSize];  // 所有结点
    int head;             // 主链表头结点下标（通常为0）
    int avail;            // 空闲链表头结点下标
}SLinkList;

void SLL_InitList(SLinkList* L);

// 从空闲链表分配一个结点，返回下标，失败返回-1
int mallocNode(SLinkList* L);
// 释放结点下标p回空闲链表
void freeNode(SLinkList* L, int p);

bool SLL_ListInsert(SLinkList* L, int i, DataType x);
bool SLL_ListDeleteR(SLinkList* L, int i, DataType* x);
bool SLL_ListDelete(SLinkList* L, int i);

int SLL_Locate(SLinkList* L, DataType x);

void SLL_Print(SLinkList* L);
void SLL_PrintAvail(SLinkList* L);

#endif
