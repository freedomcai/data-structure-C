#include "SSL.h"
#include <stdio.h>

void InitList(SSeqList* L){
  for(int i = 0;i < MaxSize;++i){
    L->list[i] = 0;
  }
  L->size = 0;
}

bool ListInsert(SSeqList* L, int i, DataType x){
  //在顺序表L的第i（1~size + 1)个位置前插入元素x
  //如果插入成功，返回1，否则返回0
  if (L->size >= MaxSize) {
    printf("顺序表已满无法插入!\n");
    return false;
  }
  if (i < 1 || i > L->size + 1) {
    printf("插入位置i非法!\n");
    return false;
  }

  for (int j = L->size; j >= i; --j) {
    L->list[j] = L->list[j - 1];
  }
  L->list[i-1] = x;
  ++L->size;
  return true;
}

bool ListDeleteR(SSeqList* L, int i, DataType* x){
  //删除顺序表L的第i（1~size)个位置的元素，并用x返回
  //如果删除成功，返回1，否则返回0
  if (L->size <= 0) {
    printf("顺序表已空无法删除!\n");
    return false;
  }
  if (i < 1 || i > L->size) {
    printf("删除位置i非法!\n");
    return false;
  }
  
  *x = L->list[i-1];
  for(int j = i;j < L->size;++j){
    L->list[j-1] = L->list[j]; 
  }
  --L->size;
  return true;
}

bool ListDelete(SSeqList* L, int i){
  //删除顺序表L的第i（1~size)个位置的元素
  //如果删除成功，返回1，否则返回0
  if (L->size <= 0) {
    printf("顺序表已空无法删除!\n");
    return false;
  }
  if (i < 1 || i > L->size) {
    printf("删除位置i非法!\n");
    return false;
  }
  
  for(int j = i;j < L->size;++j){
    L->list[j-1] = L->list[j]; 
  }
  --L->size;
  return true;
}


