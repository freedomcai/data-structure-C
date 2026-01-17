#include <stdio.h>
#include "SSS.h"

void test01();

int main(){
  test01();

  printf("\n");
  return 0;
}

void test01(){
  SSqStack s1;
  SS_InitStack(&s1);
  for(int i = 1;i < 50;++i){
    SS_Push(&s1, i);
  }
  SS_Push(&s1, 1);
  SS_PrintStack(s1);
  printf("\n");

  int cnt = 45;
  while(cnt--){
    SS_Pop(&s1);
  }
  SS_PrintStack(s1);
}



