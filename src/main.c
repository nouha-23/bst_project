#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

int main() {
    NodePtr root = NULL;
    int choice, value;
    
    // Seed for potential random operations if added later
    // srand(time(NULL));

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