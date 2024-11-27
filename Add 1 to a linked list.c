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
    printf("Enter the size of the linked list: ");
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
void display(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
struct Node *changed_linked_list(struct Node *head)
{
    struct Node *current=head,*current1=head,*temp1=NULL,*temp=NULL;
    while(current!=NULL)
    {
        temp=current;
        current=current->next;
    }
    if(temp->data%2==0||temp->data%2!=0 &&temp->data!=9)
        temp->data=temp->data+1;
    else
        {
            while(current1->next!=NULL)
            {
              temp1=current1;
              current1=current1->next;
            }
            temp1->data=temp1->data+1;
            temp1->next->data=0;
        }
    return head;
}
int main()
{
    struct Node *head=create_linked_list();
    printf("Original linked list:\n");
    display(head);
    head=changed_linked_list(head);
    printf("Changed linked list\n");
    display(head);
}
