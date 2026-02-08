#include <stdio.h>
#include "bst_node.h"

// Helper function for verification (not part of the core API, but needed for testing)
void simple_inorder(NodePtr root) {
    if (root != NULL) {
        simple_inorder(root->left);
        printf("%d ", root->data);
        simple_inorder(root->right);
    }
}

int main() {
    printf("--- Testing BST Insert Operations ---\n");

    NodePtr root = NULL;

    // Test 1: Insert into empty tree
    printf("Inserting 50...\n");
    root = insert(root, 50);

    // Test 2: Insert smaller value (left)
    printf("Inserting 30...\n");
    root = insert(root, 30);

    // Test 3: Insert larger value (right)
    printf("Inserting 70...\n");
    root = insert(root, 70);

    // Test 4: Insert more values
    printf("Inserting 20, 40, 60, 80...\n");
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Tree structure (In-order verificaton): ");
    simple_inorder(root);
    printf("\n");

    printf("Test Complete.\n");
    return 0;
}
