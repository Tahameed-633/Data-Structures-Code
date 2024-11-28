#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    queue->front = NULL;
    queue->rear = NULL;
    queue->total_item = 0;
    return queue;
}
bool isEmpty(struct Queue *queue)
{
    return queue->total_item == 0;
}
void enqueue(struct Queue *queue, int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->total_item++;
}
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is already empty. No item to delete.\n");
        return -1;
    }
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    int item = temp->data;
    free(temp);
    queue->total_item--;
    return item;
}
void display(struct Queue *queue)
{
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    struct Queue *queue = NULL;
    int size, item, data;
    queue = create_queue();
    printf("Enter the size of the queue:\n");
    scanf("%d", &size);
    printf("Enter the elements to store in the queue:\n");
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &item);
        enqueue(queue, item);
    }
    printf("Original queue:\n");
    display(queue);
    int initial_size = queue->total_item;
    for (int i = 1; i <= initial_size; i++)
    {
        data = dequeue(queue);
        if (data >= 0)
        {
            enqueue(queue, data);
        }
    }
    printf("Modified queue:\n");
    display(queue);

    return 0;
}
