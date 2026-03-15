#include <stdio.h>
#include <stdlib.h>
#include <string.h>





struct stack
{
    int top;
    int size;
    char* arr;
};






int stacktop(struct stack*s)
{
    return s->arr[s->top];
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


int isOperator(char ch) 
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
        
    }
    
    
}

int precedence(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 3;
    }

    else if (ch == '+' || ch == '-')
    {
        return 2;
    }

    else
    {
        return 0;
    }
    
    
}





char* infixtopostfix (char* infix)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(char));
    char* postfix = (char*)malloc(strlen((infix) + 1)*sizeof(char));      //Forgot 
    int i=0;
    int j=0;

    while (infix[i]!='\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else        //Else statement not clear
        {
            /*Wrong*/
            // if (precedence(infix[i])>precedence(infix[i-1]))
            // {
            //    postfix[j] = push(s,infix[i]);
            //    i++;
            // }

            if ((precedence(infix[i]) > precedence(stacktop(s))))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                j++;
            } 
        }
    }
    {
        while (!stackisempty(s))
        {
            postfix[j] = pop(s);
            j++;
        }
        postfix[j]= '\0';
        return postfix;   
    }  
}


int main() {

    char* infix = "a+b*t";
    printf("%s",infixtopostfix(infix));
  
    

    return 0;

}