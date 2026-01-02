#include <stdio.h>
#include "SSL.h"

int main(){
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

  printf("\n");
  return 0;
}
