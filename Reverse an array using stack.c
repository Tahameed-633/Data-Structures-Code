#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int capacity=4,*stack,top=-1;
void resize()
{
    int *new_stack=(int *)malloc(2*capacity*sizeof(int));
    if(new_stack==NULL)
    {
        printf("Can't allocate memory.\n");
    }
    for(int i=0; i<=top; i++)
    {
        new_stack[i]=stack[i];
    }
    free(stack);
    stack=new_stack;
    capacity=2*capacity;
    printf("Capacity increased into: %d\n",capacity);
}
void push(int item)
{
    if(top==capacity-1)
    {
        resize();
    }
    top=top+1;
    stack[top]=item;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is empty.No item to delete.\n");
        return 1;
    }
    int value=stack[top];
    top=top-1;
    return value;
}
int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int ar[n];
    printf("Input the array\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }

    stack=(int *)malloc(capacity*sizeof(int));
    if(stack==NULL)
    {
        printf("Can't allocate memory.\n");
        return -1;
    }
    for(int i=0; i<n; i++)
    {
        push(ar[i]);
    }
    printf("Reversed array\n");
    while(top!=-1)
    {
        printf("%d ",pop());

    }
    printf("\n");
}
