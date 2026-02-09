#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdlib.h> // For malloc
#include <stdio.h>  // For printf

// --- Data Structures ---

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Typedef for a pointer to a Node
typedef Node* NodePtr;

// --- Function Prototypes (Your Part) ---

/**
 * Creates a new node with the given data using Dynamic Memory Allocation.
 * @param data The integer value to store in the node.
 * @return A pointer to the newly created node.
 */
NodePtr createNode(int data);

/**
 * Inserts a new value into the BST.
 * @param root The root of the tree.
 * @param data The value to insert.
 * @return The new root of the tree.
 */
NodePtr insert(NodePtr root, int data);

#endif // BST_NODE_H