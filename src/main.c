#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

// Declare your functions (or include a header with them)
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void display(NodePtr root);

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
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d successfully!\n", value);
                break;
                
            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    display(root);
                }
                break;
                
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
                
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}