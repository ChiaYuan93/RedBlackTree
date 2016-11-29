#include "NodeHelper.h"

void initNode(Node *node, int value, Node *left, Node *right, Color color) {
  node->left = left;
  node->right = right;
  node->color = color;
  node->data = value;
}