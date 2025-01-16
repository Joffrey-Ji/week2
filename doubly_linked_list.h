// Doubly linked list interface ... COMP9024 25T0 Joffrey Ji
#include <stdbool.h>

typedef struct Node *List;

List deleteLL(List, int);
bool inLL(List, int);
void freeLL(List);
void showLL(List);

void traverseLL(List);
List appendLL(List, int);
List prependLL(List, int);
List insertAtLL(List, int, int); // Insert at specific position (0-based)
List updateLL(List, int, int); // Update a node's value
