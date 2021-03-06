#include "unity.h"
#include "rbtRemove.h"
#include "Rotation.h"
#include "NodeHelper.h"
#include "Node.h"
#include "CustomAssert.h"

Node node0, node5, node10, node20, node25, node30, node50, node100, node150, node200;

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
  initNode(&node200, 200, NULL, NULL, BLACK);  
}

void tearDown(void){}

/**
*-----------------------------------------------------------------------
*                            NOTE
*-----------------------------------------------------------------------                    
* The following tests are to test the Red Black Tree REMOVE functions.
* 
* The tests started with LEFT part removed functions tests 
* then followed by RIGHT part removed functions tests.
*/

/*----------------------------------
* LEFT PART REMOVED FUNCTIONS TESTS |
*-----------------------------------
*/

/**
*LEFT double black
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
void test_leftRotateCase1a1_given_sibling_is_black_and_sibling_right_child_is_red_should_rotate_left(void){
  Node *root = &node20;
  Node *removeNode = &node5;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node5, 5, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, NULL, &node100, BLACK);
  initNode(&node20, 20, &node5, &node50, RED);
  
  removeLeftCase1a1(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20);
  TEST_ASSERT_EQUAL_NODE(50, &node20, &node100, RED, &node50);
}

/**
*LEFT double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's right child
*                  is red (with the parent being black).
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
void test_leftRotateCase1a2_given_left_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right(void){
  Node *root = &node10;
  Node *removeNode = &node0;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, 20, NULL, &node100, BLACK);
  initNode(&node10, 10, &node0, &node20, BLACK);
  
  removeLeftCase1a2(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(20, &node10, &node100, BLACK, &node20);
}

/**
*LEFT double black
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
void test_rightLeftRotateCase1b1_given_left_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right_and_left(void){
  Node *root = &node20;
  Node *removeNode = &node10;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node10, 10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, &node25, NULL, BLACK);
  initNode(&node20, 20, &node10, &node50, RED);
  
  removeLeftCase1b1(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20);
  TEST_ASSERT_EQUAL_NODE(25, &node20, &node50, RED, &node25);
}

/**
*LEFT double black
*-----------------
*Testing case(1b): The sibling is black and the sibling's left child
*                  is red (with the parent being black).
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
void test_rightLeftRotateCase1b2_given_left_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right_and_left(void){
  Node *root = &node5;
  Node *removeNode = &node0;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, &node25, NULL, BLACK);
  initNode(&node5, 5, &node0, &node100, BLACK);
  
  removeLeftCase1b2(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(25, &node5, &node100, BLACK, &node25);
}

/**
*LEFT double black
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
  Node *removeNode = &node0;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, &node25, &node150, BLACK);
  initNode(&node5, 5, &node0, &node100, BLACK);
  
  removeLeftCase2a(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, &node100, DOUBLE_BLACK, &node5);
}

/**
*LEFT double black
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
  Node *removeNode = &node25;
  
  initNode(&node25, 25, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node50, 50, &node25, &node100, BLACK);
  
  removeLeftCase2a(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(50, NULL, &node100, DOUBLE_BLACK, &node50);
}

/**
*LEFT double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^       /                            /            ^    
*           |      10(r)                        10(b)         |
*           |     //  \           flip         /   \          |  height
*  height   |    -   100(b)       color       -   100(r)      |    2    
*    3      |        /   \       -------->        /  \        |         
*           |     25(b)  150(b)                 25(b) 150(b)  |            
*           |    /  \    /  \                  /  \   /  \    v        
*           |   -   -   -    -                -   -  -    -                           
*           |
*           v
*/
void test_flipColorCase2b_given_sibling_is_black_and_both_sibling_children_are_black_should_flip_color(void){
  Node *root = &node10;
  Node *removeNode = &node5;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node5, 5, NULL, NULL, DOUBLE_BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node100, 100, &node25, &node150, BLACK);
  initNode(&node10, 10, &node5, &node100, RED);
  
  removeLeftCase2b(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, &node100, BLACK, &node10);
}

/**
*LEFT double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^       /                            /            ^    
*           |      100(r)                      100(b)         |
*           |     //  \           flip         /   \          |  height
*  height   |    -   150(b)       color       -   150(r)      |    2    
*    3      |        /   \       -------->        /  \        |         
*           |       -     -                      -    -       v                       
*           |
*           v
*/
void test_flipColorCase2b_given_sibling_and_sibling_childrens_are_black_with_parent_is_red_should_flip_color(void){
  Node *root = &node100;
  Node *removeNode = &node50;
  
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node50, 50, NULL, NULL, DOUBLE_BLACK);
  initNode(&node100, 100, &node50, &node150, RED);
  
  removeLeftCase2b(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, RED, &node150);
  TEST_ASSERT_EQUAL_NODE(100, NULL, &node150, BLACK, &node100);
}

