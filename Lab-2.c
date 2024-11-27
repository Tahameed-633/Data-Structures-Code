#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Menu()
{
    printf("1.Create Linked List\n");
    printf("2.Insert Node At Beginning\n");
    printf("3.Insert Node At Any Position\n");
    printf("4.Delete Node From Last Position\n");
    printf("5.Delete Node From Beginning\n");
    printf("6.Delete Node from any position\n");
    printf("7.Reverse the linked list\n");
    printf("8.Delete the same elements\n");

}
struct Node *create_linked_list()
{
    struct Node *temp=NULL,*head=NULL,*current=NULL;
    int size,value;
    printf("Enter the size:\n");
    scanf("%d",&size);
    printf("Enter the values to store in the linked list\n");
    for(int i=1; i<=size; i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&value);
        temp->data=value;
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

struct Node *prepend_node(struct Node *head)
{
    struct Node *temp=NULL,*current=head;
    int item;
    temp=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value to insert:\n");
    scanf("%d",&item);
    temp->data=item;
    temp->next=head;
    head=temp;
    return head;
}
struct Node *insert_node(struct Node *head)
{
    struct Node *temp=NULL,*current=head;
    int count=0,pos,value;
    printf("Enter the position to insert:\n");
    scanf("%d",&pos);
    printf("Enter the value to insert:\n ");
    scanf("%d",&value);
    while(current->next!=NULL)
    {
        count++;
        if(count==pos-1)
        {
            temp=(struct Node *)malloc(sizeof(struct Node));
            temp->data=value;
            temp->next=current->next;
            current->next=temp;

        }
        current=current->next;
    }
    return head;
}
struct Node *delete_value(struct Node *head)
{
    struct Node *temp=NULL,*temp1=NULL;
    temp1=(struct Node *)malloc(sizeof(struct Node));
    temp1->next=head;
    temp=temp1;
    int cnt=0,pos;
    printf("Enter the position of the node to delete: \n");
    scanf("%d",&pos);
    while(temp->next!=NULL)
    {
        cnt++;
        if(cnt==pos)
        {
            temp->next=temp->next->next;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
    return temp1->next;
}
struct Node *reverse_linked_list(struct Node *head)
{
    struct Node *current=NULL,*next=NULL,*prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
void display(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL");
    printf("\n");
}
struct Node *delete_last_node(struct Node *head)
{
    struct Node *temp=NULL,*prev=NULL;
    if(head!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);

        return head;
    }
}
struct Node *delete_first_node(struct Node *head)
{
    struct Node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct Node *delete_same_item(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *current = head;
    struct Node *temp;


    while (current != NULL && current->next != NULL)
    {
        temp = current;


        while (temp->next != NULL)
        {
            if (temp->next->data == current->data)
            {
                struct Node *duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }

    return head;
}

int main()
{
    int choice;
    struct Node *head=NULL;
    while(1)
    {
        Menu();
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=create_linked_list();
            display(head);
            break;
        case 2:
            head=prepend_node(head);
            display(head);
            break;
        case 3:
            head=insert_node(head);
            display(head);
            break;
        case 4:
            head=delete_last_node(head);
            display(head);
            break;
        case 5:
            head=delete_first_node(head);
            display(head);
            break;
        case 6:
            head=delete_value(head);
            display(head);
            break;
        case 7:
            head=reverse_linked_list(head);
            display(head);
            break;
        case 8:
            head=delete_same_item(head);
            display(head);
            break;
        default:
            printf("Invalid choice.Please try again!\n");
        }
    }
}




