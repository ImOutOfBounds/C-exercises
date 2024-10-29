/*
Faça uma função que recebe um (ponteiro para um) elemento de
uma lista ligada e inverte os 2 elementos seguintes

imprima a lista antes e depois para demonstrar que funciona
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct linkList {
    int value;
    struct linkList *next;
} linkListStruct;

void addToList(int x, linkListStruct *p) {
    linkListStruct *novoItem = malloc(sizeof(linkListStruct));
    if (novoItem == NULL) {
        return;
    }
    novoItem->value = x;
    novoItem->next = p->next;
    p->next = novoItem;
}

void invertNextTwoItems(linkListStruct *p) {
    if (p->next == NULL || p->next->next == NULL) {
        return;
    }

    linkListStruct *firstPoint = p->next;
    linkListStruct *secondPoint = firstPoint->next;

    firstPoint->next = secondPoint->next;  
    secondPoint->next = firstPoint;        
    p->next = secondPoint;         
}

void printList(linkListStruct *head) {
    linkListStruct *current = head->next;  
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    linkListStruct listaTeste;
    listaTeste.next = NULL; 

    addToList(1, &listaTeste);
    addToList(2, &listaTeste);
    addToList(3, &listaTeste);
    addToList(4, &listaTeste);

    printf("Lista original:\n");
    printList(&listaTeste);

    invertNextTwoItems(&listaTeste);

    printf("Lista invertida:\n");
    printList(&listaTeste);

    return 0;
}
