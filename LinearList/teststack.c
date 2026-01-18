#include <stdio.h>
#include "SSS.h"
#include "DSS.h"

void test01();
void test02();

int main(){
  //test01();
  test02();

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

void test02(){
  DSqStack s2;
  DS_InitStack(&s2);
  for(int i = 1;i < 50;++i){
    DS_Push(&s2, i);
  }
  DS_Push(&s2, 1);
  DS_PrintStack(s2);
  printf("\n");

  int cnt = 45;
  while(cnt--){
    DS_Pop(&s2);
  }
  DS_PrintStack(s2);
}

