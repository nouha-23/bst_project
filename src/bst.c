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

int main() {
    NodePtr root = NULL;
    int choice, value;

    while (1) {
        printf("\n========== BST Menu ==========\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree Structure\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Search for a Value\n");
        printf("7. Delete a Value\n");
        printf("8. Exit\n");
        printf("==============================\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
             while(getchar() != '\n'); // Clear input buffer
             printf("Invalid input. Please enter a number.\n");
             continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted/checked.\n", value);
                break;
                
            case 2:
                display(root);
                break;
                
            case 3:
                printf("Inorder Traversal: ");
                if (root == NULL) printf("(Empty)");
                else inorder(root);
                printf("\n");
                break;
                
            case 4:
                printf("Preorder Traversal: ");
                if (root == NULL) printf("(Empty)");
                else preorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Postorder Traversal: ");
                if (root == NULL) printf("(Empty)");
                else postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d NOT found.\n", value);
                }
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Delete operation for %d completed.\n", value);
                break;
                
            case 8:
                printf("Exiting program. Goodbye!\n");
                // Free memory would be good here, but OS handles it on exit
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}