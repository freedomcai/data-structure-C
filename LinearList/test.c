#include <stdio.h>
#include "SSL.h"
#include "DSL.h"

void test01();
void test02();

int main(){
  //test01();
  test02();

  printf("\n");
  return 0;
}

void test01(){
  SSeqList l;
  InitList(&l);

  for(int i = 1;i < 45;++i){
    if(!ListInsert(&l, i, i+8)) break;
  }
  for(int j = 0;j < l.size;++j) printf("%d ", (int)l.list[j]);
  printf("\n");

  for(int k = 21;k > 11;--k){
    if(!ListDelete(&l, k)) break;
  }
  for(int j = 0;j < l.size;++j) printf("%d ", (int)l.list[j]);
}

void test02(){
  DSeqList l1;
  DSL_InitList(&l1);

  for(int i = 1;i < 11;++i){
    if(!DSL_ListInsert(&l1, i, i-1)) break;
  }
  printf("capacity is %d, size is %d\n", l1.capacity, l1.size);
  for(int j = 0;j < l1.size;++j) printf("%d ", (int)l1.data[j]);

  printf("\n");

  for(int i = 11;i < 16;++i){
    if(!DSL_ListInsert(&l1, i, i-1)) break;
  }
  printf("capacity is %d, size is %d\n", l1.capacity, l1.size);
  for(int j = 0;j < l1.size;++j) printf("%d ", (int)l1.data[j]);
}


