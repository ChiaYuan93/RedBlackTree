#include "Rotation.h"
#include "Node.h"
#include <stdio.h>

void rbtAdd(Node **nodePtr, Node *addNewNode){
  Node *root;
  root = *nodePtr;
  
  if(root == NULL){
    root = addNewNode;
    addNewNode->left = NULL;
    addNewNode->right = NULL;
    addNewNode->color = RED;
    return;
  }
  else if(addNewNode->data < root->data){
    rbtAdd(&root->left, addNewNode);
  }
  else if(addNewNode->data > root->data){
    rbtAdd(&root->right, addNewNode);
 
  }
}

// void checkViolation(Node **nodePtr){
  // Node *root;
  // root = *nodePtr;
  
  // if()
// }

void leftRotate(Node **nodePtr){
  Node *root, *child, *grandChild; 
  root = *nodePtr;
  child = root->right;
  
  if(child == NULL){
    *nodePtr = root;
  }
  else{
    grandChild = child->left;
    child->left = root;
    root->right = grandChild;
    *nodePtr = child;
  }   
}

void rightRotate(Node **nodePtr){
  Node *root, *child, *grandChild;
  root = *nodePtr;
  child = root->left;
  
  if(child == NULL){
    *nodePtr = root;
  }
  else{
    grandChild = child->right;
    child->right = root;
    root->left = grandChild;
    *nodePtr = child;
  } 
}

void leftRightRotate(Node **nodePtr){
  Node *root = *nodePtr;
  leftRotate(&root->left);
  rightRotate(&(*nodePtr));
}

void rightLeftRotate(Node **nodePtr){
  Node *root = *nodePtr;
  rightRotate(&root->right);
  leftRotate(&(*nodePtr));
}

/**
*     Three cases to deal with color violations
*     -------------------------------------------
*            Case 1: Recoloring
**/
void recolorCase1(Node **nodePtr){
  Node *root, *childLeft, *childRight;
  root = *nodePtr;
  childLeft = root->left;
  childRight = root->right;
  
  if(childLeft->left != NULL){
    if((childLeft->color==RED) && (childLeft->left->color==RED)){
      childLeft->color = BLACK;
      childRight->color = BLACK;
      root->color = RED;
    }
  }
  else if(childLeft->right != NULL){
    if((childLeft->color==RED) && (childLeft->right->color==RED)){
      childLeft->color = BLACK;
      childRight->color = BLACK;
      root->color = RED;
    }
  }
  else if(childRight->left != NULL){
    if((childRight->color==RED) && (childRight->left->color==RED)){
      childLeft->color = BLACK;
      childRight->color = BLACK;
      root->color = RED;
    }
  }
  else if(childRight->right != NULL){
    if((childRight->color==RED) && (childRight->right->color==RED)){
      childLeft->color = BLACK;
      childRight->color = BLACK;
      root->color = RED;
    }
  } 
}

/**
*         Case 2
**/
void leftRotateCase2(Node **nodePtr){
  Node *root, *child, *grandChild;
  root = *nodePtr;
  child = root->left;
  grandChild = child->right;
  if((child->color == RED) && (grandChild->color) == RED){
    leftRotate(&root->left);
  }   
}

void rightRotateCase2(Node **nodePtr){
  Node *root, *child, *grandChild;
  root = *nodePtr;
  child = root->right;
  grandChild = child->left;
  if((child->color == RED) && (grandChild->color) == RED){
    rightRotate(&root->right);
  }   
}

/**
*         Case 3
**/
void rightRotateCase3(Node **nodePtr){
  Node *root, *child, *grandChild;
  root = *nodePtr;
  child = root->left;
  grandChild = child->left;
  if((child->color == RED) && (grandChild->color) == RED){
    rightRotate(&(root));
    root->color = BLACK;
    child->right->color = RED;
  }   
}

void leftRotateCase3(Node **nodePtr){
  Node *root, *child, *grandChild;
  root = *nodePtr;
  child = root->right;
  grandChild = child->right;
  if((child->color == RED) && (grandChild->color) == RED){
    leftRotate(&(root));
    root->color = BLACK;
    child->left->color = RED;
  }   
}
