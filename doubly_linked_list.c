// Doubly linked list implementation ... COMP9024 25T0 Joffrey Ji
#include "doubly_list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
   int         v;
   struct Node *next;
   struct Node *prev; // Pointer to the previous node
} Node;

Node *makeNode(int n) {
   Node *new = malloc(sizeof(Node));
   assert(new != NULL);
   new->v = n;
   new->next = NULL;
   new->prev = NULL;
   return new;
}

List deleteLL(List L, int n) {
   if (L == NULL) {
      return L;
   }
   Node *curr = L;
   while (curr != NULL && curr->v != n) {
      curr = curr->next;
   }
   if (curr == NULL) {
      return L; // Node not found
   }
   if (curr->prev != NULL) {
      curr->prev->next = curr->next;
   } else {
      L = curr->next; // Update head if first node is deleted
   }
   if (curr->next != NULL) {
      curr->next->prev = curr->prev;
   }
   free(curr);
   return L;
}

bool inLL(List L, int n) {
   Node *curr = L;
   while (curr != NULL) {
      if (curr->v == n)
         return true;
      curr = curr->next;
   }
   return false;
}

void showLL(List L) {
   Node *curr = L;
   while (curr != NULL) {
      printf("%d", curr->v);
      if (curr->next != NULL) {
         printf(" <--> ");
      }
      curr = curr->next;
   }
   putchar('\n');
}

void freeLL(List L) {
   Node *curr = L;
   while (curr != NULL) {
      Node *next = curr->next;
      free(curr);
      curr = next;
   }
}

void traverseLL(List L) {
   printf("Traversing linked list:\n");
   Node *curr = L;
   while (curr != NULL) {
      printf("%d <-> ", curr->v);
      curr = curr->next;
   }
   printf("NULL\n");
}

List appendLL(List L, int n) {
   Node *new = makeNode(n);
   if (L == NULL) {
      return new;
   }
   Node *curr = L;
   while (curr->next != NULL) {
      curr = curr->next;
   }
   curr->next = new;
   new->prev = curr;
   return L;
}

List prependLL(List L, int n) {
   Node *new = makeNode(n);
   if (L != NULL) {
      L->prev = new;
   }
   new->next = L;
   return new;
}

List insertAtLL(List L, int n, int pos) {
   if (pos == 0) {
      return prependLL(L, n);
   }
   Node *curr = L;
   for (int i = 0; i < pos - 1 && curr != NULL; i++) {
      curr = curr->next;
   }
   if (curr == NULL) {
      printf("Position out of bounds\n");
      return L;
   }
   Node *new = makeNode(n);
   new->next = curr->next;
   new->prev = curr;
   if (curr->next != NULL) {
      curr->next->prev = new;
   }
   curr->next = new;
   return L;
}

List updateLL(List L, int oldVal, int newVal) {
   Node *curr = L;
   while (curr != NULL) {
      if (curr->v == oldVal) {
         curr->v = newVal;
         break;
      }
      curr = curr->next;
   }
   if (curr == NULL) {
      printf("Value %d not found in the list\n", oldVal);
   }
   return L;
}
