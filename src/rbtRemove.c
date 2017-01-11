#include "rbtRemove.h"
#include "Node.h"
#include <stdio.h>


int removeLeftCase1a1(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = rightChild->right;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
        return 1;
      }
      else if(rightChild != NULL){
        leftRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->left->color = BLACK;
        root->right->color = BLACK;
        return 1;
      }
    }
    else if(leftChild != NULL){
      if(leftChild->data == removeNode->data){
        if(rightChild == NULL){
          leftChild = NULL;
          leftChild->color = BLACK;
          return 1;
        }
        else if(rightChild != NULL){
          if(rightGrandchild->color == RED){
            root->left = NULL;
            leftRotate(&root);
            root->color = RED;
            root->left->color = root->right->color = BLACK;  
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int removeLeftCase1a2(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = rightChild->right;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
        return 1;
      }
      else if(rightChild != NULL){
        leftRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->left->color = BLACK;
        root->right->color = BLACK; 
        return 1;
      }
    }
    else if(leftChild != NULL){
      if(leftChild->data == removeNode->data){
        if(rightChild == NULL){
          leftChild = NULL;
          leftChild->color = BLACK;
          return 1;
        }
        else if(rightChild != NULL){
          if(rightGrandchild->color == RED){
            root->left = NULL;
            leftRotate(&root);
            root->color = BLACK;
            root->left->color = root->right->color = BLACK;
            return 1;
          }          
        }
      }
    }
  }
  return 0;
}

int removeLeftCase1b1(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
        return 1;
      }
      else if(rightChild != NULL){
        rightLeftRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->left->color = BLACK;
        root->right->color = BLACK; 
        return 1;
      }
    }
    else if(leftChild != NULL){
      if(leftChild->data == removeNode->data){
        if(rightChild == NULL){
          leftChild = NULL;
          leftChild->color = BLACK;
          return 1;
        }
        else if(rightChild != NULL){
          if(leftGrandchild->color == RED){
            root->left = NULL;
            rightLeftRotate(&root);
            *nodePtr = root;
            root->color = RED;
            root->left->color = root->right->color = BLACK;
            return 1; 
          }          
        }
      }
    }
  }
  return 0;
}

