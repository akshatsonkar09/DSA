#include <stdio.h>
#include <stdlib.h>




struct node
{
    int data;
    struct node* next;
};





void traverse (struct node*ptr)
{
    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}






void enqueue (struct node*f, struct node*r, int val)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));

    if (new==NULL)
    {
        printf("Queue is Full");        //Which is almost impossible as it only happens when no more memory is left
    }
    else
    {
        new->data = val;
        new->next = NULL;
        if (f==NULL)    //This is for cases if both queue is empty
        {
            f=r=new;
        }
        else
        {
            r->next=new;
            r=new;
        }
    }
}





int dequeue (struct node* f)
{
    int val = -1;
    struct node* ptr;
    if (f==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        f=f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}






int main() {


struct node* f = (struct node*)malloc(sizeof(struct node));
struct node* first = (struct node*)malloc(sizeof(struct node));
struct node* second = (struct node*)malloc(sizeof(struct node));
struct node* r = (struct node*)malloc(sizeof(struct node));


f->next=first;
f->data=8;

first->next=second;
first->data=12;

second->next=r;
second->data=16;

r->next=NULL;
r->data=30;

traverse(f);
enqueue(f,r,35);
traverse(f);




return 0;
}