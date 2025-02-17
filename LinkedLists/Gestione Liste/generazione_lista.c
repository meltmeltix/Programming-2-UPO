#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxNodes 5

typedef struct node {
    int data;
    struct node *next;
} Node;

void genera_lsta(Node** listHead) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* tail = NULL;

    for(unsigned short int i = 0; i < maxNodes; i++) {
        if(i == 0) {
            head = malloc(sizeof(Node));

            if(head != NULL) {
                tail = head;
                head->data =  rand() % (50 - 0 + 1) + 0;
                head->next = NULL;
            } else {
                head = NULL;
            }
        } else {
            temp = malloc(sizeof(Node));

            if(temp != NULL) {
                tail->next = temp;
                tail = temp;
                tail->data = rand() % (50 - 0 + 1) + 0;
                tail->next = NULL;
            } else {
                head = NULL;
            }
        }
    }

    *listHead = head;
}

void visualizza_lista(Node* listHead) {
    printf("Lista generata: ");

    while(listHead != NULL) {
        printf("%d ", listHead->data);
        listHead = listHead->next;

        if(listHead != NULL) {
            printf("-> ");
        } else {
            printf("-> NULL");
        }
    }

    printf("\n");
}

int main(void) {
    Node* randList;

    srand(time(NULL));

    genera_lsta(&randList);
    visualizza_lista(randList);

    return 0;
}