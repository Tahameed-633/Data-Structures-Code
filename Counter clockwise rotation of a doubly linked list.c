#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *create_doubly_linked_list()
{
    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int size,item;
    printf("Enter the size of the doubly linked list:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n");
    for(int i=1; i<=size; i++)
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
struct Node *rotated_linked_list(struct Node *head)
{
    struct Node *current=head,*temp=NULL;
    int k;
    printf("Enter the number of rotation:\n");
    scanf("%d",& k);
    for(int i=1;i<=k;i++)
    {
        while(current->next!=NULL)
        {
            temp=current;
            current=current->next;
        }
        temp->next=NULL;
        temp->prev=current;
        current->next=head;
        head->prev=current;
        head=current;
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
    head=rotated_linked_list(head);
    printf("Counter clockwise rotated doubly linked list:\n");
    display(head);
}
