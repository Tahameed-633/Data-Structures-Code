#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int capacity=5;
int *queue;

int rear=-1,front=0, total_item=0;

bool isEmpty()
{
    if(total_item==0)
    {
        return true;
    }
    return false;
}
void resize()
{
    int *new_queue=(int *)malloc(2*capacity*sizeof(int));
    if(new_queue==NULL)
    {
        printf("Memory allocation unsuccessful. Can't re-allocate memory.\n");
        return;
    }
    for(int i=0;i<capacity;i++)
    {
        new_queue[i]=queue[i];
    }
    free(queue);
    queue=new_queue;
    capacity=2*capacity;
    printf("Capacity of the queue increased into: %d\n",capacity);
}
void enqueue(int item)
{
    if(total_item==capacity)
    {
        resize();
    }
    rear=(rear+1)%capacity;
    queue[rear]=item;
    total_item++;

}
void print_queue()
{
    printf("Queue:\n");
    for(int i=0;i<capacity;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int dequeue()
{
    if(isEmpty())
    {
        printf("Sorry queue is empty\n");
        return -1;
    }
    int front_item=queue[front];
    queue[front]=-1;
    front=(front+1)%capacity;
    total_item--;
    return front_item;
}
int main()
{
    printf("Implementing queue in C\n");
    queue=(int *)malloc(capacity*sizeof(int));
    if(queue==NULL)
    {
         printf("Memory allocation unsuccessful\n");
         return -1;
    }
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print_queue();
    enqueue(60);
    printf("Dequeued item: %d\n",dequeue());
    print_queue();
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    enqueue(110);

    print_queue();
    free(queue);
}

