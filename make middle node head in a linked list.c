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
    int data,size;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&size);
    printf("Enter the elements to store in the linked list:\n");
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
        printf("NULLL");
        printf("\n");
    }
    int get_length(struct Node *head)
    {
        int length=0;
        struct Node *current=head;
        while(current!=NULL)
        {
            length++;
            current=current->next;
        }
        return length;
    }
    struct Node *changed_linked_list(struct Node *head)
    {
        struct Node *current=head,*temp=NULL;
        int length=get_length(head);
        int mid_index=length/2;
       for (int i = 0; i <= mid_index; i++) {
        temp = current;
        current = current->next;
    }


    if (temp != NULL) {
        current->next=temp->next;
        temp->next=head;
        head = temp;
    }

    return head;
}

    int main()
    {
        struct Node *head=create_linked_list();
        display(head);
        head=changed_linked_list(head);
        display(head);
    }
