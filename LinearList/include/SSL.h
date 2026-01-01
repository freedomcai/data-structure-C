#ifndef SSL_H
#define SSL_H

#define MaxSize 10

typedef int DataType;

typedef struct {
  DataType list[MaxSize];
  int size;   
}SSeqList;

#endif
