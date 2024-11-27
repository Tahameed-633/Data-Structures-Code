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
    printf("Enter the size of the linked list: \n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n");
    for(int i=1; i<=size; i++)
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
        else
        {
            current->next=temp;
            current=temp;
        }
    }
    return head;
}
void print(struct Node *head)
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
int multiplication_of_linked_list(struct Node *head1,struct Node *head2)
{
    int num1=linked_list_to_integer(head1);
    int num2=linked_list_to_integer(head2);
    int mul=num1*num2;
    return mul;
}
struct Node *integer_to_linked_list(int num)
{
    if (num == 0)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = 0;
        temp->next = NULL;
        return temp;
    }

    int digit[50], count = 0;
    struct Node *head = NULL, *temp = NULL, *current = NULL;

    while (num != 0)
    {
        digit[count++] = num % 10;
        num /= 10;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
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
            current = temp;
        }
    }
    return head;
}
int main()
{
    struct Node *head1=NULL,*head2=NULL;
    head1=create_linked_list();
    print(head1);
    head2=create_linked_list();
    print(head2);
    int mul=multiplication_of_linked_list(head1,head2);
    printf("Multiplied linked list\n");
    struct Node *head3=integer_to_linked_list(mul);
    print(head3);

}
