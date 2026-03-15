#include <stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node* next;
};



void traverse(struct node*a)
{
   while (a != NULL)
   {
    printf("Element : %d\n", a->data);
    a = a->next;  //This assign a to dereference the ptr in loop and will help loop to move forward to other struct nodes if it is not there then there will be nothing pointing to another node and a not equal to NULL will always be true
   }
}






int stackisempty (struct node*top) {
    if (top  == NULL)   //forgot
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty\n");
        return 0;
    }
}






int stackisfull () 
{
    struct node* p = (struct node*)malloc(sizeof(struct node)); //Here we are not using stack memory but heap memory. So if we cannot allocate any more memory that means no more nodes that means bucket is full so end (technically this is heap is full)
    if (p == NULL)
    {
        printf("Stack is full\n");
        return 1;
    }
    else
    {
        free(p);
        //printf("Stack is not full\n");    Unnecessary print everytime you will use push
        return 0;
    }
}






                        /*Weak*/
struct node* push (struct node* top,int x)
{
    if (stackisfull()==1)
    /*if (stackisfull(top)) means "if the function returns any non-zero value (i.e., 1), treat it as true."*/
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->next=top;
    p->data=x;
    top = p;
    return top;
    }
}
                        /*Weak*/


/*POP in linked list is very tough so left for later*/


int peek (struct node*top,int index)
{
    struct node* p = top;
    for (int i = 0; i < index && p != NULL; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
    
}



int stacktop (struct node* top)
{
    return top->data;
}

int stackbottom (struct node* top)
{

}





int main() {


struct node* top = NULL;
top = push(top,87);
top = push(top,91);
top = push(top,75);
traverse(top);
printf("%d\n",peek(top,0));
printf("%d\n",stacktop(top));
return 0;
}