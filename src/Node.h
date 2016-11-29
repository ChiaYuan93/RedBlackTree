#ifndef Node_H
#define Node_H

typedef enum {
  BLACK, RED, DOUBLE_BLACK
} Color;

typedef struct Node Node;

struct Node {
  Node *left;
  Node *right;
  int color;
  int data;
};

#endif // Node_H
