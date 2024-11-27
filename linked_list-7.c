#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list(int ar[],int size)
{
   struct Node *temp=NULL,*head=NULL,*current=NULL;
   for(int i=0;i<size;i++)
   {
       temp=(struct Node *)malloc(sizeof(struct Node));
       temp->data=ar[i];
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
struct Node *insert_node(struct Node *head,int position,int value)
{
    struct Node *current=head;
    int count=0;
    while(current!=NULL)
    {
        count++;
        if(count==position)
        {
           struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
           temp->data=value;
           temp->next=current->next;
            current->next=temp;
        }
        current=current->next;
    }
    return head;

}
void print_linked_list(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    int ar[5]={5,10,15,20,25};
    struct Node *head=create_linked_list(ar,5);
    print_linked_list(head);
    struct Node *new_head=head=insert_node(head,2,30);
    print_linked_list(new_head);
}
