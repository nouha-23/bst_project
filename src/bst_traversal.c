#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// Inorder Traversal: Left -> Root -> Right
// Used to retrieve data in sorted order
void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal: Root -> Left -> Right
// Used to create a copy of the tree or prefix notation
void preorder(NodePtr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
// Used to delete the tree (free memory) or postfix notation
void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
