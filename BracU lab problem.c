#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int elem;
    struct Node* next;
};

struct Node* create_linked_list(int size)
{
    if (size <= 0) return NULL;

    struct Node* head = NULL;
    struct Node* current = NULL;

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < size; i++)
    {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->elem = value;
        newNode->next = NULL;

        if (!head)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }
        current = newNode;
    }

    return head;
}

struct Node* reverse_sublist(struct Node* head, int i, struct Node** new_head)
{
    struct Node* prev_node = NULL;
    struct Node* current_node = head;
    struct Node* next_node = NULL;
    int count = 0;

    while (current_node && count <= i)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        count++;
        current_node = next_node;
    }

    *new_head = current_node;
    return prev_node;
}

struct Node* reverse_and_rearrange(struct Node* head, int i)
{
    if (!head || i < 0) return head;

    struct Node* unchanged_head = NULL;
    struct Node* reversed_head = reverse_sublist(head, i, &unchanged_head);

    struct Node* temp = unchanged_head;
    if (temp)
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = reversed_head;
    }
    else
    {
        unchanged_head = reversed_head;
    }

    return unchanged_head;
}

void print_linked_list(struct Node* head)
{
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }

    while (head)
    {
        printf("%d-> ", head->elem);
        head = head->next;
    }
    printf("NULL\n");
}

void free_linked_list(struct Node* head)
{
    while (head)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int size;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size. The linked list must contain at least one element.\n");
        return 0;
    }

    struct Node* head = create_linked_list(size);

    printf("Original Linked List: ");
    print_linked_list(head);

    int i;
    printf("Enter the index i (0-based) where 0 <= i < %d: ", size);
    scanf("%d", &i);

    if (i < 0 || i >= size)
    {
        printf("Invalid index. The index must be between 0 and %d.\n", size - 1);
        free_linked_list(head);
        return 0;
    }

    struct Node* new_head = reverse_and_rearrange(head, i);

    printf("Modified Linked List: ");
    print_linked_list(new_head);

    free_linked_list(new_head);

    return 0;
}
