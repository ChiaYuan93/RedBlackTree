#ifndef rbtRemove_H
#define rbtRemove_H
#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Color returnedColor;
};

ReturnedObject rbtRemoveNode(Node *nodePtr);
void removeCase1a1(Node **nodePtr, ReturnedObject removedNode);
void removeCase1a2(Node **nodePtr, ReturnedObject removedNode);
void removeCase1b1(Node **nodePtr, ReturnedObject removedNode);
void removeCase1b2(Node **nodePtr, ReturnedObject removedNode);
void removeCase2a(Node **nodePtr, ReturnedObject removedNode);

#endif // rbtRemove_H
