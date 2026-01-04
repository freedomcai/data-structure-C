#ifndef SSL_H
#define SSL_H
#include <stdbool.h>

#define MaxSize 100

typedef int DataType;

typedef struct {
  DataType list[MaxSize];
  int size;   
}SSeqList;

void InitList(SSeqList* L);

//最好:O(1) 最坏:O(n) 平均:O(n)
bool ListInsert(SSeqList* L, int i, DataType x);
//最好:O(1) 最坏:O(n) 平均:O(n)
bool ListDeleteR(SSeqList* L, int i, DataType* x);
bool ListDelete(SSeqList* L, int i);

// O(1)
DataType GetElem(SSeqList L, int i);
//最好:O(1) 最坏:O(n) 平均:O(n)
int LocateElem(SSeqList L, DataType x);

// O(n)
void PrintList(SSeqList L);

#endif



