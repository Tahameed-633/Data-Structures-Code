#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list()
{
    struct Node *temp=NULL,*head=NULL,*current=NULL;
    int data,size;
    printf("Enter the size of the linked list: \n");
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
int get_element(struct Node *head,int item)
{
    struct Node *current=head;
    int index=0;
    while(current->next!=NULL)
    {
        index++;
        if(current->data==item)
            break;
            else
        current=current->next;
    }
    return index;
}
int main()
{
    struct Node *head=create_linked_list();
    int item;
    printf("Input item :\n");
    scanf("%d",&item);
    int index=get_element(head,item);
    printf("Index of %d is %d",item,index);
}
