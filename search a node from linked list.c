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
int search_in_linkedlist(struct Node *Head,int value)
{
    int index=1;
    while(Head!=NULL)
    {
        if(Head->data==value)
        {
            return index;
        }

        index++;
        Head=Head->next;

    }
    return -1;
}
int main()
{
    int ar[5]={5,10,15,20,25};
    struct Node *head;
    head=create_linked_list(ar,5);

    printf("\nIndex:%d \n",search_in_linkedlist(head,20));
    return 0;
}
