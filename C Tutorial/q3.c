#include <stdio.h>

#define SIZE 10

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

/* Push in Stack1 */
void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow\n");
        return;
    }
    arr[++top1] = x;
}

/* Push in Stack2 */
void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow\n");
        return;
    }
    arr[--top2] = x;
}

/* Pop from Stack1 */
int pop1() {
    if (top1 == -1) {
        printf("Underflow\n");
        return -1;
    }
    return arr[top1--];
}

/* Pop from Stack2 */
int pop2() {
    if (top2 == SIZE) {
        printf("Underflow\n");
        return -1;
    }
    return arr[top2++];
}

/* Display */
void display() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);

    printf("\nStack2: ");
    for (int i = SIZE - 1; i >= top2; i--)
        printf("%d ", arr[i]);

    printf("\n");
}





struct node {
    int info;
    int priority;
    struct node* link;
};

struct node* front = NULL;

// -------- Check Empty --------
int isEmpty() {
    return front == NULL;
}

// -------- Priority Enqueue --------
void priority_enqueue(int item, int item_priority) {
    struct node *tmp, *p;

    tmp = (struct node*)malloc(sizeof(struct node));

    if (tmp == NULL) {
        printf("Memory not available\n");
        return;
    }

    tmp->info = item;
    tmp->priority = item_priority;
    tmp->link = NULL;

    // Case 1: Empty or higher priority than front
    if (isEmpty() || item_priority > front->priority) {
        tmp->link = front;
        front = tmp;
    }
    else {
        p = front;

        while (p->link != NULL && p->link->priority >= item_priority)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }
}


void enqueue(int x) {
    push1(x);
}

// -------- Dequeue (Costly only when needed) --------
int dequeue() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue Underflow\n");
        return -1;
    }

    if (isEmpty2()) {
        while (!isEmpty1())
            push2(pop1());
    }

    return pop2();
}

int main() {
    push1(10);
    push1(20);

    push2(100);
    push2(200);

    display();

    printf("Pop1: %d\n", pop1());
    printf("Pop2: %d\n", pop2());

    display();

    return 0;
}