#include<stdio.h>
#include<stdlib.h>
int capacity=4;
int top=-1,*stack;
void Menu()
{
    printf("*****Menu*****\n 1.Push\n 2.print\n 3.Pop\n");
}
void resize()
{
    int *new_stack=(int *)malloc(2*capacity*sizeof(int));
    if(new_stack==NULL)
    {
        printf("Can't allocate memory.\n");
        return;
    }
    for(int i=0;i<=top;i++)
    {
        new_stack[i]=stack[i];
    }
    free(stack);
    stack=new_stack;
    capacity=2*capacity;
    printf("Capacity increased into: %d\n ",capacity);
}
void push(int item)
{
    if(top==capacity-1)
    {
        resize();
    }
    top=top+1;
    stack[top]=item;
    printf("Item pushed successfully.\n");
}
void pop()
{
    if(top>=0)
    {
        int value=stack[top];
        top=top-1;
    }
    else
    {
        printf("Stack is empty.No item to delete.\n");
    }
}
void print()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d \n",stack[i]);
    }
}
int main()
{
    stack=(int *)malloc(capacity*sizeof(int));
    int item,size,choice;
    if(stack==NULL)
    {
        printf("Can't allocate memory\n");
        return 1;
    }
   while(1)
   {
       Menu();
       printf("Please enter your choice.\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
         printf("Input the number of elements to store in the stack:\n");
    scanf("%d",&size);
    for(int i=1;i<=size;i++)
    {
        printf("Input item %d: ",i);
        scanf("%d",&item);
        push(item);
    }
    break;
       case 2:
        print();
        break;
       case 3:
        pop();
        break;
       default:
        printf("Invalid choice.Please try again.\n");
       }

   }
   free(stack);
    return 0;
}
