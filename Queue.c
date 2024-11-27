#include<stdio.h>
#include<stdbool.h>
#define capacity 5
int queue[capacity];
int rear=-1,front=0, total_item=0;
bool isFull()
{
    if(total_item==capacity)
    {
        return true;
    }
    return false;
}
bool isEmpty()
{
    if(total_item==0)
    {
        return true;
    }
    return false;
}
void enqueue(int item)
{
    if(isFull())
    {
        printf("Sorry,Queue is full\n");
        return;
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
    print_queue();
}
