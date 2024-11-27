#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list()
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int size, data;
    printf("Enter the size of the linked list:\n");
    scanf("%d", &size);
    printf("Enter the elements to store in the linked list:\n");
    for (int i = 1; i <= size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node *remove_duplicates(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL && current->next != NULL)
    {
        struct Node *temp = current;

        while (temp->next != NULL)
        {
            if (temp->next->data == current->data)
            {
                struct Node *duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
    return head;
}

int main()
{
    struct Node *head = create_linked_list();

    printf("Original linked list:\n");
    display(head);

    head = remove_duplicates(head);

    printf("Linked list after removing duplicates:\n");
    display(head);

    return 0;
}

