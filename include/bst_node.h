#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* NodePtr;

// Core BST Operations (bst.c)
NodePtr createNode(int value);
NodePtr insert(NodePtr root, int value);
bool search(NodePtr root, int value);
NodePtr deleteNode(NodePtr root, int value);

// Traversal Operations (bst_traversal.c)
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);

// Display Operations (bst_display.c)
void display(NodePtr root);
void displayTree(NodePtr root, int space);

#endif // BST_NODE_H
