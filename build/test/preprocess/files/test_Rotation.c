#include "CustomAssert.h"
#include "Node.h"
#include "NodeHelper.h"
#include "Rotation.h"
#include "unity.h"




Node node5, node20, node25, node30, node50, node100, node150;



void setUp(void) {

  initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);

  initNode(&node25, 25, ((void *)0), ((void *)0), BLACK);

  initNode(&node30, 30, ((void *)0), ((void *)0), BLACK);

  initNode(&node50, 50, ((void *)0), ((void *)0), BLACK);

  initNode(&node100, 100, ((void *)0), ((void *)0), BLACK);

  initNode(&node150, 150, ((void *)0), ((void *)0), BLACK);

}



void tearDown(void) {}















void test_leftRotation_given_one_node_should_do_nothing(void) {

  Node *root = &node20;

 initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

 initNode(&node20, 20, &node5, ((void *)0), BLACK);



  leftRotate(&root);



  testAssertCompareNodes(&node20, root, 34);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 35);;

  testAssertNode(20, &node5, ((void *)0), BLACK, &node20, 36);;

}















void test_leftRotation_given_20_50_node_should_rotate_left(void) {

  Node *root = &node20;

  initNode(&node20, 20, ((void *)0), &node50, BLACK);

  initNode(&node50, 50, ((void *)0), ((void *)0), BLACK);



  leftRotate(&root);



  testAssertCompareNodes(&node50, root, 52);;

  testAssertNode(50, &node20, ((void *)0), BLACK, &node50, 53);;

  testAssertNode(20, ((void *)0), ((void *)0), BLACK, &node20, 54);;

}

void test_leftRotation_given_5_20_25_50_node_should_rotate_left(void) {

  Node *root = &node20;

  initNode(&node25, 25, ((void *)0), ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

  initNode(&node50, 50, &node25, ((void *)0), BLACK);

  initNode(&node20, 20, &node5, &node50, BLACK);



  leftRotate(&root);



  testAssertCompareNodes(&node50, root, 74);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 75);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 76);;

  testAssertNode(20, &node5, &node25, BLACK, &node20, 77);;

  testAssertNode(50, &node20, ((void *)0), BLACK, &node50, 78);;

}











void test_rightRotation_given_one_node_should_do_nothing(void) {

  Node *root = &node20;

 initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 91);;

  testAssertNode(20, ((void *)0), ((void *)0), BLACK, &node20, 92);;

}















void test_rightRotation_given_20_50_node_should_rotate_right(void) {

  Node *root = &node50;

  initNode(&node50, 50, &node20, ((void *)0), BLACK);

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 108);;

  testAssertNode(20, ((void *)0), &node50, BLACK, &node20, 109);;

  testAssertNode(50, ((void *)0), ((void *)0), BLACK, &node50, 110);;

}

void test_rightRotate_given_5_20_25_50_node_should_rotate_right(void) {

  Node *root = &node50;

  initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

  initNode(&node25, 25, ((void *)0), ((void *)0), BLACK);

  initNode(&node20, 20, &node5, &node25, BLACK);

  initNode(&node50, 50, &node20, ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 129);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 130);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 131);;

  testAssertNode(20, &node5, &node50, BLACK, &node20, 132);;

  testAssertNode(50, &node25, ((void *)0), BLACK, &node50, 133);;

}

void test_leftRightRotate_given_5_20_50_node_should_rotate_left_and_right(void){

 Node *root = &node50;

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), &node20, BLACK);

  initNode(&node50, 50, &node5, ((void *)0), BLACK);



  leftRightRotate(&root);



  testAssertCompareNodes(&node20, root, 151);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 152);;

  testAssertNode(50, ((void *)0), ((void *)0), BLACK, &node50, 153);;

  testAssertNode(20, &node5, &node50, BLACK, &node20, 154);;

}

void test_rightLeftRotate_given_5_20_25_node_should_rotate_right_and_left(void){

 Node *root = &node5;

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);

  initNode(&node25, 25, &node20, ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), &node25, BLACK);



  rightLeftRotate(&root);



  testAssertCompareNodes(&node20, root, 172);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 173);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 174);;

  testAssertNode(20, &node5, &node25, BLACK, &node20, 175);;

}

void test_recolorCase1_given_left_child_and_grandChild_are_red_should_recolor(void){

  Node *root = &node50;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, ((void *)0), ((void *)0), RED);

  initNode(&node5, 5, ((void *)0), &node25, RED);

  initNode(&node50, 50, &node5, &node100, BLACK);



  recolorCase1(&root);



  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 195);;

  testAssertNode(100, ((void *)0), ((void *)0), BLACK, &node100, 196);;

  testAssertNode(5, ((void *)0), &node25, BLACK, &node5, 197);;

  testAssertNode(50, &node5, &node100, RED, &node50, 198);;

}

void test_recolorCase1_given_right_child_and_grandChild_are_red_should_recolor(void){

  Node *root = &node50;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node5, 5, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, &node25, ((void *)0), RED);

  initNode(&node50, 50, &node5, &node100, BLACK);



  recolorCase1(&root);



  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 218);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 219);;

  testAssertNode(100, &node25, ((void *)0), BLACK, &node100, 220);;

  testAssertNode(50, &node5, &node100, RED, &node50, 221);;

}

void test_leftRotateCase2_given_left_child_and_right_grandChild_are_red_should_rotate_left(void){

  Node *root = &node100;



  initNode(&node50, 50, ((void *)0), ((void *)0), RED);

  initNode(&node25, 25, ((void *)0), &node50, RED);

  initNode(&node100, 100, &node25, ((void *)0), BLACK);



  leftRotateCase2(&root);



  testAssertNode(100, &node50, ((void *)0), BLACK, &node100, 240);;

  testAssertNode(50, &node25, ((void *)0), RED, &node50, 241);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 242);;

}

void test_rightRotateCase2_given_right_child_and_left_grandChild_are_red_should_rotate_right(void){

  Node *root = &node20;



  initNode(&node50, 50, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, &node50, ((void *)0), RED);

  initNode(&node20, 20, ((void *)0), &node100, BLACK);



  rightRotateCase2(&root);



  testAssertNode(20, ((void *)0), &node50, BLACK, &node20, 261);;

  testAssertNode(50, ((void *)0), &node100, RED, &node50, 262);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 263);;

}

void test_rightRotateCase3_given_left_child_and_left_grandChild_are_red_should_rotate_right(void){

  Node *root = &node100;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node50, 50, &node25, ((void *)0), RED);

  initNode(&node100, 100, &node50, ((void *)0), BLACK);



  rightRotateCase3(&root);



  testAssertNode(50, &node25, &node100, BLACK, &node50, 282);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 283);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 284);;

}

void test_leftRotateCase3_given_right_child_and_right_grandChild_are_red_should_rotate_left(void){

  Node *root = &node25;



  initNode(&node100, 100, ((void *)0), ((void *)0), RED);

  initNode(&node50, 50, ((void *)0), &node100, RED);

  initNode(&node25, 25, ((void *)0), &node50, BLACK);



  leftRotateCase3(&root);



  testAssertNode(50, &node25, &node100, BLACK, &node50, 303);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 304);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 305);;

}
