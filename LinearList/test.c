#include <stdio.h>
#include "SSL.h"
#include "DSL.h"
#include "LL.h"
#include "DLL.h"
#include "CLL.h"

//void test01();
//void test02();
//void test03();
//void test04();

void test05();

int main(){
  //test01();
  //test02();
  //test03();
  //test04();

  test05();

  printf("\n");
  return 0;
}

//void test01(){
//  SSeqList l1;
//  SSL_InitList(&l1);
//
//  for(int i = 1;i < 45;++i){
//    if(!SSL_ListInsert(&l1, i, i+8)) break;
//  }
//  SSL_PrintList(l1);
//
//  printf("\n");
//
//  for(int k = 31;k > 11;--k){
//    if(!SSL_ListDelete(&l1, k)) break;
//  }
//  SSL_PrintList(l1);
//
//  printf("\n");
//
//  for(int j = 9;j < 15;++j){
//    printf("The %d's is %d", j, SSL_GetElem(l1, j));
//  }
//  
//  printf("\n");
//
//  for(int j = 49;j < 53;++j){
//    printf("%d is located in %d", j, SSL_LocateElem(l1, j));
//  }
// }
//
//void test02(){
//  DSeqList l2;
//  DSL_InitList(&l2);
//
//  for(int i = 1;i < 11;++i){
//    if(!DSL_ListInsert(&l2, i, i-1)) break;
//  }
//  printf("capacity is %d, size is %d\n", l2.capacity, l2.size);
//  DSL_PrintList(l2);
//
//  printf("\n");
//
//  for(int i = 11;i < 16;++i){
//    if(!DSL_ListInsert(&l2, i, i-1)) break;
//  }
//  printf("capacity is %d, size is %d\n", l2.capacity, l2.size);
//  DSL_PrintList(l2);
//
//  printf("\n");
//
//  for(int i = 11;i >= 6;--i){
//    if(!DSL_ListDelete(&l2, i)) break;
//  }
//  printf("capacity is %d, size is %d\n", l2.capacity, l2.size);
//  DSL_PrintList(l2);
//  
//  printf("\n");
//
//  printf("The second is %d\n", DSL_GetElem(l2, 2));
//  printf("The third is %d\n", DSL_GetElem(l2, 3));
//  printf("13 is located in %d\n", DSL_LocateElem(l2, 13));
//}
//
//void test03(){
//  LinkList l3;
//  List_TailInsert(&l3);
//  LL_PrintList(l3);
//
//  LinkList l4;
//  List_HeadInsert(&l4);
//  LL_PrintList(l4);
//  //LinkList l5 = List_reverse(l4);
//  //LL_PrintList(l5);
//  LL_reverseList(l4);
//  LL_PrintList(l4);
//
//  printf("\n");
//}


//void test04(){
//  DLinkList l4;
//  DLL_ListTailInsert(&l4);
//  DLL_BackwardTraversal(l4);
//  printf("\n");
//  DNode* tmp = DLL_GetNode(l4, 10);
//  printf("%d\n", tmp->data);
//  DLL_BackwardTraversal(tmp);
//  printf("\n");
//  DLL_ForwardTraversal(tmp);
//}

void test05(){
  CLinkList l5;
  CLL_ListTailInsert(&l5);
  CLL_PrintList(l5);
  CLNode* cur = CLL_ReturnTail(l5);
  printf("%d\n", cur->data);

  CLinkList l6;
  CLL_ListHeadInsert(&l6);
  CLL_PrintList(l6);
  cur = CLL_ReturnTail(l6);
  printf("%d\n", cur->data);
  
  CLL_reverseList(l6);
  CLL_PrintList(l6);
  cur = CLL_ReturnTail(l6);
  printf("%d\n", cur->data);
  printf("\n");
}

