#include<stdio.h>
#include<stdlib.h>
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
void delete_middle_element(int *stack)
{
    int length=top+1;
    int middle=length/2;
    int *temp_stack=(int *)malloc(length*sizeof(int));
    int temp_top=-1;
    for(int i=0; i<=top; i++)
    {
        int value=pop();
        if(value!=stack[middle])
        {
            temp_stack[++temp_top]=value;
        }

    }
    for(int i=temp_top; i>=0; i--)
    {
        push(temp_stack[i]);
    }

}
void display(int *stack)
{
    for(int i=0; i<=top; i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    int size,item;
    stack=(int *)malloc(capacity*sizeof(int));
    if(stack==NULL)
    {
        printf("Can't allocate memory\n");
        return -1;
    }
    printf("Enter the size of the stack:\n");
    scanf("%d",&size);
    printf("Enter the element to store is the stack\n");
    for(int i=1; i<=size; i++)
    {
        scanf("%d",&item);
        push(item);
    }
    printf("Original stack\n");
    display(stack);
    printf("Stack after deleting middle element\n");
    delete_middle_element(stack);
    display(stack);
    return 0;
}
