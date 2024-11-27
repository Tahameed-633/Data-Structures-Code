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
void print_linked_list(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
struct Node *delete_node(struct Node *head,int data)
{
   struct Node *dummy_head=(struct Node *)malloc(sizeof(struct Node));
   struct Node *current=NULL;
   dummy_head->next=head;
   current=dummy_head;
   while(current!=NULL)
   {
       if(current->next->data==data)
       {
           current->next=current->next->next;
           break;
       }
       else
       {
           current=current->next;
       }
   }
   return dummy_head->next;
}
int main()
{
    int ar[5]={5,10,15,20,25};
    struct Node *head=create_linked_list(ar,5);
    print_linked_list(head);
    struct Node *new_head=delete_node(head,20);
    print_linked_list(new_head);

}
