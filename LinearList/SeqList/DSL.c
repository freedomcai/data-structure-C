#include "DSL.h"
#include <stdio.h>
#include <stdlib.h>

void DSL_InitList(DSeqList* L){
  L->data = (DataType*)malloc(10 * sizeof(DataType)); // 初始容量为10
  if (L->data == NULL) {
    printf("内存分配失败!\n");
    exit(1);
  }
  L->size = 0;
  L->capacity = 10;
}

bool DSL_ListInsert(DSeqList* L, int i, DataType x){
  // 在顺序表L的第i（1~size + 1)个位置前插入元素x
  // 如果插入成功，返回1，否则返回0
  if (i < 1 || i > L->size + 1) {
    printf("插入位置i非法!\n");
    return false;
  }
  if (L->size >= L->capacity) {
    // 扩展容量
    L->capacity *= 2;
    L->data = (DataType*)realloc(L->data, L->capacity * sizeof(DataType));
    if (L->data == NULL) {
      printf("内存分配失败!\n");
      exit(1);
    }
  }
  for (int j = L->size; j >= i;--j) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i-1] = x;
  ++L->size;
  return true;
}

bool DSL_ListDeleteR(DSeqList* L, int i, DataType* x){
  // 删除顺序表L的第i（1~size)个位置的元素，并用x返回
  // 如果删除成功，返回1，否则返回0
  if (L->size <= 0) {
    printf("顺序表已空无法删除!\n");
    return false;
  }
  if (i < 1 || i > L->size) {
    printf("删除位置i非法!\n");
    return false;
  }
  *x = L->data[i-1];
  for (int j = i; j < L->size;++j) {
    L->data[j-1] = L->data[j];
  }
  --L->size;
  return true;
}

bool DSL_ListDelete(DSeqList* L, int i){
  // 删除顺序表L的第i（1~size)个位置的元素，并用x返回
  // 如果删除成功，返回1，否则返回0
  if (L->size <= 0) {
    printf("顺序表已空无法删除!\n");
    return false;
  }
  if (i < 1 || i > L->size) {
    printf("删除位置i非法!\n");
    return false;
  }
  for (int j = i; j < L->size;++j) {
    L->data[j-1] = L->data[j];
  }
  --L->size;
  return true;
}

DataType DSL_GetElem(DSeqList L, int i){
  //获取顺序表L的第i（1~size)个位置的元素，并用x返回
  //如果获取成功，返回data[i-1]，否则返回0
  if (i < 0 || i >= L.size) {
    printf("获取位置i非法!\n");
    return 0;
  }
  return L.data[i-1];
}

int DSL_LocateElem(DSeqList L, DataType x){
  //获取顺序表L（1~size）中的第1个位置等于x的元素
  //如果获取成功，返回i，否则返回0
  for(int i = 0;i < L.size;++i){
    if(L.data[i] == x) return i+1;
  }
  return 0;
}

void DSL_PrintList(DSeqList L){
  for(int j = 0;j < L.size;++j) printf("%d ", (int)L.data[j]);
}



