#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int capacity = 4, top = -1;
char *stack;
void resize()
{
    char *new_stack = (char *)malloc(2*capacity*sizeof(char));
    if (new_stack == NULL)
    {
        printf("Can't allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i <= top; i++)
    {
        new_stack[i] = stack[i];
    }
    free(stack);
    stack = new_stack;
    capacity = 2 * capacity;
    printf("Capacity increased to: %d\n", capacity);
}
bool isEmpty()
{
    return top==-1;
}
void push(char item)
{
    if (top==capacity - 1)
    {
        resize();
    }
    stack[++top] = item;
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
void display()
{
    for (int i=0; i<=top; i++)
    {
        printf("%c ",stack[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the size of the string: ");
    scanf("%d", &n);
    getchar();
    char str[n + 1];
    printf("Enter the string: ");
    fgets(str, n + 1, stdin);
    stack = (char *)malloc(capacity * sizeof(char));
    if (stack == NULL)
    {
        printf("Can't allocate memory.\n");
        return -1;
    }

    for (int i=0; i< strlen(str); i++)
    {
        push(str[i]);
    }
    printf("Reversed string: ");
    while (!isEmpty())
    {
        printf("%c", pop());
    }
    printf("\n");

    free(stack);
    return 0;
}
