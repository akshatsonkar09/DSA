#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

// --- UTILITY ---
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is: ");
    while (p != NULL)
    {
        printf("%d <-> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

// --- INSERTION ---
struct node *addtoempty(struct node *start, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct node *addatbeg(struct node *start, int data)
{
    if (start == NULL)
        return addtoempty(start, data);
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    if (start == NULL)
        return addtoempty(start, data);
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next = NULL;
    tmp->prev = p;
    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp->prev = p;
            tmp->next = p->next;
            if (p->next != NULL)
                p->next->prev = tmp;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("% d not present in the list\n", item);
    return start;
}

// --- DELETION ---
struct node *del(struct node *start, int data)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    // Deletion of only node
    if (start->next == NULL && start->info == data)
    {
        tmp = start;
        start = NULL;
        free(tmp);
        return start;
    }
    // Deletion of first node
    if (start->info == data)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }
    // Deletion in between or at end
    p = start;
    while (p->next != NULL)
    {
        if (p->next->info == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            if (tmp->next != NULL) // If not last node
                tmp->next->prev = p;
            free(tmp);
            return start;
        }

        p = p->next;
    }
    printf("Element %d not found\n", data);
    return start;
}

// --- REVERSE ---
struct node *reverse(struct node *start)
{
    if (start == NULL || start->next == NULL)
        return start;
    struct node *p1 = start;
    struct node *p2 = p1->next;

    p1->next = NULL;
    p1->prev = p2;

    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; // This works because we just swapped prev and next
    }
    start = p1;
    printf("List reversed\n");
    return start;
}

struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    start = addtoempty(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

int main()
{
    struct node *start = NULL;
    int choice, data;

    while (1)
    {
        printf("\n1. Add Beg\n2. Add End\n3. Delete\n4. Reverse\n5. Display\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Data: ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 2:
            printf("Data: ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;
        case 3:
            printf("Data: ");
            scanf("%d", &data);
            start = del(start, data);
            break;
        case 4:
            start = reverse(start);
            break;
        case 5:
            display(start);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}