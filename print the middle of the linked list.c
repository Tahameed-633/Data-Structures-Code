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
    int size,data;
    printf("Enter the size of the linked list: \n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n");
    for(int i=1; i<=size; i++)
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
            current=temp;
        }
    }
    return head;
}
int get_length(struct Node *head)
{

    int length=0;
    while(head!=NULL)
    {
        length++;
        head=head->next;
    }
    return length;
}
int get_middle(struct Node *head)
{

    int length=get_length(head);
    int mid_index=length/2;
    while(mid_index--)
    {
        head=head->next;
    }
    return head->data;
}
int main()
{
    struct Node *head=create_linked_list();
    int mid_element=get_middle(head);
    printf("Middle element:%d \n",mid_element);
}
