// Doubly linked list illustration ... COMP9024 25T0 Joffrey Ji
#include "doubly_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List s = NULL; // Initialize the doubly linked list
    int option;
    int key, data, pos;

    do {
        printf("\nWhat operation do you want to perform? Select option number. Enter 0 to exit.\n");
        printf("1. appendLL()\n");
        printf("2. prependLL()\n");
        printf("3. insertAtLL()\n");
        printf("4. deleteLL()\n");
        printf("5. updateLL()\n");
        printf("6. showLL()\n");
        printf("7. Clear Screen\n");

        scanf("%d", &option);

        switch (option) {
            case 0:
                break;

            case 1:
                printf("Append Node Operation\nEnter data of the Node to be appended: ");
                scanf("%d", &data);
                s = appendLL(s, data);
                break;

            case 2:
                printf("Prepend Node Operation\nEnter data of the Node to be prepended: ");
                scanf("%d", &data);
                s = prependLL(s, data);
                break;

            case 3:
                printf("Insert Node Operation\nEnter position (0-based) to insert the Node: ");
                scanf("%d", &pos);
                printf("Enter data of the Node to be inserted: ");
                scanf("%d", &data);
                s = insertAtLL(s, data, pos);
                break;

            case 4:
                printf("Delete Node Operation\nEnter data of the Node to be deleted: ");
                scanf("%d", &data);
                s = deleteLL(s, data);
                break;

            case 5:
                printf("Update Node Operation\nEnter existing data of the Node: ");
                scanf("%d", &key);
                printf("Enter new data for the Node: ");
                scanf("%d", &data);
                s = updateLL(s, key, data);
                break;

            case 6:
                printf("Print List Operation\n");
                showLL(s);
                break;

            case 7:
                system("clear"); // Clear screen (use "cls" for Windows)
                break;

            default:
                printf("Enter proper option number\n");
        }
    } while (option != 0);

    freeLL(s); // Free the memory allocated for the list
    printf("Exiting program.\n");
    return 0;
}
