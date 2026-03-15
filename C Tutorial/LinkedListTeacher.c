#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

// --- INSERTION FUNCTIONS ---

struct node *addatbeg(struct node *start, int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = start;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int data) {
    struct node *ptr, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;

    if (start == NULL) {
        return tmp;
    }

    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = tmp;
    return start;
}

struct node *addafter(struct node *start, int data, int item) {
    struct node *tmp, *p = start;
    while (p != NULL) {
        if (p->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", item);
    return start;
}

struct node *addbefore(struct node *start, int data, int item) {
    struct node *tmp, *p;
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (item == start->info) {
        return addatbeg(start, data);
    }
    p = start;
    while (p->next != NULL) {
        if (p->next->info == item) {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", item);
    return start;
}

// --- DELETION FUNCTIONS ---

struct node *delete_node(struct node *start, int data) {
    struct node *tmp, *p;
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    if (start->info == data) {
        tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }
    p = start;
    while (p->next != NULL) {
        if (p->next->info == data) {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return start;
        }
        p = p->next;
    }
    printf("Element %d not found\n", data);
    return start;
}

// --- UTILITY FUNCTIONS ---

void display(struct node *start) {
    struct node *p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is: ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

struct node *reverse(struct node *start) {
    struct node *prev = NULL, *ptr = start, *next;
    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}

// --- MAIN FUNCTION ---

int main() {
    struct node *start = NULL;
    int choice, data, item;

    while (1) {
        printf("\n1. Add at Beginning\n2. Add at End\n3. Add After\n4. Add Before\n5. Delete\n6. Reverse\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: "); scanf("%d", &data);
                start = addatbeg(start, data);
                break;
            case 2:
                printf("Enter data: "); scanf("%d", &data);
                start = addatend(start, data);
                break;
            case 3:
                printf("Enter data: "); scanf("%d", &data);
                printf("Enter item after which to insert: "); scanf("%d", &item);
                start = addafter(start, data, item);
                break;
            case 4:
                printf("Enter data: "); scanf("%d", &data);
                printf("Enter item before which to insert: "); scanf("%d", &item);
                start = addbefore(start, data, item);
                break;
            case 5:
                printf("Enter data to delete: "); scanf("%d", &data);
                start = delete_node(start, data);
                break;
            case 6:
                start = reverse(start);
                break;
            case 7:
                display(start);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}