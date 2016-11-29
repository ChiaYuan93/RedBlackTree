#include <stdio.h>
#include "Unity.h"
#include "CustomAssert.h"

const char *getColorName(Color color) {
  switch(color) {
    case BLACK:
      return "black";
      break;
    case RED:
      return "red";
      break;      
    case DOUBLE_BLACK:
      return "double black";
      break;
    default:
      return "unknown color";
      break;      
  }
}

void getNodeValueInString(Node *node, char *str) {   
  if(node != NULL)
    sprintf(str, "%d", node->data);
  else
    sprintf(str, "NULL"); 
}

void verifyChild(Node *node, char *whichChild, Node *expectedNode, Node *actualNode, int lineNo) {
  char buffer[256], valueString1[64], valueString2[64];
  if(expectedNode != actualNode) {    
    getNodeValueInString(expectedNode, valueString1);
    getNodeValueInString(actualNode, valueString2);
       
    sprintf(buffer, "Expect %s child of node %d (0x%p) be %s (0x%p), but it is %s (0x%p)",    \
      whichChild, node->data, node, valueString1, expectedNode, valueString2, actualNode);
    UNITY_TEST_FAIL(lineNo, buffer);  
  } 
}

void testAssertNode(int value, Node *left, Node *right, Color color, Node *node, int lineNo) {
  char buffer[256];
  if(node == NULL)
    UNITY_TEST_FAIL(lineNo, "Expect node is not NULL");
  
  if(node->data != value)  {
    sprintf(buffer, "Expect node %d's value is %d, but it is %d",     \
              node->data, value, node->data);
    UNITY_TEST_FAIL(lineNo, buffer);
  }
  
  verifyChild(node, "left",  left, node->left, lineNo);
  verifyChild(node, "right", right, node->right, lineNo);
  
  if(node->color != color) {
    sprintf(buffer, "Expect node %d's color is %s, but it is %s",   \
              node->data, getColorName(color), getColorName(node->color ));
    UNITY_TEST_FAIL(lineNo, buffer);
  }
}

void testAssertCompareNodes(Node *expectedNode, Node *actualNode, int lineNo) {
  char buffer[256], valueString1[64], valueString2[64];
  if(expectedNode != actualNode) {
    getNodeValueInString(expectedNode, valueString1);
    getNodeValueInString(actualNode, valueString2);
    sprintf(buffer, "Expect node is %s, but it is %s",       \
            valueString1, valueString2);
    UNITY_TEST_FAIL(lineNo, buffer);  
  }
}