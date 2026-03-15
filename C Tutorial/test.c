#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void insert(int x){

    struct Node* n=malloc(sizeof(struct Node));
    n->data=x;
    n->next=NULL;

    if(rear==NULL){
        front=rear=n;
        return;
    }

    rear->next=n;
    rear=n;
}

void delete(){

    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }

    struct Node* t=front;
    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(t);
}

void display(){

    struct Node* t=front;

    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }

    printf("\n");
}

int main(){

    insert(10);
    insert(20);
    insert(30);

    printf("Queue:\n");
    display();

    delete();

    printf("After deletion:\n");
    display();

    return 0;
}