#include "CustomAssert.h"
#include "Node.h"
#include "NodeHelper.h"
#include "Rotation.h"
#include "unity.h"




Node node0,node5, node20, node25, node30, node50, node100, node150;



void setUp(void) {

  initNode(&node0, 0, ((void *)0), ((void *)0), BLACK);

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



  testAssertCompareNodes(&node20, root, 35);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 36);;

  testAssertNode(20, &node5, ((void *)0), BLACK, &node20, 37);;

}















void test_leftRotation_given_20_50_node_should_rotate_left(void) {

  Node *root = &node20;

  initNode(&node20, 20, ((void *)0), &node50, BLACK);

  initNode(&node50, 50, ((void *)0), ((void *)0), BLACK);



  leftRotate(&root);



  testAssertCompareNodes(&node50, root, 53);;

  testAssertNode(50, &node20, ((void *)0), BLACK, &node50, 54);;

  testAssertNode(20, ((void *)0), ((void *)0), BLACK, &node20, 55);;

}

void test_leftRotation_given_5_20_25_50_node_should_rotate_left(void) {

  Node *root = &node20;

  initNode(&node25, 25, ((void *)0), ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

  initNode(&node50, 50, &node25, ((void *)0), BLACK);

  initNode(&node20, 20, &node5, &node50, BLACK);



  leftRotate(&root);



  testAssertCompareNodes(&node50, root, 75);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 76);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 77);;

  testAssertNode(20, &node5, &node25, BLACK, &node20, 78);;

  testAssertNode(50, &node20, ((void *)0), BLACK, &node50, 79);;

}











void test_rightRotation_given_one_node_should_do_nothing(void) {

  Node *root = &node20;

 initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 92);;

  testAssertNode(20, ((void *)0), ((void *)0), BLACK, &node20, 93);;

}















void test_rightRotation_given_20_50_node_should_rotate_right(void) {

  Node *root = &node50;

  initNode(&node50, 50, &node20, ((void *)0), BLACK);

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 109);;

  testAssertNode(20, ((void *)0), &node50, BLACK, &node20, 110);;

  testAssertNode(50, ((void *)0), ((void *)0), BLACK, &node50, 111);;

}

void test_rightRotate_given_5_20_25_50_node_should_rotate_right(void) {

  Node *root = &node50;

  initNode(&node5, 5, ((void *)0), ((void *)0), BLACK);

  initNode(&node25, 25, ((void *)0), ((void *)0), BLACK);

  initNode(&node20, 20, &node5, &node25, BLACK);

  initNode(&node50, 50, &node20, ((void *)0), BLACK);



  rightRotate(&root);



  testAssertCompareNodes(&node20, root, 130);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 131);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 132);;

  testAssertNode(20, &node5, &node50, BLACK, &node20, 133);;

  testAssertNode(50, &node25, ((void *)0), BLACK, &node50, 134);;

}

void test_leftRightRotate_given_5_20_50_node_should_rotate_left_and_right(void){

 Node *root = &node50;

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), &node20, BLACK);

  initNode(&node50, 50, &node5, ((void *)0), BLACK);



  leftRightRotate(&root);



  testAssertCompareNodes(&node20, root, 152);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 153);;

  testAssertNode(50, ((void *)0), ((void *)0), BLACK, &node50, 154);;

  testAssertNode(20, &node5, &node50, BLACK, &node20, 155);;

}

void test_rightLeftRotate_given_5_20_25_node_should_rotate_right_and_left(void){

 Node *root = &node5;

  initNode(&node20, 20, ((void *)0), ((void *)0), BLACK);

  initNode(&node25, 25, &node20, ((void *)0), BLACK);

  initNode(&node5, 5, ((void *)0), &node25, BLACK);



  rightLeftRotate(&root);



  testAssertCompareNodes(&node20, root, 173);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 174);;

  testAssertNode(25, ((void *)0), ((void *)0), BLACK, &node25, 175);;

  testAssertNode(20, &node5, &node25, BLACK, &node20, 176);;

}

void test_recolorCase1_given_left_child_and_grandChild_are_red_should_recolor(void){

  Node *root = &node50;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, ((void *)0), ((void *)0), RED);

  initNode(&node5, 5, ((void *)0), &node25, RED);

  initNode(&node50, 50, &node5, &node100, BLACK);



  recolorCase1(&root);



  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 196);;

  testAssertNode(100, ((void *)0), ((void *)0), BLACK, &node100, 197);;

  testAssertNode(5, ((void *)0), &node25, BLACK, &node5, 198);;

  testAssertNode(50, &node5, &node100, RED, &node50, 199);;

}

void test_recolorCase1_given_right_child_and_grandChild_are_red_should_recolor(void){

  Node *root = &node50;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node5, 5, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, &node25, ((void *)0), RED);

  initNode(&node50, 50, &node5, &node100, BLACK);



  recolorCase1(&root);



  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 219);;

  testAssertNode(5, ((void *)0), ((void *)0), BLACK, &node5, 220);;

  testAssertNode(100, &node25, ((void *)0), BLACK, &node100, 221);;

  testAssertNode(50, &node5, &node100, RED, &node50, 222);;

}

void test_leftRotateCase2_given_left_child_and_right_grandChild_are_red_should_rotate_left(void){

  Node *root = &node100;



  initNode(&node50, 50, ((void *)0), ((void *)0), RED);

  initNode(&node25, 25, ((void *)0), &node50, RED);

  initNode(&node100, 100, &node25, ((void *)0), BLACK);



  leftRotateCase2(&root);



  testAssertNode(100, &node50, ((void *)0), BLACK, &node100, 241);;

  testAssertNode(50, &node25, ((void *)0), RED, &node50, 242);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 243);;

}

void test_rightRotateCase2_given_right_child_and_left_grandChild_are_red_should_rotate_right(void){

  Node *root = &node20;



  initNode(&node50, 50, ((void *)0), ((void *)0), RED);

  initNode(&node100, 100, &node50, ((void *)0), RED);

  initNode(&node20, 20, ((void *)0), &node100, BLACK);



  rightRotateCase2(&root);



  testAssertNode(20, ((void *)0), &node50, BLACK, &node20, 262);;

  testAssertNode(50, ((void *)0), &node100, RED, &node50, 263);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 264);;

}

void test_rightRotateCase3_given_left_child_and_left_grandChild_are_red_should_rotate_right(void){

  Node *root = &node100;



  initNode(&node25, 25, ((void *)0), ((void *)0), RED);

  initNode(&node50, 50, &node25, ((void *)0), RED);

  initNode(&node100, 100, &node50, ((void *)0), BLACK);



  rightRotateCase3(&root);



  testAssertNode(50, &node25, &node100, BLACK, &node50, 283);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 284);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 285);;

}

void test_leftRotateCase3_given_right_child_and_right_grandChild_are_red_should_rotate_left(void){

  Node *root = &node25;



  initNode(&node100, 100, ((void *)0), ((void *)0), RED);

  initNode(&node50, 50, ((void *)0), &node100, RED);

  initNode(&node25, 25, ((void *)0), &node50, BLACK);



  leftRotateCase3(&root);



  testAssertNode(50, &node25, &node100, BLACK, &node50, 304);;

  testAssertNode(25, ((void *)0), ((void *)0), RED, &node25, 305);;

  testAssertNode(100, ((void *)0), ((void *)0), RED, &node100, 306);;

}
