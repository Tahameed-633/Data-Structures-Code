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
struct Node *rotate_counter_clockwise(struct Node *head)
{

   int k;
   printf("Enter the number of rotation:\n");
   scanf("%d",&k);
   for(int i=0;i<k;i++)
   {
      struct Node *current=head,*temp=NULL;
      while(current->next!=NULL)
   {    temp=current;
       current=current->next;
   }
   temp->next=NULL;
    current->next=head;
    head=current;

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
int main()
{
    struct Node *head=create_linked_list();
    printf("Original linked list:\n");
    display(head);
    head=rotate_counter_clockwise(head);
    printf("Counter clockwise rotated linked list:\n");
    display(head);
}
