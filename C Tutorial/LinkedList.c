#include <stdio.h>
#include <stdlib.h>





struct node
{
    int data;
    /* int *ptr;        //$$ This is a pointer to int and not to a node*/
    struct node* next; //Forgot  //$$ This is a pointer to node and not to a int*/
};





/* This is correct but is not reproducible ie will not repeat*/
// void traverse(struct node*a) {
//     a->data;
//     a->next;
// }

void traverse(struct node*a) {
   while (a != NULL)
   {
    printf("Data is %d\n", a->data);
    a = a->next;  //This assign a to dereference the ptr in loop and will help loop to move forward to other struct nodes if it is not there then there will be nothing pointing to another node and a not equal to NULL will always be true
   }
}





struct node* insertatfirst (struct node* start, int data)
{
    struct node*new = (struct node*)malloc(sizeof(struct node)); //New node is requested in heap memory
    new->data = data;
    new->next = start; // A new node is formed and it is pointing towards start node, making new node the new starting node  
    return new; //This new node is now the new starting node
}





//Insertinbetween is actually insert after which node
struct node* insertinbetween (struct node* start, int data, int index)
{
    struct node*new = (struct node*)malloc(sizeof(struct node));
    struct node* p = start; //It is a p pointer of type struct node which is pointing towards the start of linked list 
    //Reason for 

    
    int i=0;
    while (i!=index-1)  //For index 3 ie 0,1,2,3 use index-1
                        //For place 3 ie 1,2,3 use index-2
    {
        p = p->next;    //The pointer p is pointing towards the start node, the while loops is to shift the pointer p to next node until we have reached the node where we wish to insert the new node
        i++;
    }

    new->data = data;
    /*This part was weak*/
    new->next= p->next;  //This is saying ki new next ko wahan point kara do jahan p ka next point kar raha hai (Concept of Left wala jo karna hai aur right wala jispe karna hai is failing)
    p->next=new; // This is saying ki p ke next ko new node ki taraf point kardo 
    return start;
    /*This part was weak*/
    
}





struct node* insertatend (struct node* start, int data)
{
    struct node*new = (struct node*)malloc(sizeof(struct node));
    struct node* p = start;
    while (p->next !=NULL)
    {
        p= p->next;
    }
    p->next=new;
    new->next = NULL;
    new->data = data;
    return start; //This new is now the new start file
}





struct node* insertafternode (struct node* start, struct node* prevnode, int data) 
{
    struct node*new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next= prevnode->next;
    prevnode->next=new;
    return start;
}





struct node* deletefirst(struct node* start) 
{
    struct node* p = start; //after changing start we need a pointer which is pointing towards previous start to free that memory (pointer works as p in insertion. Just different variable)
    start->next=start; 
    free (p);
}





struct node* deleteatindex (struct node* start, int index)
{
    struct node* p = start;
    struct node* q = start->next;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }

    // struct node* p = start;
    // int i=0;
    // while (i!=index-1)
    // {
    //     p=p->next;
    //     i++;
    // }
    // while (i!=index)
    // {
    //     q=q->next;
    //     i++;
    // }

/*This is also a way to perform above code but it is not elegant ie efficient and small*/
    
p->next=q->next;
free (q);
return start;
}





struct node* deleteatlast (struct node* start)
{
    struct node* p = start;
    struct node* q = start->next;
    int i=0;
    //while (i!=NULL)     //This is not gonna work as with this p will stop at NULL and not before NULL
    while (q->next!=NULL)   //This is gonna work as with this q will stop when it will be pointing NULL while p will point at index just befor NULL
    {
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    // p->next=NULL;
    //Both will work as q->next is basically NULL

    free (q);
    return start;
}





struct node* deleteatvalue (struct node* start, int value)
{
    struct node* p = start;
    struct node* q = start->next;
    int i=0;
    //while (q->data != value || q->next == NULL)   The problem with this is that the code will continue even after finding value as it has to determine whether the second statement is true or false and even after it is false we are accessing q
    while (q->data != value && q->next != NULL)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    if (q->data == value)
    {
        p->next=q->next;
        free (q);
    }
    
    return start;
}






int main() {






struct node* start;
struct node* first;
struct node* second;
struct node* last;

/*
1) struct node start;
This creates one actual node, directly in memory.

You can use it like:

struct node start;
start.data = 10;
start.next = NULL;
But it’s just one node, not connected to others unless you embed others directly — which we don’t do in linked lists.

2) struct node *start;
This creates a pointer to a node. You can make it point to:

Dynamically allocated memory (malloc)
Another node in memory
This is what allows you to build a linked list:

struct node *start = malloc(sizeof(struct node));
start->data = 10;
start->next = malloc(sizeof(struct node));
start->next->data = 20;
Now you have a chain of nodes — which is exactly what linked lists need!*/



/*
Question) Will this not work?
struct node start;
start.data = 10;
start.next = first;

But: Why it’s NOT used for real linked lists?
1) Fixed size: You have to declare all nodes manually (start, first, second,...). What if you want 1000? 
You can't do:
struct node a1, a2, a3, ..., a1000; // 😵

2)Stack memory limits: Local struct node variables are stored on the stack, which has limited size.

3)No runtime flexibility: You can't add or delete nodes while the program is running — which is the whole point of linked lists.
*/



/*
struct node start; → A real box (a single object)
struct node *start; → A remote control (pointer) that can point to different boxes

To build a chain (linked list), you need remote controls (pointers) that can point from one box to another.
*/








start = /*(struct node*)*/malloc(sizeof(struct node));
first = /*(struct node*)*/malloc(sizeof(struct node));
second = /*(struct node*)*/malloc(sizeof(struct node));
last = /*(struct node*)*/malloc(sizeof(struct node));

/*
Option 1 (with cast — mostly used in C++):
start = (struct node*)malloc(sizeof(struct node));

Option 2 (recommended in pure C — no cast needed):
start = malloc(sizeof(struct node));

Both are correct in C. The second is preferred by many C programmers because the cast can hide errors if you forget to #include <stdlib.h>.
*/






start->data = 54;
start->next = first;

first->data = 56;
first->next = second;

second->data = 78;
second->next = last;

last->data = 92;
last->next = NULL;


traverse(start);
printf("\n");

// start = insertinbetween(start,87,3);
// traverse(start);
// printf("\n");


// start = insertafternode(start,second,65);
// traverse(start);
// printf("\n");

// insertatfirst(start,100);  This does not work as we are not catching the input of function
// start = insertatfirst(start,100);
// traverse(start);
// printf("\n");


// start = insertatend(start,105);
// traverse(start);
// printf("\n");

// start = deleteatfirst(start);
// traverse(start);
// printf("\n");


// start = deleteatindex(start,2);
// traverse(start);
// printf("\n");

// start = deleteatlast(start);
// traverse(start);
// printf("\n");

// start = deleteatvalue(start,6);
// traverse(start);
// printf("\n");

return 0;
}