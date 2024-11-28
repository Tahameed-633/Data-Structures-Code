#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    char data;
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

void enqueue(struct Queue *queue, char item)
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

char dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. No item to delete.\n");
        return '\0';
    }
    struct Node *temp = queue->front;
    char c = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    queue->total_item--;
    return c;
}

void display(struct Queue *queue)
{
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the string: ");
    scanf("%d", &size);
    getchar();

    char str[size + 1];
    printf("Enter the string: ");
    gets(str);
    //getchar();

    struct Queue *queue = create_queue();
    for (int i = 0; i < size; i++)
    {
        enqueue(queue, str[i]);
    }
printf("Original string:\n");
display(queue);


    for (int i = 0; i < size; i++)
    {
        char c = dequeue(queue);
        if (c != ' ')
        {
            enqueue(queue, c);
        }
    }
    printf("Compressed string:\n ");
    display(queue);

    return 0;
}
