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
    int item,size;
    printf("Enter the size of the linked list:\n");
    scanf("%d",& size);
    printf("Enter the elements to store in the linked list:\n");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&item);
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=item;
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
void display(struct Node *head)
{
    struct Node *current=head;
    while(current!=NULL)
    {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
void print_pair(struct Node *head,int x)
{
    struct Node *current=head,*temp=NULL;
    while(current!=NULL && current->next!=NULL)
    {
        temp=current;
        while(temp->next!=NULL)
        {
            if(current->data+temp->next->data==x)
            {
                printf("(%d,%d)\n",current->data,temp->next->data);
            }
            temp=temp->next;
        }
        current=current->next;
    }

}
int main()
{
    struct Node *head=NULL;
    int x;
    head=create_linked_list();
    display(head);
    printf("Enter the value of x:\n");
    scanf("%d",&x);
    print_pair(head,x);
}

