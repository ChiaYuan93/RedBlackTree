#ifndef CustomAssert_H
#define CustomAssert_H

#include "Node.h"

#define TEST_ASSERT_EQUAL_NODE(v, l, r, c, n)                   \
        testAssertNode(v, l, r, c, n, __LINE__);

#define TEST_ASSERT_COMPARE_NODES(expectedNode, actualNode)     \
        testAssertCompareNodes(expectedNode, actualNode, __LINE__);

void testAssertNode(int value, Node *left, Node *right, Color color, Node *node, int lineNo);
void testAssertCompareNodes(Node *expectedNode, Node *actualNode, int lineNo);

#endif // CustomAssert_H
