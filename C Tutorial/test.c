#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear == MAX-1){
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Underflow\n");
        return;
    }
    front++;
}

void display(){
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}

void deleteNth(int n){
    if(front == -1 || n > (rear-front+1)){
        printf("Error: Invalid position\n");
        return;
    }

    for(int i=1;i<n;i++){
        enqueue(queue[front]);
        dequeue();
    }

    dequeue(); // delete nth
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("Queue elements are: ");
    display();

    printf("Delete 7th element:\n");
    deleteNth(7);

    printf("Delete 3rd element:\n");
    deleteNth(3);

    printf("Queue elements are: ");
    display();

    return 0;
}
