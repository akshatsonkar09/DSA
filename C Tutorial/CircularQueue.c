#include <stdio.h>
#include <stdlib.h>


/*WEAK*/


struct CircularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};






int isFull (struct CircularQueue* q) 
{
    if ((q->r+1)%q->size == q->f)       //(Changed)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}






int isEmpty (struct CircularQueue* q) 
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





void enCircularQueue (struct CircularQueue* q, int val) 
{
    if (isFull(q))
    {
        printf("CircularQueue is full\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;        //(Changed)
        printf("Added Number is %d\n",q->arr[q->r] = val);
    }
}






int deCircularQueue (struct CircularQueue* q) 
{
    if (isEmpty(q))
    {
        printf("CircularQueue is Empty\n");
        return -1;
    }
    else
    {
        q->f = (q->f+1)%q->size;        //(Changed)
        printf("Removed Number is %d\n",q->arr[q->f]);
    }
}






/*IMPORTANT*/
void printCircularQueue(struct CircularQueue* q) {
    if (isEmpty(q)) 
    {
        printf("CircularQueue is Empty\n");
        return;
    } 
    else {
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("Number in CircularQueue at index %d : %d\n",i, q->arr[i]);
        }
    }
}
/*IMPORTANT*/






int main() {
struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));


q->size=4;
q->f = q->r = 0;
q->arr = (int*)malloc(q->size*sizeof(int));


enCircularQueue(q,43);
enCircularQueue(q,65);
printCircularQueue(q);


deCircularQueue(q);
deCircularQueue(q);

enCircularQueue(q,72);
printCircularQueue(q);


return 0;
}