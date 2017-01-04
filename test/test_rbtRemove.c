#include "unity.h"
#include "rbtRemove.h"
#include "Rotation.h"
#include "NodeHelper.h"
#include "Node.h"
#include "CustomAssert.h"

Node node0, node5, node10, node20, node25, node30, node50, node100, node150;

void setUp(void) {  
  initNode(&node0,     0, NULL, NULL, BLACK);  
  initNode(&node5,     5, NULL, NULL, BLACK);  
  initNode(&node10,   10, NULL, NULL, BLACK);  
  initNode(&node20,   20, NULL, NULL, BLACK);  
  initNode(&node25,   25, NULL, NULL, BLACK);  
  initNode(&node30,   30, NULL, NULL, BLACK);  
  initNode(&node50,   50, NULL, NULL, BLACK);  
  initNode(&node100, 100, NULL, NULL, BLACK);  
  initNode(&node150, 150, NULL, NULL, BLACK);  
}

void tearDown(void){}

/**
*         /
*        50(B)
*       /   \
*     40(B) 100(B)
*    /   \
*  10(R) -
*
*
*
*



/**
*Left double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's right child
*                  is red (with the parent being red).
*
*           ^       /                             /         ^    
*           |      20(r)         rotate         50(r)       |
*           |     //  \          Left          /   \        |   height
*  height   |   5(db) 50(b)      ------>     20(b) 100(b)   |     3     
*    3      |        /  \                   / \    / \      |         
*           |       -   100(r)             -  -   -   -     |            
*           |          /  \                                 v        
*           |         -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1a_given_sibling_is_black_and_sibling_right_child_is_red_should_rotate_right(void){
  Node *root = &node20;
  ReturnedObject returnedObject;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node5, 5, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, NULL, &node100, BLACK);
  initNode(&node20, 20, &node5, &node50, RED);
  
  removeCase1a1(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20);
  TEST_ASSERT_EQUAL_NODE(50, &node20, &node100, RED, &node50);
}

/**
*Left double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's right child
*                  is red (with the parent being red).
*
*           ^       /                             /         ^    
*           |      10(b)         rotate         20(b)       |
*           |     //  \          Left          /   \        |   height
*  height   |    -   20(b)      ------>     10(b) 100(b)    |     4    
*    3      |        /  \                   / \    / \      |         
*           |       -   100(r)             -  -   -   -     |            
*           |          /  \                                 v        
*           |         -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1a2_given_left_child_is_double_black_and_sibling_is_black_and_sibling_right_child_is_red_should_rotate_right(void){
  Node *root = &node10;
  ReturnedObject returnedObject;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, 20, NULL, &node100, BLACK);
  initNode(&node10, 10, &node0, &node20, BLACK);
  
  returnedObject = rbtRemoveNode(&node0);
  removeCase1a2(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(20, &node10, &node100, BLACK, &node20);
}

/**
*Left double black
*-----------------
*Testing case(1b): The sibling is black and the sibling's left child
*                  is red (with the parent being red).
*
*           ^       /                             /         ^    
*           |      20(r)         rotate         25(r)       |
*           |     //  \          Right          /   \       |   height
*  height   | 10(db)  50(b)       Left        20(b) 50(b)    |     3    
*    3      |        /  \     -------->      / \    / \     |         
*           |     25(r)  -                  -  -   -   -    |            
*           |    /  \                                       v        
*           |   -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1b1_given_left_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right_and_left(void){
  Node *root = &node20;
  ReturnedObject returnedObject;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node10, 10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, &node25, NULL, BLACK);
  initNode(&node20, 20, &node10, &node50, RED);
  
  returnedObject = rbtRemoveNode(&node10);
  removeCase1b1(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20);
  TEST_ASSERT_EQUAL_NODE(25, &node20, &node50, RED, &node25);
}

/**
*Left double black
*-----------------
*Testing case(1b): The sibling is black and the sibling's left child
*                  is red (with the parent being red).
*
*           ^       /                             /           ^    
*           |      5(b)          rotate         25(b)         |
*           |     //  \          Right          /   \         |   height
*  height   |    -   100(b)      Left         5(b) 100(b)     |     3    
*    3      |        /  \      -------->      / \   / \       |         
*           |     25(r)  -                   -  -  -   -      |            
*           |    /  \                                         v        
*           |   -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1b2_given_left_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right_and_left(void){
  Node *root = &node5;
  ReturnedObject returnedObject;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, &node25, NULL, BLACK);
  initNode(&node5, 5, &node0, &node100, BLACK);
  
  returnedObject = rbtRemoveNode(&node0);
  removeCase1b2(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(25, &node5, &node100, BLACK, &node25);
}

/**
*Left double black
*-----------------
*Testing case(2a): The sibling is black and both sibling's children
*                  are black (with the parent being black).
*
*           ^       /                            //           ^    
*           |      5(b)                         5(db)         |
*           |     //  \           flip         /   \          |  height
*  height   |    -   100(b)       color       -   100(r)      |    2    
*    3      |        /   \       -------->        /  \        |         
*           |     25(b)  150(b)                 25(b) 150(b)  |            
*           |    /  \    /  \                  /  \   /  \    v        
*           |   -   -   -    -                -   -  -    -                           
*           |
*           v
*
*/
void test_flipColorCase2a_given_sibling_is_black_and_both_sibling_children_are_black_should_flip_color(void){
  Node *root = &node5;
  ReturnedObject returnedObject;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, &node25, &node150, BLACK);
  initNode(&node5, 5, &node0, &node100, BLACK);
  
  removeCase2a(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, &node100, DOUBLE_BLACK, &node5);
}

/**
*Left double black
*-----------------
*Testing case(2a): The sibling is black and both sibling's children
*                  are NULL (with the parent being black).
*
*           ^       /                            //           ^    
*           |      50(b)                        50(db)        |
*           |     //  \           flip         /   \          |  height
*  height   |  25(db) 100(b)      color       -   100(r)      |    1    
*    2      |        /   \       -------->        /  \        |         
*           |       -     -                      -    -       |            
*           |                                                 v        
*           |                             
*           |
*           v
*
*/
void test_flipColorCase2a_given_sibling_is_black_and_both_sibling_children_are_null_should_flip_color(void){
  Node *root = &node50;
  ReturnedObject returnedObject;
  
  initNode(&node25, 25, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node50, 50, &node25, &node100, BLACK);
  
  removeCase2a(&root, returnedObject);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(50, NULL, &node100, DOUBLE_BLACK, &node50);
}

/**
*Left double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^       /                            /            ^    
*           |      5(r)                         5(b)          |
*           |     //  \           flip         /   \          |  height
*  height   |    -   100(b)       color       -   100(r)      |    2    
*    3      |        /   \       -------->        /  \        |         
*           |     25(b)  150(b)                 25(b) 150(b)  |            
*           |    /  \    /  \                  /  \   /  \    v        
*           |   -   -   -    -                -   -  -    -                           
*           |
*           v
*
*/
