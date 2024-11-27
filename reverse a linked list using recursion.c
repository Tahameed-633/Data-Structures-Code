#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list(int size)
{
    if (size <= 0)
    {
        printf("Invalid size! The linked list cannot be created.\n");
        return NULL;
    }

    struct Node *head = NULL, *temp = NULL, *current = NULL;

    for (int i = 0; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp->data);
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

struct Node *reverse_linked_list(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *rest = reverse_linked_list(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void print_linked_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int size;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    struct Node *head = create_linked_list(size);

    if (head == NULL)
    {
        return 0;
    }

    printf("Original List:\n");
    print_linked_list(head);
    head = reverse_linked_list(head);
    printf("Reversed List:\n");
    print_linked_list(head);
    return 0;
}