int removeLeftCase1b2(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  
  if(leftChild->color == DOUBLE_BLACK){
    if(leftChild == NULL){
      if(rightChild == NULL){
        leftChild->color = BLACK;
        return 1;
      }
      else if(rightChild != NULL){
        rightLeftRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->left->color = BLACK;
        root->right->color = BLACK;
        return 1;  
      }
    }
    else{
      if(leftChild->data == removeNode->data){
        if(rightChild == NULL){
          leftChild = NULL;
          leftChild->color = BLACK;
          return 1;
        }
        else if(rightChild != NULL){
          if(leftGrandchild->color == RED){
            root->left = NULL;
            rightLeftRotate(&root);
            root->color = BLACK;
            root->left->color = root->right->color = BLACK;  
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int removeLeftCase2a(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (root->color == BLACK)){
    if((rightChild != NULL) && (rightChild-> color == BLACK)){
      if(leftChild->data == removeNode->data){
        if(leftGrandchild && rightGrandchild != NULL){
          if((leftGrandchild->color == BLACK) && (rightGrandchild->color == BLACK)){
            root->color = DOUBLE_BLACK;
            root->right->color = RED;
            root->left = NULL;
            return 1;
          }
        }
        else if((leftGrandchild == NULL) && (rightGrandchild == NULL)){
          root->color = DOUBLE_BLACK;
          root->right->color = RED;
          root->left = NULL;
          return 1;
        }
      }
    }
  }
  return 0;
}

int removeLeftCase2b(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (root->color == RED)){
    if((rightChild != NULL) && (rightChild->color == BLACK)){
      if(leftChild->data == removeNode->data){
        if(leftGrandchild && rightGrandchild != NULL){
          if((leftGrandchild->color == BLACK) && (rightGrandchild->color == BLACK)){
            root->color = BLACK;
            root->right->color = RED;
            root->left = NULL;
            return 1;
          }
        }
        else if((leftGrandchild == NULL) && (rightGrandchild == NULL)){
          root->color = BLACK;
          root->right->color = RED;
          root->left = NULL;
          return 1;
        }
      }
    }
  }
  return 0;
}

int removeLeftCase3(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left; 
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (rightChild != NULL)){
    if((rightChild->color == RED) && (leftChild->color == DOUBLE_BLACK)){
      leftRotate(&(*nodePtr));
      root = *nodePtr;
      root->color = BLACK;
      root->left->left = NULL;
      root->left->color = RED;
      if(((*nodePtr)->left != NULL) && ((*nodePtr)->left->color == RED)){   //<-have not done yet
        removeLeftCase2b((&root->left), removeNode);
        return 1;
      }
    }
  }
  return 0;
}

/*
*-----------------------------
* RIGHT PART REMOVED FUNCTIONS 
*------------------------------
*/

int removeRightCase1a1(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = leftChild->left;
  
  if(rightChild->color == DOUBLE_BLACK){
    if(rightChild == NULL){
      if(leftChild == NULL){
        rightChild->color = BLACK;
        return 1;
      }
      else if(leftChild != NULL){
        rightRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->right->color = BLACK;
        root->left->color = BLACK;
        return 1;  
      }
    }
    else if(rightChild != NULL){
      if(rightChild->data == removeNode->data){
        if(leftChild == NULL){
          rightChild = NULL;
          rightChild->color = BLACK;
          return 1;
        }
        else if(leftChild != NULL){
          if(leftGrandchild->color == RED){
            root->right = NULL;
            rightRotate(&root);
            root->color = RED;
            root->right->color = root->left->color = BLACK;  
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int removeRightCase1a2(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = leftChild->left;
  
  if(rightChild->color == DOUBLE_BLACK){
    if(rightChild == NULL){
      if(leftChild == NULL){
        rightChild->color = BLACK;
        return 1;
      }
      else if(leftChild != NULL){
        rightRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->right->color = BLACK;
        root->left->color = BLACK; 
        return 1;
      }
    }
    else if(rightChild != NULL){
      if(rightChild->data == removeNode->data){
        if(leftChild == NULL){
          rightChild = NULL;
          rightChild->color = BLACK;
          return 1;
        }
        else if(leftChild != NULL){
          if(leftGrandchild->color == RED){
            root->right = NULL;
            rightRotate(&root);
            root->color = BLACK;
            root->right->color = root->left->color = BLACK; 
            return 1;
          }          
        }
      }
    }
  }
  return 0;
}

int removeRightCase1b1(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = leftChild->right;
  
  if(rightChild->color == DOUBLE_BLACK){
    if(rightChild == NULL){
      if(leftChild == NULL){
        rightChild->color = BLACK;
        return 1;
      }
      else if(leftChild != NULL){
        leftRightRotate(&root);
        *nodePtr = root;
        root->color = RED;
        root->right->color = BLACK;
        root->left->color = BLACK;
        return 1;  
      }
    }
    else if(rightChild != NULL){
      if(rightChild->data == removeNode->data){
        if(leftChild == NULL){
          rightChild = NULL;
          rightChild->color = BLACK;
          return 1;
        }
        else if(leftChild != NULL){
          if(rightGrandchild->color == RED){
            root->right = NULL;
            leftRightRotate(&root);
            *nodePtr = root;
            root->color = RED;
            root->right->color = root->left->color = BLACK;  
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

int removeRightCase1b2(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  rightGrandchild = leftChild->right;
  
  if(rightChild->color == DOUBLE_BLACK){
    if(rightChild == NULL){
      if(leftChild == NULL){
        rightChild->color = BLACK;
        return 1;
      }
      else if(leftChild != NULL){
        leftRightRotate(&root);
        *nodePtr = root;
        root->color = BLACK;
        root->right->color = BLACK;
        root->left->color = BLACK; 
        return 1;
      }
    }
    else{
      if(rightChild->data == removeNode->data){
        if(leftChild == NULL){
          rightChild = NULL;
          rightChild->color = BLACK;
          return 1;
        }
        else if(leftChild != NULL){
          if(rightGrandchild->color == RED){
            root->right = NULL;
            leftRightRotate(&root);
            root->color = BLACK;
            root->right->color = root->left->color = BLACK;
            return 1; 
          }          
        }
      }
    }
  }
  return 0;
}

int removeRightCase2a(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left;
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (root->color == BLACK)){
    if((leftChild != NULL) && (leftChild-> color == BLACK)){
      if(rightChild->data == removeNode->data){
        if(rightGrandchild && leftGrandchild != NULL){
          if((rightGrandchild->color == BLACK) && (leftGrandchild->color == BLACK)){
            root->color = DOUBLE_BLACK;
            root->left->color = RED;
            root->right = NULL;
            return 1;
          }
        }
        else if((rightGrandchild == NULL) && (leftGrandchild == NULL)){
          root->color = DOUBLE_BLACK;
          root->left->color = RED;
          root->right = NULL;
          return 1;
        }
      }
    }
  }
  return 0;
}

int removeRightCase2b(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left; 
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (root->color == RED)){
    if((leftChild != NULL) && (leftChild-> color == BLACK)){
      if(rightChild->data == removeNode->data){
        if(rightGrandchild && leftGrandchild != NULL){
          if((rightGrandchild->color == BLACK) && (leftGrandchild->color == BLACK)){
            root->color = BLACK;
            root->left->color = RED;
            root->right = NULL;
            return 1;
          }
        }
        else if((rightGrandchild == NULL) && (leftGrandchild == NULL)){
          root->color = BLACK;
          root->left->color = RED;
          root->right = NULL;
          return 1;
        }
      }
    }
  }
  return 0;
}

int removeRightCase3(Node **nodePtr, Node *removeNode){
  Node *root, *leftChild, *rightChild, *leftGrandchild, *rightGrandchild;
  root = *nodePtr;
  leftChild = root->left;
  rightChild = root->right;
  leftGrandchild = rightChild->left; 
  rightGrandchild = rightChild->right;
  
  if((root != NULL) && (leftChild != NULL)){
    if((leftChild->color == RED) && (rightChild->color == DOUBLE_BLACK)){
      rightRotate(&(*nodePtr));
      root = *nodePtr;
      root->color = BLACK;
      root->right->right = NULL;
      root->right->color = RED;
      return 1;
    }
  }
  return 0;
}

/*
* The following functions are to call all the removed cases that have done above.
* If the red black tree does not meet the condition of the function, it will proceed to the next function.
*/

int pollLeftRemove(Node **nodePtr, Node *removeNode){
  
  if(removeLeftCase3(&(*nodePtr), removeNode)) return;
  if(removeLeftCase1a1(&(*nodePtr), removeNode)) return;
  if(removeLeftCase1a2(&(*nodePtr), removeNode)) return;
  if(removeLeftCase1b1(&(*nodePtr), removeNode)) return;
  if(removeLeftCase1b2(&(*nodePtr), removeNode)) return;
  if(removeLeftCase2a(&(*nodePtr), removeNode)) return;
  if(removeLeftCase2b(&(*nodePtr), removeNode)) return;
}

int pollRightRemove(Node **nodePtr, Node *removeNode){
  Node *root;
  root = *nodePtr;
  
  removeRightCase3(&root, removeNode);
  if(removeRightCase1a1(&root, removeNode)) return;
  if(removeRightCase1a2(&root, removeNode)) return;
  if(removeRightCase1b1(&root, removeNode)) return;
  if(removeRightCase1b2(&root, removeNode)) return;
  if(removeRightCase2a(&root, removeNode)) return;
  if(removeRightCase2b(&root, removeNode)) return;
}


