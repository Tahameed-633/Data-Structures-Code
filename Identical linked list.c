#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node* create_linked_list()
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int size, val;

    printf("Enter the size of the linked list:\n");
    scanf("%d", &size);
    printf("Enter the elements to store in the linked list:\n");
    for (int i = 0; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &val);
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}
void display_linked_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
bool are_identical(struct Node *head1, struct Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}
int main()
{
    struct Node *head1, *head2;

    printf("Creating the first linked list:\n");
    head1 = create_linked_list();

    printf("Creating the second linked list:\n");
    head2 = create_linked_list();

    printf("First linked list:\n");
    display_linked_list(head1);

    printf("Second linked list:\n");
    display_linked_list(head2);

    if (are_identical(head1, head2))
    {
        printf("Identical\n");
    }
    else
    {
        printf("Not identical\n");
    }
    return 0;
}
