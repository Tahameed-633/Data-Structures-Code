#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int coefficient;
    int exponent;
    struct Node* next;
};
struct Node *create_polynomial(struct Node *head,int c,int e)
{
    struct Node *temp=NULL,*current=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node));
    {
        temp->coefficient=c;
        temp->exponent=e;
        temp->next=NULL;
    }
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
    return head;
}


void display(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL && temp->next->coefficient >= 0)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int evaluate_polynomial(struct Node* head, int x)
{
    int r=0;
    struct Node* current=head;
    while (current!= NULL)
    {
        r=r+ current->coefficient * pow(x, current->exponent);
        current=current->next;
    }
    return r;
}

int main()
{
    struct Node* polynomial=NULL;
    int size, c, e, x;


    printf("Input the number of terms: ");
    scanf("%d", &size);


    for (int i=1; i<= size; i++)
    {
        printf("Enter the coefficient of term:-%d: ", i);
        scanf("%d", &c);
        printf("Enter the exponent of term:-%d: ", i);
        scanf("%d", &e);
        polynomial=create_polynomial(polynomial,c,e);
    }
    printf("The polynomial is: ");
    display(polynomial);
    printf("Input the value of x: ");
    scanf("%d",&x);
      int result = evaluate_polynomial(polynomial, x);
    printf("The result is = %d\n", result);
    return 0;
}
