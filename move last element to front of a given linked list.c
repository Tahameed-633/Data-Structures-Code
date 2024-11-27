#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list()
{
    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int data,size;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n");
    for(int i=1;i<=size;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&data);
        temp->data=data;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }
    }
    return head;
}

struct Node *change_position(struct Node *head)
{
    struct Node *current=head,*temp=NULL,*last_node=NULL;
    while(current->next!=NULL)
    {
       last_node=current;
       current=current->next;
    }
    last_node->next=NULL;
    current->next=head;
    head=current;
    return head;
}
void display(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    struct Node *head=create_linked_list();
    struct Node *new_head=change_position(head);
    display(new_head);
    return 0;
}
