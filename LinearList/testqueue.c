#include <stdio.h>
#include "SSQ.h"


void test01();
void test02();
void test03();

int main(){
  test01();
  //test02();
  //test03();

  printf("\n");
  return 0;
}

void test01(){
  SSqQueue q1;
  SQ_InitQueue(&q1);
  for(int i = 1;i < 101;++i){
    SQ_Push(&q1, i);
  }
  SQ_PrintQueue(q1);
  printf("\n");
  while(!SQ_IsEmpty(&q1)){
    SQ_Pop(&q1);
  }
  for(int i = 1;i < 51;++i){
    SQ_Push(&q1, i);
  }
  SQ_PrintQueue(q1);
  printf("\n");
  printf("%d", q1.cnt);
}


