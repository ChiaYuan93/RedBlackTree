#include "rbtAdd.h"
#include "Rotation.h"
#include "Node.h"
#include <stdio.h>

void rbtAdd(Node **nodePtr, Node *addNewNode){
  Node *root;
  root = *nodePtr;
  
  if(root == NULL){
    root = addNewNode;
    *nodePtr = root;
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
  checkViolation(&(*nodePtr));
}

void checkViolation(Node **nodePtr){
  Node *root;
  root = *nodePtr;
  
  if((root->left) && (root->right) != NULL ){               
    recolorCase1(&root);                 //call case 1 recolor function
  }
  else if((root->left) != NULL || (root->right) == NULL){  
    if(root->left->right != NULL){
      leftRotateCase2(&(*nodePtr));     //call case2 left rotate function
    }
    else if(root->left->left != NULL){
      rightRotateCase3(&(*nodePtr));   //call case3 right rotate function
    }
  }
  else if((root->right) != NULL || (root->left) == NULL){  
    if(root->right->left != NULL){
      rightRotateCase2(&(*nodePtr));   //call case2 right rotate function
    }
    else if(root->right->right != NULL){
      leftRotateCase3(&(*nodePtr));   //call case3 right rotate function
    }
  }
}
