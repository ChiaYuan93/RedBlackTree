#ifndef rbtRemove_H
#define rbtRemove_H
#include "Node.h"

int removeLeftCase1a1(Node **nodePtr, Node *removeNode);
int removeLeftCase1a2(Node **nodePtr, Node *removeNode);
int removeLeftCase1b1(Node **nodePtr, Node *removeNode);
int removeLeftCase1b2(Node **nodePtr, Node *removeNode);
int removeLeftCase2a(Node **nodePtr, Node *removeNode);
int removeLeftCase2b(Node **nodePtr, Node *removeNode);
int removeLeftCase3(Node **nodePtr, Node *removeNode);
int removeRightCase1a1(Node **nodePtr, Node *removeNode);
int removeRightCase1a2(Node **nodePtr, Node *removeNode);
int removeRightCase1b1(Node **nodePtr, Node *removeNode);
int removeRightCase1b2(Node **nodePtr, Node *removeNode);
int removeRightCase2a(Node **nodePtr, Node *removeNode);
int removeRightCase2b(Node **nodePtr, Node *removeNode);
int removeRightCase3(Node **nodePtr, Node *removeNode);

int pollLeftRemove(Node **nodePtr, Node *removeNode);
int pollRightRemove(Node **nodePtr, Node *removeNode);

#endif // rbtRemove_H
