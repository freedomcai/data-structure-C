#ifndef DSL_H
#define DSL_h

typedef int DataType;

typedef struct {
  DataType* data;
  int length;
  int capacity;  
}DSeqList;

#endif
