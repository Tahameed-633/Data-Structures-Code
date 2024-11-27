#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
//function to create a linked list
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
//function to print the created linked list
void print_linked_list(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
//function to add a node at the first of the previously created linked list
struct Node *prepend_node(struct Node *head,int value)
{
  struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
  temp->data=value;
  temp->next=head;
  return temp;
}
//function to add a node at the end of the created linked list
struct Node *postpend_node(struct Node *head,int value)
{

    struct Node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    current->next=temp;
    return head;
}
//reverse the created linked list
struct Node *reverse_linked_list(struct Node *head)
{
   struct Node *previous=NULL,*current=head,*next=NULL;
   while(current!=NULL)
   {
       next=current->next;
   current->next=previous;
   previous=current;
   current=next;
   }
   return previous;

}

//main function
int main()
{
    printf("Implementing linked list using C\n");
    int ar[5]={5,10,15,20,25};
    struct Node *head=create_linked_list(ar,5);
    print_linked_list(head);
    struct Node *new_head=prepend_node(head,50);
    print_linked_list(new_head);
    struct Node *postpended_node=postpend_node(head,70);
    print_linked_list(postpended_node);
    struct Node *reversed_list=reverse_linked_list(head);
    print_linked_list(reversed_list);
}
