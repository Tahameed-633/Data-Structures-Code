#include<stdio.h>
#include<stdlib.h>

int capacity = 2;
int top = -1;
int *stack;

void resize()
{
    int *new_stack = (int *)malloc(capacity * 2 * sizeof(int));
    if (new_stack == NULL)
    {
        printf("Memory allocation failed! Can't resize.\n");
        return;
    }

    for (int i = 0; i <= top; i++)
    {
        new_stack[i] = stack[i];
    }

    free(stack);
    stack = new_stack;
    capacity = 2 * capacity;
    printf("Size of the stack increased to: %d\n", capacity);
}

void push(int x)
{
    if (top == capacity - 1)
    {
        resize();
    }
    top = top + 1;
    stack[top] = x;
    printf("Item pushed successfully: %d\n", x);
}

int pop()
{
    if (top >= 0)
    {
        int value = stack[top];
        top = top - 1;
        return value;
    }
    printf("Exception in pop! Empty Stack.\n");
    return -1;
}

int peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    printf("Exception in peek! Empty stack.\n");
    return -1;
}

int main()
{
    printf("Implementing stack in C\n");


    stack = (int *)malloc(capacity * sizeof(int));
    if (stack == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    peek();
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    printf("Item peeked successfully: %d\n", peek());
    push(70);
    printf("Item popped successfully: %d\n", pop());


    free(stack);

    return 0;
}
