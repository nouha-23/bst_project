#include "bst_node.h"

// createNode implementation
NodePtr createNode(int data) {
    // Dynamic Memory Allocation using malloc
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
