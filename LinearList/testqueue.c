#include <stdio.h>
#include "SSQ.h"
#include "LQ.h"

void test01();
void test02();
void test03();

int main(){
  //test01();
  test02();
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

void test02(){
  LinkQueue q2;
  LQ_InitQueue(&q2);
  for(int i = 1;i < 101;++i){
    LQ_Push(&q2, i);
  }
  LQ_PrintQueue(q2);
  printf("\n");
  while(!LQ_IsEmpty(q2)){
    LQ_Pop(&q2);
  }
  for(int i = 1;i < 51;++i){
    LQ_Push(&q2, i);
  }
  LQ_PrintQueue(q2);
  printf("\n");
  printf("%d", q2.size);
  printf("first is %d, last is %d\n", 
    LQ_GetFront(q2),
    LQ_GetBack(q2));
}



