#ifndef BT_H
#define BT_H

typedef int DataType;

typedef struct BiTNode{
  DataType data;
  struct BiTNode *lchild, *rchild;
}BiTNode, BiTree;

void visit(BiTree T);

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

void LevelOrder(BiTree T);

#endif
