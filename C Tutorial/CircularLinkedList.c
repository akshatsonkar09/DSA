#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void display(struct node *last)
{
    struct node *p;
    if (last == NULL)
    {
        printf("List is empty");
        return;
    }
    p = last->next;
    do
    {
        printf("%d", p->info);
        p = p->next;
    } while (p != last->next);
    printf("/n");
}

struct node *addatbeg(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = last->next;
    last->next = tmp;
    return last;
}

struct node *addtoempty(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last = tmp;
    last->next = last;
    return last;
}

struct node *addatend(struct node *last, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = last->next;
    last->next = tmp;
    last = tmp;
    return last;
}

struct node *addafter(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    p = last->next;
    do
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            p->next = tmp;
            if (p == last)
                last = tmp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("%d not present in the list\n", item);
    return last;
}

struct node *create_list(struct node *last)
{
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    last = NULL;
    if (n == 0)
        return last;
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    last = addtoempty(last, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        last = addatend(last, data);
    }
    return last;
}

struct node *del(struct node *last, int data)
{
    struct node *tmp, *p;
    if (last == NULL)
    {
        printf("List is empty");
        return last;
    }
    if (last->next == last && last->info == data) /*Deletion of only node*/
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->next->info == data) /*Deletion of first node*/
    {
        tmp = last->next;
        last->next = tmp->next;
        free(tmp);
        return last;
    }
    p = last->next; /*Deletion in between*/
    while (p->next != last)
    {
        if (p->next->info == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return last;
        }
        p = p->next;
    }
    if (last->info == data) /*Deletion of last node*/
    {
        tmp = last;
        p->next = last->next;
        last = p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n", data);
    return last;
}

int main()
{

    return 0;
}