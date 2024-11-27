#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100
char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top=-1;
void push(char item);
char pop();
bool isEmpty();
int precedence(char symbol);
void infix_to_postfix();
int main()
{
    printf("Enter the infix notation: \n");
    gets(infix);
    infix_to_postfix();
    printf("Postfix expression:\n%s\n",postfix);
}
void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack is full can't insert anything.\n");
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
char pop()
{
    if(isEmpty())
    {
        printf("Stack is empty.No item to delete.\n");
        return '\0';
    }
    char c=stack[top];
    top=top-1;
    return c;

}
bool isEmpty()
{
    return top == -1;
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default :
        return 0;
    }
}
void infix_to_postfix()
{
    char symbol, next;
    int i, j = 0;

    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':

            while (!isEmpty() && (next = pop()) != '(')
            {
                postfix[j++] = next;
            }
            break;

        case '^':
        case '*':
        case '/':
        case '+':
        case '-':

            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;

        default:

            postfix[j++] = symbol;
        }
    }


    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

