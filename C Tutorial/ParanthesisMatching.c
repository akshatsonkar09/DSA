#include <stdio.h>
#include <stdlib.h>






struct stack
{
    int top;
    int size;
    char* arr;
};






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






void push (struct stack*s, char value)
{
    if (stackisfull(s) == 1)
    {
        printf("Stack Overflow because of value %c\n",value);
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("New Char %c is added\n",value);
    }
}






char pop (struct stack*s)
{
    if (stackisempty(s)== 1)
    {
        return -1;   
    }
    else
    {
        char value = s->arr[s->top];
        printf("New Char %c is removed\n",s->arr[s->top]);
        s->top--;
        return value;
    }
}




int match (char a,char b)
{
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}




int paranthesismatching (char*arr)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1; 
    s->arr=(char*)malloc(s->size*sizeof(char));
    char popped;

    for (int i = 0; arr[i] != '\0'; i++)
    {
      if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
      {
        push(s,arr[i]);
      }
      else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
      {
        if (stackisempty(s))
        {
            return 0;
        }
        popped = pop(s);
        if (!match(popped,arr[i]))
        {
            printf("Mismatched: %c and %c\n", popped, arr[i]);
            return 0;
        }
    }
    }
    if (stackisempty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}


int main() {

    char* arr = "[8(*9]";
    if (paranthesismatching(arr))
    {
        printf("Balanced");
    }
    else
    {
        printf("Not Balanced");
    }
    
    

    return 0;

}