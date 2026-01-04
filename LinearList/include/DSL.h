#ifndef DSL_H
#define DSL_h
#include <stdbool.h>

typedef int DataType;

typedef struct {
  DataType* data;
  int size;
  int capacity;  
}DSeqList;

void DSL_InitList(DSeqList* L);

//最好:O(1) 最坏:O(n) 平均:O(n)
bool DSL_ListInsert(DSeqList* L, int i, DataType x);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool DSL_ListDeleteR(DSeqList* L, int i, DataType* x);
bool DSL_ListDelete(DSeqList* L, int i);

// O(1)
DataType DSL_GetElem(DSeqList L, int i);
//最好:O(1) 最坏:O(n) 平均:O(n)
int DSL_LocateElem(DSeqList L, DataType x);

// O(n)
void DSL_PrintList(DSeqList L);

#endif



