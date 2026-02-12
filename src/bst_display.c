#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// Recursive helper to display the tree structure
// 'space' tracks the indentation level
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

// Wrapper function to display the tree clearly
void display(NodePtr root) {
    printf("\n=== Tree Structure ===\n");
    if (root == NULL) {
        printf("(Empty Tree)\n");
    } else {
        displayTree(root, 0);
    }
    printf("======================\n");
}