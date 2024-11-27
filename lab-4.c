#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
void menu()
{
    printf("1.Enqueue\n 2.Print Queue\n 3.Dequeue\n");
}
struct Queue *create_queue()
{
    struct Queue *queue=(struct Queue *)malloc(sizeof(struct Queue));
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
        queue->rear=new_node;
        queue->front=new_node;
    }
    else
    {
        queue->rear->next=new_node;
        queue->rear=new_node;
    }
    queue->total_item++;
}
bool isEmpty(struct Queue *queue)
{
    return queue->total_item == 0;
}
int dequeue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty.No item to delete.\n");
        return -1;
    }
    struct Node *temp=queue->front;
    int item=temp->data;
    queue->front=queue->front->next;

    if(queue->front==NULL)
    {
        queue->rear=NULL;
    }
    free(temp);
    queue->total_item--;
    return item;
}
void print_queue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Queue contents (Front to Rear): ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    int choice,item;
    struct Queue *queue = create_queue();
    while(1)
    {
        menu();
        printf("Enter your choice.\n");
        scanf("%d",& choice);

        switch(choice)
        {
        case 1:
            printf("Enter the item to insert:\n");
            scanf("%d",& item);
            enqueue(queue,item);
            break;
        case 2:
            print_queue(queue);
            break;
        case 3:
            item = dequeue(queue);
            if (item != -1)
            {
                printf("Dequeued item: %d\n", item);
            }
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
}
