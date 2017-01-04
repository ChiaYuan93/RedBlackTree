#include "rbtRemove.h"
#include "Node.h"
#include <stdio.h>

ReturnedObject rbtRemoveNode(Node *nodePtr){
  ReturnedObject returnedObject;
  
  returnedObject.removedNode = nodePtr;
  // returnedObject.removedNode = nodePtr->color;
  
  return returnedObject;
}

void removeCase1a1(Node **nodePtr, ReturnedObject removedNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = rightChild->right;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
      }
      else{
        leftRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->left->color = BLACK;
        root->right->color = BLACK; 
      }
    }
    else{
      if(rightChild == NULL){
        leftChild = NULL;
        leftChild->color = BLACK;
      }
      else{
        root->left = NULL;
        leftRotate(&root);
        root->color = RED;
        root->left->color = root->right->color = BLACK;  
      }
    }
  }
}

void removeCase1a2(Node **nodePtr, ReturnedObject removedNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = rightChild->right;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
      }
      else{
        leftRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->left->color = BLACK;
        root->right->color = BLACK; 
      }
    }
    else{
      if(rightChild == NULL){
        leftChild = NULL;
        leftChild->color = BLACK;
      }
      else{
        root->left = NULL;
        leftRotate(&root);
        root->color = BLACK;
        root->left->color = root->right->color = BLACK;  
      }
    }
  }
}

void removeCase1b1(Node **nodePtr, ReturnedObject removedNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
      }
      else{
        rightLeftRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->left->color = BLACK;
        root->right->color = BLACK; 
      }
    }
    else{
      if(rightChild == NULL){
        leftChild = NULL;
        leftChild->color = BLACK;
      }
      else{
        root->left = NULL;
        rightLeftRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->left->color = root->right->color = BLACK;  
      }
    }
  }
}

void removeCase1b2(Node **nodePtr, ReturnedObject removedNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
      }
      else{
        rightLeftRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->left->color = BLACK;
        root->right->color = BLACK; 
      }
    }
    else{
      if(rightChild == NULL){
        leftChild = NULL;
        leftChild->color = BLACK;
      }
      else{
        root->left = NULL;
        rightLeftRotate(&root);
        root->color = BLACK;
        root->left->color = root->right->color = BLACK;  
      }
    }
  }
}

void removeCase2a(Node **nodePtr, ReturnedObject removedNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  rightGrandchild = rightChild->right;
  
  if((rightChild != NULL) && (rightChild-> color == BLACK)){
    if(leftGrandchild && rightGrandchild != NULL){
      if((leftGrandchild->color == BLACK) && (rightGrandchild->color == BLACK)){
        root->color = DOUBLE_BLACK;
        root->right->color = RED;
        root->left = NULL;
      }
    }
    else if((leftGrandchild == NULL) && (rightGrandchild == NULL)){
      root->color = DOUBLE_BLACK;
      root->right->color = RED;
      root->left = NULL;
    }
  }
}