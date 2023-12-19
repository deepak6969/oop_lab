#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertElement(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;

    if (head == NULL) {
        head = newNode;
        head->prev = head;
        head->next = head;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
    }

    printf("Element %d inserted successfully.\n", element);
}

void deleteElement(int element) {
    if (head == NULL) {
        printf("List is empty. Cannot delete element.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->data != element) {
        if (current->next == head) {
            printf("Element %d not found in the list.\n", element);
            return;
        }

        prev = current;
        current = current->next;
    }

    if (current == head && current->next == head) {
        head = NULL;
    } else if (current == head) {
        prev = head->prev;
        head = head->next;
        prev->next = head;
        head->prev = prev;
    } else {
        prev->next = current->next;
        current->next->prev = prev;
    }

    free(current);
    printf("Element %d deleted successfully.\n", element);
}

int main() {
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(element);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

