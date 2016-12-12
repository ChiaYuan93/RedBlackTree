#include "unity.h"
#include "rbtRemove.h"

void setUp(void){}

void tearDown(void){}

/**
*Left double black
*-----------------
*Testing case(1a): The sibling is black and the sibling's right child
*                  is red (with the parent being red).
*
*           ^       /                             /       ^    
*           |      2(r)         rotate          3(r)      |
*           |     //  \          Left          /  \       |   height
*  height   |    .    3(b)      ------>      2(b)  5(b)   |     3     
*    3      |        /  \                   / \    / \    |         
*           |       .   5(r)               .  .   .   .   |            
*           |          /  \                               v        
*           |         .    .                                        
*           |
*           v
*
*/
void test_module_generator_needs_to_be_implemented(void)
{
	
}
