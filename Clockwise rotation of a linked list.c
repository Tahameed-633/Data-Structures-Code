#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *create_doubly_linked_list()
{
    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int size, item;
    printf("Enter the size of the doubly linked list:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the doubly linked list:\n");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",& item);
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->prev=NULL;
        temp->data=item;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            current=temp;

        }
        else
        {
            current->next=temp;
            temp->prev=current;
            current=temp;
        }
    }
    return head;
}
struct Node *rotated_doubly_linked_list(struct Node *head)
{
    int k;
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    struct Node *current=head,*temp=NULL;

    printf("Enter the number of rotation:\n");
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        while(current->next!=NULL)
        {

            current=current->next;
        }
       current->next=head;
       head->prev=current;
       head=head->next;
       current->next->next=NULL;

    }
    return head;
}
void display(struct Node *head)
{
    struct Node *current=head;
    while(current!=NULL)
    {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head=NULL;
    head=create_doubly_linked_list();
    display(head);
    head=rotated_doubly_linked_list(head);
    printf("Clockwise rotated linked list:\n");
    display(head);
    return 0;
}
