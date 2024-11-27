#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;
void push(char item);
char pop();
bool isEmpty();
int precedence(char symbol);
void infix_to_postfix();
void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack is full.\n");
        return;
    }
    stack[++top] = item;
}
char pop()
{
    if (isEmpty())
    {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return stack[top--];
}
bool isEmpty()
{
    return (top == -1);
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
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
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
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


int main()
{
    printf("Enter the infix expression:\n");
    gets(infix);

    infix_to_postfix();

    printf("The postfix expression is:\n%s\n", postfix);

    return 0;
}
