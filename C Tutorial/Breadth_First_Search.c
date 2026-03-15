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
        q->arr[q->r] = val;
    }
}





int dequeue (struct queue* q) 
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        q->f++;     //  q->r=q->r+1;
        a = q->arr[q->f];
    }
    return a;

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
struct queue* q;

q->size=400;
q->f = q->r = 0;
q->arr = (int*)malloc(q->size*sizeof(int));


/*BREADTH FIRST SEARCH*/
int u;
int i =0;

int visited[7] = {0,0,0,0,0,0,0,};

int a[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

printf("%d", i);
visited[i] = 1;
enqueue(q,i);      //For exploration

while (!isEmpty(q))
{
    int node = dequeue(q);
    for (int j = 0; j < 7; j++)
    {
        if (a[node][j] == 1 && visited[j] == 0)
        {
            printf("%d", j);
            visited[j] = 1;
            enqueue(q,j);
        }
        
    }
    
}

return 0;
}