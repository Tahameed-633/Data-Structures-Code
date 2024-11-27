#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
void menu()
{
    printf("*****Menu*****\n 1.Create the doubly linked list\n 2.Add a node at begin\n 3. Add a node at middle\n 4.Add at end\n 5.Delete the first node\n 6.Delete middle node\n 7.Delete the last node\n");
}
struct Node *create_doubly_linked_list()
{
    struct Node *head=NULL,*temp=NULL,*current=NULL;
    int size,item;
    printf("Enter the size of the doubly linked list: ");
    scanf("%d",&size);
    printf("Input the element to store in the doubly linked list: ");
    for(int i=1; i<=size; i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&item);
        temp->prev=NULL;
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
            temp->prev=current;
            current=temp;
        }
    }
    return head;
}
struct Node *add_at_begin(struct Node *head)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    int item;
    printf("Enter the item to add:\n");
    scanf("%d",&item);
    temp->prev=NULL;
    temp->data=item;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct Node *add_at_middle(struct Node *head)
{
    struct Node *current=head,*new_node=NULL,*temp1=NULL,*temp2=NULL;
    int position,item;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the position to insert:\n");
    scanf("%d",&position);
    printf("Enter the value to insert:\n");
    scanf("%d",&item);
    new_node->prev=NULL;
    new_node->data=item;
    new_node->next=NULL;
    while(position!=1)
    {
        temp1=current;
        current=current->next;
        position--;
    }
    temp2=temp1->next;
    temp1->next=new_node;
    new_node->prev=temp1;
    new_node->next=temp2;
    temp2->prev=new_node;
    return head;
}
struct Node *add_at_end(struct Node *head)
{
    struct Node *current=head,*temp=NULL;
    int item;
    temp=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value to insert\n");
    scanf("%d",&item);
    temp->prev=NULL;
    temp->data=item;
    temp->next=NULL;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=temp;
    temp->prev=current;
    return head;
}
struct Node *delete_first_node(struct Node *head)
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("List is already empty.\n");
        return head;
    }
    head=head->next;
    free(temp);
    return head;
}
struct Node *delete_middle_node(struct Node *head)
{
    int index,count=1;
    printf("Enter the index to delete\n");
    scanf("%d",&index);
    struct Node *dummy_head=(struct Node *)malloc(sizeof(struct Node));
    dummy_head->next=head;
    head->prev=dummy_head;
    struct Node *current=dummy_head;
    while(current->next!=NULL)
    {
        if(count==index)
        {
            current->next=current->next->next;
            current->next->next->prev=current;
            break;
        }
        else
        {
            current=current->next;
        }
        count++;

    }
    return dummy_head->next;

}
struct Node *delete_last_node(struct Node *head)
{
    struct Node *current=head,*temp=NULL;
    if(head==NULL)
    {
        printf("The list is already empty.\n");
        return head;
    }

    while(current->next!=NULL)
    {

        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;
}
void print(struct Node*head)
{
    while(head!=NULL)
    {
        printf("%d <-> ",head->data);
        head=head->next;

    }
    printf("NULL\n");
}

int main()
{
    struct Node *head=NULL;
    int choice;
    while(1)
    {
        menu();
        printf("Enter your choice:\n");
        scanf("%d",& choice);
        switch(choice)
        {
        case 1:
            head=create_doubly_linked_list();
            print(head);
            break;
        case 2:
            head=add_at_begin(head);
            print(head);
            break;
        case 3:
            head=add_at_middle(head);
            print(head);
            break;
        case 4:
            add_at_end(head);
            print(head);
            break;
        case 5:
            head=delete_first_node(head);
            print(head);
            break;
        case 6:
            head=delete_middle_node(head);
            print(head);
            break;
        case 7:
            head=delete_last_node(head);
            print(head);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    }

}
