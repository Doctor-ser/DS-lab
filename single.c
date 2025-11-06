#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtLocation(struct Node** head_ref, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head_ref, data);
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

void deleteLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteAtLocation(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at location\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete at location\n");
        printf("7. Search\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at Beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at End: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insertAtLocation(&head, value, pos);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtLocation(&head, pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(head, value))
                    printf("%d found in the list.\n", value);
                else
                    printf("%d not found in the list.\n", value);
                break;
            case 8:
                printf("Current list: ");
                display(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

