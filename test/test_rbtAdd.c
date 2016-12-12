#include "unity.h"
#include "Rotation.h"
#include "NodeHelper.h"
#include "Node.h"
#include "CustomAssert.h"
#include "rbtAdd.h"

Node node0,node5, node20, node25, node30, node50, node100, node150;

void setUp(void) {  
  initNode(&node0,     0, NULL, NULL, BLACK);  
  initNode(&node5,     5, NULL, NULL, BLACK);  
  initNode(&node20,   20, NULL, NULL, BLACK);  
  initNode(&node25,   25, NULL, NULL, BLACK);  
  initNode(&node30,   30, NULL, NULL, BLACK);  
  initNode(&node50,   50, NULL, NULL, BLACK);  
  initNode(&node100, 100, NULL, NULL, BLACK);  
  initNode(&node150, 150, NULL, NULL, BLACK);  
}

void tearDown(void) {}

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
  initNode(&node5, 5, &node25, &node50, BLACK);
  
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
  initNode(&node150, 150, &node25, &node20, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, BLACK, &node5);
  TEST_ASSERT_EQUAL_NODE(150, NULL, NULL, RED, &node150);
  TEST_ASSERT_EQUAL_NODE(100, NULL, &node150, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, BLACK, &node50);
}

/**
*	      
*	       root         add new node              root           case 1                   root      
*	       50(B)         node 20                 50(B)           recolor                 50(R)        
*       /  \          ---------->            /     \          -------->              /     \
*   (R)30  100(R)                         (R)30     100(R)                        (B)30     100(B)
*                                         /  \     /    \                         /  \     /    \
*                                      (R)20 NULL NULL  NULL                    (R)20 NULL NULL  NULL
*                                     /  \                                    /  \
*                                   NULL NULL                               NULL NULL
**/
void test_rbtADD_and_checkViolation_given_added_new_node_cause_violation_case1_should_recolor(void){
  Node *root = &node50;
  Node *addNewNode = &node20;
  
  initNode(&node30, 30, NULL, NULL, RED);
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node50, 50, &node30, &node100, BLACK);
  initNode(&node20, 20, &node5, &node25, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, RED, &node20);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, BLACK, &node100);
  TEST_ASSERT_EQUAL_NODE(30, &node20, NULL, BLACK, &node30);
  TEST_ASSERT_EQUAL_NODE(50, &node30, &node100, RED, &node50);
}

/**
*	      
*	       root         add new node               root           case 3                root 
*	       50(B)         node 20                  50(B)         right rotate            25(B)
*       /             ---------->              /   \          ---------->            /  \
*   (R)25                                   (R)25  NULL                          (R)20   50(R)
*                                           /  \                                    
*                                       (R)20 NULL                                  
*                                        /  \                                                            
*                                      NULL NULL                                           
**/
void test_rbtADD_and_checkViolation_given_added_new_node_cause_violation_case3_should_rotate_right(void){
  Node *root = &node50;
  Node *addNewNode = &node20;
  
  initNode(&node25, 25, NULL, NULL, RED);
  initNode(&node50, 50, &node25, NULL, BLACK);
  initNode(&node20, 20, &node5, &node30, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, RED, &node20);
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(25, &node20, &node50, BLACK, &node25);
}

/**
*	      
*	       root         add new node         root            case 3                 root      
*	       5(B)          node 100            5(B)           right rotate            50(B)        
*          \          ---------->         /   \           ------------>          /   \
*          50(R)                       NULL   50(R)                           (R)5   100(R)
*                                            /   \                              
*                                         NULL   100(R)                         
*                                                /  \                           
*                                               NULL NULL                                                    NULL NULL
**/
void test_rbtADD_and_checkViolation_given_added_new_node_cause_violation_case3_should_rotate_left(void){
  Node *root = &node5;
  Node *addNewNode = &node100;
  
  initNode(&node50, 50, NULL, NULL, RED);
  initNode(&node5, 5, NULL, &node50, BLACK);
  initNode(&node100, 100, &node25, &node150, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, RED, &node5);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, BLACK, &node50);
}

/**
*	      
*	       root    add new node     root     case 2               root     case 3          root
*	       50(B)   node 25          50(B)   left rotate          50(B)    right rotate     25(B)
*       /        ---------->     /        ---------->         /   \     --------->      /  \
*   (R)20                      (R)20                       (R)25  NULL              (R)20  50(R)
*                              /  \                         /  \                   
*                           NULL (R)25                  (R)20 NULL 
*                                 /  \                   /  \
*                              NULL NULL               NULL NULL
**/
void test_rbtADD_and_checkViolation_given_added_new_node_cause_violation_case2_and_case3_should_rotate_left_and_right(void){
  Node *root = &node50;
  Node *addNewNode = &node25;
  
  initNode(&node20, 20, NULL, NULL, RED);
  initNode(&node50, 50, &node20, NULL, BLACK);
  initNode(&node25, 25, &node5, &node30, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(20, NULL, NULL, RED, &node20);
  TEST_ASSERT_EQUAL_NODE(50, NULL, NULL, RED, &node50);
  TEST_ASSERT_EQUAL_NODE(25, &node20, &node50, BLACK, &node25);
}

/**
*	      
*	    root     add new node       root      case 2           root         case 3          root
*	    5(B)      node 50           5(B)     right rotate      5(B)        left rotate     50(B) 
*      \      ---------->       /   \     ------------>     /   \        --------->      /  \ 
*     100(R)                 NULL  100(R)                NULL   50(R)                (R)5  100(R) 
*                                 /   \                        /   \                         
*                             (R)50  NULL                   NULL   100(R)
*                                                                 /  \
*                                                              NULL NULL
**/
void test_rbtADD_and_checkViolation_given_added_new_node_cause_violation_case2_and_case3_should_rotate_right_and_left(void){
  Node *root = &node5;
  Node *addNewNode = &node50;
  
  initNode(&node100, 100, NULL, NULL, RED);
  initNode(&node5, 5, NULL, &node100, BLACK);
  initNode(&node50, 50, &node25, &node150, BLACK);
  
  rbtAdd(&root, addNewNode);
  
  TEST_ASSERT_EQUAL_NODE(5, NULL, NULL, RED, &node5);
  TEST_ASSERT_EQUAL_NODE(100, NULL, NULL, RED, &node100);
  TEST_ASSERT_EQUAL_NODE(50, &node5, &node100, BLACK, &node50);
}
