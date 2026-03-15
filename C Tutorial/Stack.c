#include <stdio.h>
#include <stdlib.h>



struct stack
{
    int size;
    int top;
    int* arr;
};






int stackisempty (struct stack*s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}






int stackisfull (struct stack*s)
{
    if (s->top == s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}






void push (struct stack* s,int value)
{
    if (stackisfull(s))
    {
        printf("Stack Overflow because of value %d\n",value);
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("New Value %d is added to index %d\n",value,s->top);
    }    
}






int pop (struct stack*s)
{
    if (stackisempty(s))
    {
        printf("Stack Underflow\n");
        return -1;   
    }
    else
    {
        int value = s->arr[s->top];
        printf("Value %d is removed\n",s->arr[s->top]);
        s->top--;
        return value;
    }
}





/*This is for position from above*/
// int peek(struct stack*s, int index)
// {
//     if (index < 0)
//     {
//         printf("Index does not exist");
//     }
//     else
//     {
//         return s->arr[s->top-index+1];
//     }  
// }

/*This is for index from 0*/
int peek(struct stack*s, int index)
{
    if (index < 0 || index > s->top)
    {
       printf("Index does not exist");
    }
    else
    {
        return s->arr[index];
    } 
}






int stacktop(struct stack*s)
{
    return s->arr[s->top];
}






int stackbottom(struct stack*s)
{
    return s->arr[0];
}







int main() {

struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->size = 8;
s->top = -1;
s->arr = (int*)malloc(s->size*sizeof(int));

printf("Stack is created\n");

printf("StackFull is %d\n",stackisfull(s));
printf("StackEmpty is %d\n",stackisempty(s));



push(s,5);
push(s,8);
push(s,11);
push(s,16);
push(s,20);
push(s,26);
push(s,32);
push(s,39);


printf("Value at top is %d\n",stacktop(s));
printf("Value at bottom is %d\n",stackbottom(s));


push(s,45);


printf("Stack Array is:\n");
for (int i = 0; i < s->top+1; i++)
{
    printf("Index %d : %d\n",i,s->arr[i]);
}
printf("Value of index 5 from top is %d\n",peek(s,5));




printf("StackFull is %d\n",stackisfull(s));
printf("StackEmpty is %d\n",stackisempty(s));





pop(s);
pop(s);
pop(s);
pop(s);
pop(s);
pop(s);
pop(s);
pop(s);
pop(s);


printf("StackFull is %d\n",stackisfull(s));
printf("StackEmpty is %d\n",stackisempty(s));




return 0;
}