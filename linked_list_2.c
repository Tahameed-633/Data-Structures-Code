#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
 struct Node *create_linked_list(int arr[],int size)
 {
     struct Node *temp=NULL,*head=NULL,*current=NULL;
     for(int i=0;i<size;i++)
     {
         temp=(struct Node *)malloc(sizeof(struct Node));
         temp->data=arr[i];
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
 int main()
 {
     int arr[5]={5,10,15,20,25};
     struct Node *head;
     head=create_linked_list(arr,5);
     while(head!=NULL)
     {
         printf("%d -> ",head->data);
         head=head->next;
     }
 }
