#include <stdio.h>
#include "SLL.h"

void SLL_InitList(SLinkList* L){
  // 初始化主链表：头结点在0位置，next为-1
  L->head = 0;
  L->nodes[L->head].next = -1;
  // 初始化空闲链表：1->2->3->...->MaxSize-1->-1
  L->avail = 1;
  for (int i = 1; i < MaxSize - 1; i++) {
      L->nodes[i].next = i + 1;
  }
  L->nodes[MaxSize - 1].next = -1;
}

int mallocNode(SLinkList* L){
  if(L->avail == -1) return -1;
  int tmp = L->avail;
  L->avail = L->nodes[tmp].next;
  return tmp;
}

void freeNode(SLinkList* L, int p){
  L->nodes[p].next = L->avail;
  L->avail = p;
}

bool SLL_ListInsert(SLinkList* L, int i, DataType x){
  if(i < 1) return false;
  int cur = L->head;
  int j = 0;
  while(cur != -1 && j < i-1){
    cur = L->nodes[cur].next;
    ++j;
  }
  if (cur == -1 || j > i - 1) return false;  // 位置i不合法
  int new_node = mallocNode(L);  // 分配新结点
  if (new_node == -1) return false;  // 空间不足
  // 插入新结点
  L->nodes[new_node].data = x;
  L->nodes[new_node].next = L->nodes[cur].next;
  L->nodes[cur].next = new_node;
  return true;
}

bool SLL_ListDeleteR(SLinkList* L, int i, DataType* x){
  if(i < 1) return false;
  int p = L->head;  // 从头结点开始
  int j = 0;
  // 寻找第i-1个结点（被删除结点的前驱）
  while (p != -1 && j < i - 1) {
      p = L->nodes[p].next;
      j++;
  }
  if (p == -1 || L->nodes[p].next == -1) return false;  // 第i个结点不存在
  int q = L->nodes[p].next;  // 要删除的结点
  if (x) *x = L->nodes[q].data;
  // 从主链表移除
  L->nodes[p].next = L->nodes[q].next;
  // 释放回空闲链表
  freeNode(L, q);
  return true;
}

bool SLL_ListDelete(SLinkList* L, int i){
  if (i < 1) return false;
  int p = L->head;  // 从头结点开始
  int j = 0;
  // 寻找第i-1个结点（被删除结点的前驱）
  while (p != -1 && j < i - 1) {
      p = L->nodes[p].next;
      j++;
  }
  if (p == -1 || L->nodes[p].next == -1) return false;  // 第i个结点不存在
  int q = L->nodes[p].next;  // 要删除的结点
  // 从主链表移除
  L->nodes[p].next = L->nodes[q].next; 
  // 释放回空闲链表
  freeNode(L, q);
  return true;
}

int SLL_Locate(SLinkList* L, DataType x) {
    int p = L->nodes[L->head].next;  // 第一个数据结点
    while (p != -1) {
        if (L->nodes[p].data == x) return p;  // 返回结点下标
        p = L->nodes[p].next;
    }
    return -1;  // 没找到
}

void SLL_Print(SLinkList* L) {
    int p = L->nodes[L->head].next;
    printf("List: ");
    while (p != -1) {
        printf("%d ", L->nodes[p].data);
        p = L->nodes[p].next;
    }
    printf("\n");
}

// 打印空闲链表（调试用）
void SLL_PrintAvail(SLinkList* L) {
    int p = L->avail;
    printf("Avail: ");
    while (p != -1) {
        printf("%d ", p);
        p = L->nodes[p].next;
    }
    printf("\n");
}




