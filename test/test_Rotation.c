#include "unity.h"
#include "Rotation.h"
#include "NodeHelper.h"
#include "Node.h"
#include "CustomAssert.h"

Node node0,node5, node20, node25, node50, node100, node150;

void setUp(void) {  
  initNode(&node0,     0, NULL, NULL, BLACK);  
  initNode(&node5,     5, NULL, NULL, BLACK);  
  initNode(&node20,   20, NULL, NULL, BLACK);  
  initNode(&node25,   25, NULL, NULL, BLACK);  
  initNode(&node50,   50, NULL, NULL, BLACK);  
  initNode(&node100, 100, NULL, NULL, BLACK);  
  initNode(&node150, 150, NULL, NULL, BLACK);  
}

void tearDown(void) {}

/**
*      root     rotate left     root 
*       20     ----------->      20
*      /                        /
*     5                        5
**/
void test_leftRotation_given_one_node_should_do_nothing(void) {
  Node *root = &node20;
	initNode(&node5,   5, NULL, NULL, BLACK);
	initNode(&node20, 20, &node5, NULL, BLACK);

  leftRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(20, &node5, NULL, BLACK, &node20);
}

/**
*      root    rotate left        root 
*       20     ---------->         50 
*         \                       /
*         50                    20
**/
void test_leftRotation_given_20_50_node_should_rotate_left(void) {
  Node *root = &node20;
  initNode(&node20, 20, NULL, &node50, BLACK); 
  initNode(&node50, 50, NULL, NULL, BLACK); 
 
  leftRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node50, root);   
  TEST_ASSERT_EQUAL_NODE(50, &node20, NULL, BLACK, &node50); 
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20); 
}
 
/**
*      root     rotate left       root 
*       20      ---------->       50 
*      /  \                      / 
*     5   50                   20  
*         /                   /  \
*       25                   5   25
**/
void test_leftRotation_given_5_20_25_50_node_should_rotate_left(void) {
  Node *root = &node20;
  initNode(&node25, 25, NULL, NULL, BLACK); 
  initNode(&node5, 5, NULL, NULL, BLACK); 
  initNode(&node50, 50, &node25, NULL, BLACK); 
  initNode(&node20, 20, &node5, &node50, BLACK); 
 
  leftRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node50, root);    
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5); 
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25); 
  TEST_ASSERT_EQUAL_NODE(20, &node5, &node25, BLACK, &node20); 
  TEST_ASSERT_EQUAL_NODE(50, &node20, NULL, BLACK, &node50); 
}

/**
*      root           root 
*       20      --->   20
**/
void test_rightRotation_given_one_node_should_do_nothing(void) {
  Node *root = &node20;
	initNode(&node20, 20, NULL, NULL, BLACK);

  rightRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);  
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, BLACK, &node20);
}

/**
*      root    rotate right       root 
*       50    ------------>        20 
*      /                            \
*    20                             50
**/
void test_rightRotation_given_20_50_node_should_rotate_right(void) {
  Node *root = &node50;
  initNode(&node50, 50, &node20, NULL, BLACK); 
  initNode(&node20, 20, NULL, NULL, BLACK); 
 
  rightRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);   
  TEST_ASSERT_EQUAL_NODE(20, NULL, &node50, BLACK, &node20); 
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50); 
}
 
/**
*          50                       20
*         /      rotate right      /  \
*        20     ------------->    5   50
*       / \                          /
*      5  25                        25
*/
void test_rightRotate_given_5_20_25_50_node_should_rotate_right(void) {
  Node *root = &node50;
  initNode(&node5, 5, NULL, NULL, BLACK);
  initNode(&node25, 25, NULL, NULL, BLACK);
  initNode(&node20, 20, &node5, &node25, BLACK);
  initNode(&node50, 50, &node20, NULL, BLACK);

  rightRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);    
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5); 
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25); 
  TEST_ASSERT_EQUAL_NODE(20, &node5, &node50, BLACK, &node20); 
  TEST_ASSERT_EQUAL_NODE(50, &node25, NULL, BLACK, &node50); 
}

/**
*	       50		 rotate left     50	  rotate right       20
*	      /     ---------->     /     ------------>     / \
* 	   5	     	             20	                     5  50
*	     \	                     \	 
*      20                      5  
**/
void test_leftRight_given_5_20_50_node_should_rotate_left_and_right(void){
	Node *root = &node50;
  initNode(&node20, 20, NULL, NULL, BLACK);
  initNode(&node5, 5, NULL, &node20, BLACK);
  initNode(&node50, 50, &node5, NULL, BLACK);

  leftRightRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);    
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5); 
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, BLACK, &node50); 
  TEST_ASSERT_EQUAL_NODE(20, &node5, &node50, BLACK, &node20); 
}

/**
*	      5	     rotate right    5	     rotate left    	 20
*	       \     ----------->	    \      ----------->	    /  \
*	       25	       	            20	       	           5   25
*	       /		                 /		      
*       20 		                25 		    
**/
void test_rightLeft_given_5_20_25_node_should_rotate_right_and_left(void){
	Node *root = &node5;
  initNode(&node20, 20, NULL, NULL, BLACK);
  initNode(&node25, 25, &node20, NULL, BLACK);
  initNode(&node5, 5, NULL, &node25, BLACK);

  rightLeftRotate(&root);
  
  TEST_ASSERT_COMPARE_NODES(&node20, root);    
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5); 
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, BLACK, &node25); 
  TEST_ASSERT_EQUAL_NODE(20, &node5, &node25, BLACK, &node20); 
}

