#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list()
{
    int size, data;
    struct Node *head=NULL,*temp=NULL,*current=NULL;

    printf("Enter the size of the linked list: \n");
    scanf("%d",&size);
    printf("Input the elements to create the linked list; ");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&data);
        temp=(struct Node *)malloc(sizeof(struct Node));
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
            current=temp;
        }
    }
    return head;
}
struct Node *rotate_linked_list(struct Node *head,int k)
{
    if(head==NULL||head->next==NULL||k==0)
    {
        return NULL;
    }
    struct Node *current=head;
    for(int i=0;i<k;i++)
    {
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=head;
        head=head->next;
        current->next->next=NULL;
    }
    return head;
}
void print(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL");
    printf("\n");
}
int main()
{
    struct Node *head=create_linked_list();
    int k;
    print(head);
    printf("Enter the value of k:\n");
    scanf("%d",&k);
    head=rotate_linked_list(head,k);
    printf("Rotated linked list:\n");
    print(head);
}
