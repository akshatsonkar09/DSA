#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isFull (struct queue* q) 
{
    if (q->r == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





int isEmpty (struct queue* q) 
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}





void enqueue (struct queue* q, int val) 
{
    if (isFull(q))
    {
        printf("Queue is full");
    }
    else
    {
        q->r++;     //  q->r=q->r+1;
        printf("Added Number is %d\n",q->arr[q->r] = val);
    }
}





int dequeue (struct queue* q) 
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        q->f++;     //  q->r=q->r+1;
        printf("Removed Number is %d\n",q->arr[q->f]);
    }
}





/*IMPORTANT*/
void printQueue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("Number in Queue at index %d : %d\n",i, q->arr[i]);
        }
    }
}
/*IMPORTANT*/





int main() {
struct queue* q = (struct queue*)malloc(sizeof(struct queue));

q->size=30;
q->f = q->r = -1;
q->arr = (int*)malloc(q->size*sizeof(int));

enqueue(q,43);
enqueue(q,65);
printQueue(q);


dequeue(q);
dequeue(q);
printQueue(q);

return 0;
}