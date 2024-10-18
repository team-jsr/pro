#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *next;
};

// Global variable to keep track of the head of the linked list
struct node *first = NULL;

// Function to insert a node at the end of the linked list
void insert() {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &nn->data);
    nn->next = NULL;

    if (first == NULL) {
        first = nn;
    } else {
        struct node *temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

// Function to display all nodes in the linked list
void display() {
    struct node *temp = first;
    if (temp == NULL) {
        printf("No elements in the linked list\n");
        return;
    }

    printf("Elements in linked list are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to delete the first node from the linked list
void deletion() {
    if (first == NULL) {
        printf("The list is empty, nothing to delete\n");
        return;
    }

    struct node *temp = first;
    first = first->next; // Move the head to the next node
    free(temp); // Free the memory of the old head
    printf("First element deleted\n");
}

int main() {
    int op;
    do {
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insert();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again\n");
        }
    } while (op != 4);

    return 0;
}