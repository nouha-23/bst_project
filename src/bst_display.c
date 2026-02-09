#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// Display tree structure with indentation
void displayTree(NodePtr root, int space) {
    if (root == NULL) {
        return;
    }
    
    // Increase distance between levels
    space += 5;
    
    // Print right child first (top of display)
    displayTree(root->right, space);
    
    // Print current node with indentation
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    // Print left child (bottom of display)
    displayTree(root->left, space);
}

// Wrapper function for easier use
void display(NodePtr root) {
    printf("\n=== Tree Structure ===\n");
    displayTree(root, 0);
    printf("======================\n");
}