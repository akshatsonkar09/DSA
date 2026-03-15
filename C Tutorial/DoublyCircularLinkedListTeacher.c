#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *addatbeg(struct node *start, int data)
{
    struct node *temp, *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\nOverflow");
    else
        ptr->info = data;

    if (start == NULL) /*list is empty*/
    {
        start = ptr;
        ptr->next = start;
        ptr->prev = start;
    }
    else
    {
        /*list is not empty*/
        temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
        start->prev = ptr;
        ptr->next = start;
        start = ptr;
    }
}

struct node *addatend(struct node *start, int data)
{
    struct node *temp, *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\nOverflow");
    else
        ptr->info = data;
    if (start == NULL) /*list is empty*/
    {
        start = ptr;
        ptr->next = start;
        ptr->prev = start;
    }
    else
    {
        /*list is not empty*/
        temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
        start->prev = ptr;
        ptr->next = start;
    }
}

struct node *delatbeg(struct node *start, int data)
{
    struct node *temp;
    if (start == NULL)
        printf("\nUnderflow");
    else if (start->next == start)
    {
        start = NULL;
        free(start);
        printf("Node deleted");
    }
    else
    {
        temp = start;
        while (temp->next != start)
            temp = temp->next;
        temp->next = start->next;
        start->next->prev = temp;
        free(start);
        start = temp->next;
    }
}

struct node *delatbeg(struct node *start, int data)
{
    struct node *ptr;
    if (start == NULL)
        printf("\nUnderflow");
    else if (start->next == start)
    {
        start = NULL;
        free(start);
        printf("Node deleted");
    }
    else
    {
        ptr = start;
        if (ptr->next != start)
            ptr = ptr->next;
        ptr->prev->next = start;
        start->prev = ptr->prev;
        free(ptr);
        printf("node deleted");
    }
}

int main()
{

    return 0;
}