#include<stdio.h>
#include<stdlib.h>
int *stack,capacity=4,top=-1;
struct Node
{
    int data;
    struct Node *next;
};
struct Queue
{
    struct Node *front;
    struct Node *rear;
    int total_item;
};
struct Queue *create_queue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front=NULL;
    queue->rear=NULL;
    queue->total_item=0;
    return queue;
}
void enqueue(struct Queue *queue,int item)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=item;
    new_node->next=NULL;
    if(queue->rear==NULL)
    {
        queue->front=new_node;
        queue->rear=new_node;
    }
    else
    {
        queue->rear->next=new_node;
        queue->rear=new_node;
    }
    queue->total_item++;
}
void resize()
{
    int *new_stack=(int *)malloc(capacity*sizeof(int));
    if(stack==NULL)
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
    printf("Capacity increased into: %d",capacity);
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
void print_stack(int *stack)
{
    for(int i=0; i<=top; i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void display(struct Queue *queue)
{
    struct Node *current=queue->front;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
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
    printf("Enter the size of the stack\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the stack\n");
    for(int i=1; i<=size; i++)
    {
        scanf("%d",&item);
        push(item);
    }
    printf("Original stack\n");
    print_stack(stack);
    struct Queue *queue=create_queue();
    for(int i=1; i<=size; i++)
    {
        int data=pop();
        enqueue(queue,data);
    }
    printf("Reversed stack\n");
    display(queue);
    return 0;
}
