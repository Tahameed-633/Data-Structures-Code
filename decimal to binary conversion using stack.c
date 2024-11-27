#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *stack,top=-1,capacity=4;
void resize()
{
    int *new_stack=(int *)malloc(2*capacity*sizeof(int));
    for(int i=0; i<=top; i++)
    {
        new_stack[i]=stack[i];
    }
    free(stack);
    stack=new_stack;
    capacity=2*capacity;
    printf("Capacity increased into: %d\n",capacity);
}
bool isEmpty(int *stack)
{
    return top==-1;
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
    int value=stack[top];
    top=top-1;
    return value;
}
void dec_to_bin(int dec)
{
    int bin;
    while(dec!=0)
    {
         bin=dec%2;
         push(bin);
         dec/=2;
    }
    printf("Decimal to binary: ");
    while(!isEmpty(stack))
    {
        printf("%d",pop());
    }
}
int main()
{
    int dec;
    stack=(int *)malloc(capacity*sizeof(int));
    if(stack==NULL)
    {
        printf("Can't allocate memory\n");
        return 1;
    }
    printf("Enter the decimal number to convert into binary\n");
    scanf("%d",&dec);
    dec_to_bin(dec);
    return 0;

}
