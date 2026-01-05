#ifndef SSL_H
#define SSL_H
#include <stdbool.h>

#define MaxSize 100

typedef int DataType;

typedef struct {
  DataType list[MaxSize];
  int size;   
}SSeqList;

void SSL_InitList(SSeqList* L);

//最好:O(1) 最坏:O(n) 平均:O(n)
bool SSL_ListInsert(SSeqList* L, int i, DataType x);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool SSL_ListDeleteR(SSeqList* L, int i, DataType* x);
bool SSL_ListDelete(SSeqList* L, int i);

// O(1)
DataType SSL_GetElem(SSeqList L, int i);
//最好:O(1) 最坏:O(n) 平均:O(n)
int SSL_LocateElem(SSeqList L, DataType x);

// O(n)
void SSL_PrintList(SSeqList L);

#endif



