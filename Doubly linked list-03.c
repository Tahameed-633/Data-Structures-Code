#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *add_to_empty_list(struct Node *head,int data)
{
   struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
   temp->prev=NULL;
   temp->data=data;
   temp->next=NULL;
   head=temp;
   return head;
}
struct Node *add_at_begin(struct Node *head,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct Node *add_at_end(struct Node *head,int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct Node *current=head;
    while(current->next!=NULL)
    {
      current=current->next;
    }
    current->next=temp;
    temp->prev=current;
    return head;
}
struct Node *add_at_middle(struct Node *head,int data,int position)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct Node *current=head;
    while(position !=1)
    {
        current=current->next;
        position--;
    }
    struct Node *current2=current->next;
    current->next=temp;
    temp->prev=current;
    temp->next=current2;
    current2->prev=temp;
    return head;
}
int main()
{
    struct Node *head;
    head=add_to_empty_list(head,45);
    head=add_at_begin(head,34);
     head=add_at_begin(head,54);
     head=add_at_end(head,44);
     head=add_at_middle(head,50,2);
     struct Node *current=head;
     while(current!=NULL)
     {
         printf("%d -><- ",current->data);
         current=current->next;

     }
     printf("NULL");
     return 0;
}
