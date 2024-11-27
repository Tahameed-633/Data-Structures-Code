#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *create_linked_list(int ar[], int size)
{
    struct Node *temp = NULL, *head = NULL, *current = NULL;
    for(int i = 0; i < size; i++)
    {

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = ar[i];
        temp->next = NULL;

        if(head == NULL)
        {

            head = temp;
            current = temp;
        }
        else
        {

            current->next = temp;
            current =current->next;
        }
    }
    return head;
}


void reversed_linked_list(struct Node *head)
{
    struct Node *next = NULL, *previous = NULL, *current = head;


    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;


    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int ar[5] = {5, 10, 15, 20, 25};
    struct Node *head;


    head = create_linked_list(ar, 5);


    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    reversed_linked_list(head);

    return 0;
}