/**
*LEFT double black
*-----------------
*Testing case(3): The sibling is red
*
*           ^          /                              /         ^    
*           |        25(b)                         100(b)       |
*           |       //   \           rotate       /     \       |  height
*  height   |    10(db)  100(r)      left       25(r)  150(b)   |    2    
*    2      |           /   \      -------->   // \      / \    |           
*           |        50(b) 150(b)             -  50(b)  -  -    v                       
*           |        / \    / \                  /  \
*           v       -  -   -  -                 -   - 
*/
void test_leftCase3_given_sibling_is_red_should_rotate_right(void){
  Node *root = &node25;
  Node *removeNode = &node10;
  
  initNode(&node10, 10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, NULL, NULL, BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node100, 100, &node50, &node150, RED);
  initNode(&node25, 25, &node10, &node100, BLACK);
  
  removeLeftCase3(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, &node50, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, BLACK, &node100);
}

/*
*-----------------------------------
* RIGHT PART REMOVED FUNCTIONS TESTS
*------------------------------------
*/

/**
*RIGHT double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's left child
*                  is red (with the parent being red).
*
*           ^         /                               /         ^    
*           |       50(r)          rotate           20(r)       |
*           |      /    \\         right           /   \        |   height
*  height   |    20(b) 100(db)    ------>        5(b) 50(b)     |     3     
*    3      |    /   \                          / \    / \      |         
*           |   5(r) -                        -  -   -   -      |            
*           |  /  \                                             v        
*           | -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1a1_given_sibling_is_black_and_sibling_right_child_is_red_should_rotate_right(void){
  Node *root = &node50;
  Node *removeNode = &node100;
  
  initNode(&node100, 100, NULL, NULL, DOUBLE_BLACK);
  initNode(&node5, 5, NULL, NULL, RED);
  initNode(&node20, 20, &node5, NULL, BLACK);
  initNode(&node50, 50, &node20, &node100, RED);
  
  removeRightCase1a1(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(20, &node5, &node50, RED, &node20);
}

/**
*RIGHT double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's left child
*                  is red (with the parent being black).
*
*           ^             /                             /         ^    
*           |           100(b)         rotate         20(b)       |
*           |          /   \\          right         /   \        |   height
*  height   |        20(b)  -         ------>     10(b) 100(b)    |     4    
*    3      |        /  \                         / \    / \      |         
*           |     10(r)                          -  -   -   -     |            
*           |    /  \                                             v        
*           |   -    -                                        
*           |
*           v
*
*/
void test_rightRotateCase1a2_given_right_child_is_double_black_and_sibling_is_black_and_sibling_left_child_is_red_should_rotate_right(void){
  Node *root = &node100;
  Node *removeNode = &node0;
  
  initNode(&node10, 10, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, 20, &node10, NULL, BLACK);
  initNode(&node100, 100, &node20, &node0, BLACK);
  
  removeRightCase1a2(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(20, &node10, &node100, BLACK, &node20);
}

/**
*RIGHT double black
*-----------------
*Testing case(1b): The sibling is black and the sibling's right child
*                  is red (with the parent being red).
*
*           ^        /                                /         ^    
*           |      100(r)          rotate          25(r)        |
*           |     /   \\           Left            /   \        |   height
*  height   |  10(b) 150(db)       right        10(b) 100(b)    |     3    
*    3      |  /  \              -------->      / \    / \      |         
*           | -   25(r)                        -  -   -   -     |            
*           |    /  \                                           v        
*           |   -   -                                           
*           |
*           v
*
*/
void test_leftRightRotateCase1b1_given_right_child_is_double_black_and_sibling_is_black_and_sibling_right_child_is_red_should_rotate_left_and_right(void){
  Node *root = &node100;
  Node *removeNode = &node150;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node150, 150, NULL, NULL, DOUBLE_BLACK);
  initNode(&node10, 10, NULL, &node25, BLACK);
  initNode(&node100, 100, &node10, &node150, RED);
  
  removeRightCase1b1(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(25, &node10, &node100, RED, &node25);
}

/**
*RIGHT double black
*-----------------
*Testing case(1b): The sibling is black and the sibling's right child
*                  is red (with the parent being black).
*
*           ^             /                              /         ^    
*           |           50(b)         rotate           25(b)       |
*           |          /   \\         left           /    \        |   height
*  height   |        10(b)  -         right         10(b) 50(b)    |     3    
*    3      |       /  \            -------->      / \    / \      |         
*           |      -  25(r)                       -  -   -   -     |            
*           |        /  \                                          v        
*           |       -    -                                        
*           |
*           v
*
*/
void test_leftRightRotateCase1b2_given_right_child_is_double_black_and_sibling_is_black_and_sibling_right_child_is_red_should_rotate_left_and_right(void){
  Node *root = &node50;
  Node *removeNode = &node0;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node10, 10, NULL, &node25, BLACK);
  initNode(&node50, 50, &node10, &node0, BLACK);
  
  removeRightCase1b2(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(25, &node10, &node50, BLACK, &node25);
}

/**
*RIGHT double black
*-----------------
*Testing case(2a): The sibling is black and both sibling's children
*                  are black (with the parent being black).
*
*           ^              /                            //      ^    
*           |            150(b)                       150(db)   |
*           |           /   \\       flip            /   \      |  height
*  height   |         25(b)  -      color          25(r)  -     |    2    
*    3      |        /   \         -------->      /   \         |         
*           |     5(b)  100(b)                  5(b)  100(b)    |            
*           |    /  \    /  \                  /  \   /  \      |        
*           |   -   -   -    -                -   -  -    -     v                     
*           |
*           v
*
*/
void test_rightFlipColorCase2a_given_sibling_is_black_and_both_sibling_children_are_black_should_flip_color(void){
  Node *root = &node150;
  Node *removeNode = &node0;
  
  initNode(&node5, 5, NULL, NULL, BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node25, 25, &node5, &node100, BLACK);
  initNode(&node150, 150, &node25, &node0, BLACK);
  
  removeRightCase2a(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(25, &node5, &node100, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(150, &node25, NULL, DOUBLE_BLACK, &node150);
}

/**
*RIGHT double black
*-----------------
*Testing case(2a): The sibling is black and both sibling's children
*                  are NULL (with the parent being black).
*
*           ^        /                            //      ^    
*           |      50(b)                        50(db)    |
*           |     /  \\           flip          /   \     |  height
*  height   |  25(b) 100(db)      color       25(r)  -    |    1    
*    2      |  /   \             -------->   /  \         |         
*           | -     -                       -    -        |            
*           |                                             v        
*           |                             
*           |
*           v
*
*/
void test_rightFlipColorCase2a_given_sibling_is_black_and_both_sibling_children_are_null_should_flip_color(void){
  Node *root = &node50;
  Node *removeNode = &node100;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node100, 100, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, &node25, &node100, BLACK);
  
  removeRightCase2a(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(50, &node25, NULL, DOUBLE_BLACK, &node50);
}

/**
*RIGHT double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^            /                             /      ^    
*           |          150(r)                       150(b)    |
*           |          /   \\        flip           /   \     |  height
*  height   |        50(b)  -        color        50(r)  -    |    2    
*    3      |       /   \          -------->     /   \        |         
*           |     25(b) 100(b)                25(b) 100(b)    |            
*           |    /  \   /  \                  /  \   /  \     |        
*           |   -   -  -    -                -   -  -    -    v                       
*           |
*           v
*/
void test_rightFlipColorCase2b_given_sibling_is_black_and_both_sibling_children_are_black_should_flip_color(void){
  Node *root = &node150;
  Node *removeNode = &node200;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node200, 200, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, &node25, &node100, BLACK);
  initNode(&node150, 150, &node50, &node200, RED);
  
  removeRightCase2b(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(50, &node25, &node100, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(150, &node50, NULL, BLACK, &node150);
}

/**
*RIGHT double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^       /                       /      ^    
*           |     100(r)                  100(b)   |
*           |     /   \\     flip         /   \    |  height
*  height   |   50(b)  -     color      50(r)  -   |    2    
*    3      |  /   \       -------->   /  \        |         
*           | -     -                 -    -       v                       
*           |
*           v
*/
void test_rightFlipColorCase2b_given_sibling_and_sibling_childrens_are_black_with_parent_is_red_should_flip_color(void){
  Node *root = &node100;
  Node *removeNode = &node150;
  
  initNode(&node150, 150, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, NULL, NULL, BLACK);
  initNode(&node100, 100, &node50, &node150, RED);
  
  removeRightCase2b(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(100, &node50, NULL, BLACK, &node100);
}

/**
*RIGHT double black
*-----------------
*Testing case(3): The sibling is red
*
*           ^           /                            /           ^    
*           |         100(b)                       25(b)         |
*           |         /   \\         rotate       /    \         |  height
*  height   |       25(r) 150(db)     right      10(b)  100(r)   |    2    
*    2      |      /   \             -------->  / \     /  \\   |           
*           |    10(b) 50(b)                   -   -   50(b) -   v                       
*           |    / \    / \                           /  \
*           v   -  -   -  -                          -   - 
*/
void test_rightCase3_given_sibling_is_red_should_rotate_right(void){
  Node *root = &node100;
  Node *removeNode = &node150;
  
  initNode(&node10, 10, NULL, NULL, BLACK);
  initNode(&node50, 50, NULL, NULL, BLACK);
  initNode(&node150, 150, NULL, NULL, DOUBLE_BLACK);
  initNode(&node25, 25, &node10, &node50, RED);
  initNode(&node100, 100, &node25, &node150, BLACK);
  
  removeRightCase3(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(10, NULL, NULL, BLACK, &node10);
  TEST_ASSERT_EQUAL_NODE(100, &node50, NULL, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(25, &node10, &node100, BLACK, &node25);
}


/**
*LEFT double black
*-----------------
*Testing case(2b): The sibling is black and both sibling's children
*                  are black (with the parent being red).
*
*           ^       /                            /            ^    
*           |      10(r)                        10(b)         |
*           |     //  \           flip         /   \          |  height
*  height   |    -   100(b)       color       -   100(r)      |    2    
*    3      |        /   \       -------->        /  \        |         
*           |     25(b)  150(b)                 25(b) 150(b)  |            
*           |    /  \    /  \                  /  \   /  \    v        
*           |   -   -   -    -                -   -  -    -                           
*           |
*           v
*/
void test_polling_left_remove_function_given_sibling_is_black_and_both_sibling_children_are_black_should_call_leftCase2b_function(void){
  Node *root = &node10;
  Node *removeNode = &node5;
  
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node5, 5, NULL, NULL, DOUBLE_BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node100, 100, &node25, &node150, BLACK);
  initNode(&node10, 10, &node5, &node100, RED);
  
  pollLeftRemove(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(10, NULL, &node100, BLACK, &node10);
}

/**
*LEFT double black
*-----------------
*Testing case(3): The sibling is red
*
*           ^          /                              /                        /         ^    
*           |        25(b)                         100(b)                    100(b)      |
*           |       //   \           rotate       /     \        call       /     \      |  height
*  height   |    10(db)  100(r)      left       25(r)  150(b)    case 2   25(b)  150(b)  |    2    
*    2      |           /   \      -------->   // \      / \    ------>   / \     / \    |           
*           |        50(b) 150(b)             -  50(b)  -  -             - 50(r) -  -    v                       
*           |        / \    / \                  /  \                      / \     
*           v       -  -   -  -                 -   -                     -  -     
*/                                                                                
void test_polling_left_remove_function_given_sibling_is_red_should_call_case3_and_case_2(void){
  Node *root = &node25;
  Node *removeNode = &node10;
  
  initNode(&node10, 10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, 50, NULL, NULL, BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  initNode(&node100, 100, &node50, &node150, RED);
  initNode(&node25, 25, &node10, &node100, BLACK);
  
  pollLeftRemove(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, BLACK, &node150);
  TEST_ASSERT_EQUAL_NODE(25, NULL, &node50, BLACK, &node25);
  TEST_ASSERT_EQUAL_NODE(100, &node25, &node150, BLACK, &node100);
}

/**
*RIGHT double black
*-----------------
*Testing case(2a): The sibling is black and both sibling's children
*                  are black (with the parent being black).
*
*           ^              /                            //      ^    
*           |            150(b)                       150(db)   |
*           |           /   \\       flip            /   \      |  height
*  height   |         25(b)  -      color          25(r)  -     |    2    
*    3      |        /   \         -------->      /   \         |         
*           |     5(b)  100(b)                  5(b)  100(b)    |            
*           |    /  \    /  \                  /  \   /  \      |        
*           |   -   -   -    -                -   -  -    -     v                     
*           |
*           v
*
*/
void test_polling_right_remove_function_given_sibling_is_black_and_both_sibling_children_are_black_should_call_rightCase2b_function(void){
  Node *root = &node150;
  Node *removeNode = &node0;
  
  initNode(&node5, 5, NULL, NULL, BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node0, 0, NULL, NULL, DOUBLE_BLACK);
  initNode(&node25, 25, &node5, &node100, BLACK);
  initNode(&node150, 150, &node25, &node0, BLACK);
  
  pollRightRemove(&root, removeNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(25, &node5, &node100, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(150, &node25, NULL, DOUBLE_BLACK, &node150);
}
