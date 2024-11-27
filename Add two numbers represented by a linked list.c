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
    printf("Enter the size of the linked list:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n ");
    for(int i=1; i<=size; i++)
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
void display(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int linked_list_to_integer(struct Node *head)
{
    int num=0;
    while(head!=NULL)
    {
        num=num*10+head->data;
        head=head->next;
    }
    return num;
}
int summation_of_linked_lists(struct Node *head1,struct Node *head2)
{
    int sum=0;
    int num1=linked_list_to_integer(head1);
    int num2=linked_list_to_integer(head2);
    sum=num1+num2;
    return sum;
}
struct Node *integer_to_linked_lists(int num)
{
    struct Node *head = NULL, *current = NULL;
    int digit[10], count = 0;
    while (num != 0)
    {
        digit[count++] = num % 10;
        num = num / 10;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = digit[i];
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }

    return head;
}

int main()
{
    struct Node *head1=NULL,*head2=NULL;
    head1=create_linked_list();
    display(head1);
    head2=create_linked_list();
    display(head2);
    int sum=summation_of_linked_lists(head1,head2);
    struct Node *head3=integer_to_linked_lists(sum);
    display(head3);
}
