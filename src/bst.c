#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// Create a new node with the given value
NodePtr createNode(int value) {
    // Dynamic Memory Allocation using malloc
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the BST
NodePtr insert(NodePtr root, int value) {
    // If tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // if value matches root->data, we don't insert duplicate

    // return the (unchanged) node pointer
    return root;
}


// Search for a value in the BST
bool search(NodePtr root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;

    if (value > root->data)
        return search(root->right, value);

    return search(root->left, value);
}

// Helper to find minimum value node in a subtree (successor)
NodePtr getSuccessor(NodePtr curr) {
    curr = curr->right;
    while (curr && curr->left)
        curr = curr->left;
    return curr;
}

// Delete a node with the given value
NodePtr deleteNode(NodePtr root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        NodePtr succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}



