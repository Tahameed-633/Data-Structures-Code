#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *add_at_begin()
{
    struct Node *head = NULL, *temp = NULL, *tail = NULL;
    int size, data;

    printf("Enter the size of the linked list:\n");
    scanf("%d", &size);
    printf("Enter the elements to store in the linked list:\n");

    for (int i = 1; i <= size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &data);
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    return head;
}
struct Node *add_at_middle(struct Node *head, int data, int position)
{
    struct Node *temp = head, *temp1 = NULL, *new_node = NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (position == 1)
    {
        new_node->next = head;
        if (head != NULL)
            head->prev = new_node;
        head = new_node;
        return head;
    }

    while(position!=1)
    {
        temp = temp->next;
        position--;
    }


    temp1 = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = temp1;



    return head;
}
struct Node *add_at_end(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->prev = current;
    return head;
}
struct Node *delete_end(struct Node *head)
{
    struct Node *current=head,*temp=NULL;
    while(current->next!=NULL)
    {
        temp=current;
        current=current->next;
    }
    temp->next=NULL;
    free(current);
    return head;
}
struct Node *delete_middle(struct Node *head,int position)
{
struct Node *temp=head,*temp1=NULL,*temp2=NULL;
while(position!=1)
    {
        position--;

        temp=temp->next;
    }
    temp->prev->next=temp->next;
   temp->next->prev=temp->prev;
   free(temp);
    return head;
}
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    head = add_at_begin();

    printf("Original list:\n");
    display(head);

    head = add_at_middle(head, 30, 2);

    printf("List after inserting 30 at position 2:\n");
    display(head);
    head=add_at_end(head,35);
    display(head);
    head=delete_end(head);
    display(head);
    head=delete_middle(head,3);
    display(head);

    return 0;
}
