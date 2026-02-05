#include "BT.h"
#include <stdio.h>

void visit(BiTree T){
  printf("%d ", T->data);
}

void PreOrder(BiTree T){
  if(T == NULL) return;
  visit(T);
  PreOrder(T->lchild);
  PreOrder(T->rchild);
}

void InOrder(BiTree T){
  if(T == NULL) return;
  InOrder(T->lchild);
  visit(T);
  InOrder(T->rchild);
}

void PostOrder(BiTree T){
  if(T == NULL) return;
  PostOrder(T->lchild);
  PostOrder(T->rchild);
  visit(T);
}

void LevelOrder(BiTree T);

