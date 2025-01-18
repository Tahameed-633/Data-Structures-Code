#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_linked_list()
{
    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int size,item;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&size);
    printf("Enter the items to store in the linked list:\n");
    for(int i=1;i<=size;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&item);
        temp->data=item;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            current=temp;
        }
        current->next=temp;
        current=temp;
    }
    return head;
}
struct Node *reverse(struct Node *head)
{
    struct Node *current=head,*prev=NULL,*next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
bool is_palindrome(struct Node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return true;
    }
    bool palindrome_flag=true;
    struct Node *fast=head;
    struct Node *slow=head;
    if(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node *first_half=head;
    struct Node *second_half=reverse(slow);
    struct Node *temp=first_half;
    while(second_half!=NULL)
    {
        if(first_half->data!=second_half->data)
        {
            palindrome_flag=false;
            break;
        }
        first_half=first_half->next;
        second_half=second_half->next;

    }
    return palindrome_flag;
}
void display(struct Node *head)
{
    struct Node *current=head;
    while(current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head=NULL;
    head=create_linked_list();
    display(head);
    if(is_palindrome(head))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