/**
*	        50(B)          recolor            50(R)     
*	       /   \         ---------->         /   \      
*	    5(R)   100(R)                      5(B)   100(B) 
*	       \                                  \ 
*       25(R)                              25(R) 
**/
void test_recolorCase1_given_left_child_and_grandChild_are_red_should_recolor(void){
  Node *root = &node50;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node5, 5, NULL, &node25, RED);
  initNode(&node50, 50, &node5, &node100, BLACK);
  
  recolorCase1(&root);
  
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, &node25, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, RED, &node50);
}

/**
*	        50(B)          recolor            50(R)     
*	       /   \         ---------->         /   \      
*	    5(R)   100(R)                      5(B)  100(B) 
*	           /                                 / 
*          25(R)                             25(R) 
**/
void test_recolorCase1_given_right_child_and_grandChild_are_red_should_recolor(void){
  Node *root = &node50;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node5, 5, NULL, NULL, RED);
  initNode(&node100, 100, &node25, NULL, RED);
  initNode(&node50, 50, &node5, &node100, BLACK);
  
  recolorCase1(&root);
  
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(100, &node25, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, RED, &node50);
}

/**
*	      100(B)	  rotate left		 100(B)
*	      /          ------>        / 
* 	  25(R)	     	              50(R) 
*	     \	                      /
*      50(R)                  25(R)
**/
void test_leftRotateCase2_given_left_child_and_right_grandChild_are_red_should_rotate_left(void){
  Node *root = &node100;
  
  initNode(&node50, 50, NULL, NULL, RED);
  initNode(&node25, 25, NULL, &node50, RED);
  initNode(&node100, 100, &node25, NULL, BLACK);
  
  leftRotateCase2(&root);
  
  TEST_ASSERT_EQUAL_NODE(100, &node50, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(50, &node25, NULL, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
}

/**
*	      20(B)	     right rotate    	   20(B)
*	        \          ------>	           \
*	       100(R)	       	                 50(R)
*	      /		                              \
*     50(R) 		                          100(R)
**/
void test_rightRotateCase2_given_right_child_and_left_grandChild_are_red_should_rotate_right(void){
  Node *root = &node20;
  
  initNode(&node50, 50, NULL, NULL, RED);
  initNode(&node100, 100, &node50, NULL, RED);
  initNode(&node20, 20, NULL, &node100, BLACK);
  
  rightRotateCase2(&root);
  
  TEST_ASSERT_EQUAL_NODE(20, NULL, &node50, BLACK, &node20);
  TEST_ASSERT_EQUAL_NODE(50, NULL, &node100, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
}

/**
*	       	 100(B)    right rotate          50(B)
*	        /         ------------->        /  \
* 	   50(R)                         25(R)  100(R)
*	      /
*     25(R)
**/
void test_rightRotateCase3_given_left_child_and_left_grandChild_are_red_should_rotate_right(void){
  Node *root = &node100;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node50, 50, &node25, NULL, RED);
  initNode(&node100, 100, &node50, NULL, BLACK);
  
  rightRotateCase3(&root);
  
  TEST_ASSERT_EQUAL_NODE(50, &node25, &node100, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
}

/**
*	      25(B)      left rotate        50(B)
*	        \        ---------->       /  \
*	       50(R)                   25(R)  100(R)
*	         \
*        100(R)
**/
void test_leftRotateCase3_given_right_child_and_right_grandChild_are_red_should_rotate_left(void){
  Node *root = &node25;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node50, 50, NULL, &node100, RED);
  initNode(&node25, 25, NULL, &node50, BLACK);
  
  leftRotateCase3(&root);
  
  TEST_ASSERT_EQUAL_NODE(50, &node25, &node100, BLACK, &node50);
  TEST_ASSERT_EQUAL_NODE(25, NULL, NULL, RED, &node25);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
}

/**
*	Description : To test if the root is NULL and add new node,   
*	              the new node should become root with null at left and right.    
*	      
*	        root      add new node    root
*	       NULL(B)    ----------->     5(R)
*                                   / \
*                                NULL NULL      
**/
void test_rbtADD_given_root_is_null_new_node_should_become_red_color_root(void){
  Node *root = &node0;
  Node *addNewNode = &node5;
  
  initNode(&node0, 0, NULL, NULL, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, RED, &node5);
}

/**
*	      
*	       root         add new node      root
*	       50(B)        ---------->       50(B)
*       /  \                           /    \
*   (B)5  100(B)                   (B)5     100(B)
*                                   /  \    /    \
*                                NULL NULL NULL  150(R)
*                                                /  \
*                                              NULL NULL
**/
void test_rbtADD_given_added_new_node_larger_than_root_and_righ_child_should_place_at_right(void){
  Node *root = &node50;
  Node *addNewNode = &node150;
  
  initNode(&node5, 5, NULL, NULL, BLACK);
  initNode(&node100, 100, NULL, NULL, BLACK);
  initNode(&node50, 50, &node5, &node100, BLACK);
  initNode(&node150, 150, NULL, NULL, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, RED, &node150);
  TEST_ASSERT_EQUAL_NODE(100, NULL, &node150, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, BLACK, &node50);
}
