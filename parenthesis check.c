#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;


void push(char item);
char pop();
bool isEmpty();
void check_parentheses(char *expression);

int main()
{
    char expression[MAX];
    printf("Enter an expression: \n");
    gets(expression);
    check_parentheses(expression);
    return 0;
}

void push(char item)
{
    if (top == MAX - 1)
    {
        printf("Stack is full, can't insert anything.\n");
    }
    else
    {
        stack[++top] = item;
    }
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack is empty. No item to delete.\n");
        return '\0';
    }
    return stack[top--];
}

bool isEmpty()
{
    return top == -1;
}
void check_parentheses(char *expression)
{
    int i;
    bool error = false;

    for (i = 0; i < strlen(expression); i++)
    {
        char symbol = expression[i];

        if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            if (isEmpty())
            {
                printf("Error: Closing parenthesis unmatched at position %d\n", i + 1);
                error = true;
                break;
            }
            pop();
        }
    }

    if (!isEmpty())
    {
        printf("Error: Opening parenthesis unmatched\n");
        error = true;
    }

    if (!error)
    {
        printf("Parentheses are well paired\n");
    }
}

