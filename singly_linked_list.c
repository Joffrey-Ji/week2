// singly linked list implementation ... COMP9024 25T0 Joffrey Ji
#include "singly_list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
   int         v;
   struct Node *next; 
} Node;

Node *makeNode(int n) {
   Node *new = malloc(sizeof(Node));
   assert(new != NULL);
   new->v = n;
   new->next = NULL;
   return new;
}

List insertLL(List L, int n) {
   if (inLL(L, n))
      return L;

   // add new node at the beginning
   Node *new = makeNode(n);
   new->next = L;
   return new;
}

List deleteLL(List L, int n) {
   if (L == NULL) {
      return L;
   } else if (L->v == n) {
      Node *p = L->next;
      free(L);
      return p;
   } else {
      L->next = deleteLL(L->next, n);
      return L;
   }
}

bool inLL(List L, int n) {
   if (L == NULL)
      return false;
   if (L->v == n)
     return true;

   return inLL(L->next, n);
}

// void showLL(List L) {
//    if (L == NULL)
//       putchar('\n');
//    else {
//       printf("%d ", L->v);
//       showLL(L->next);
//    }
// }

void showLL(List L) {
   while (L != NULL) {
      printf("%d", L->v);
      if (L->next != NULL) {
         printf(" --> ");
      }
      L = L->next;
   }
   putchar('\n');
}

void freeLL(List L) {
   if (L != NULL) {
      freeLL(L->next);
      free(L);
   }
}

void traverseLL(List L) {
   printf("Traversing linked list:\n");
   while (L != NULL) {
      printf("%d -> ", L->v);
      L = L->next;
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
   return L;
}

List prependLL(List L, int n) {
   Node *new = makeNode(n);
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
