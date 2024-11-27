#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *a=NULL;
    struct Node *b=NULL;
    struct Node *c=NULL;
    struct Node *current=NULL;
    a=(struct Node *)malloc(sizeof(struct Node));
    b=(struct Node *)malloc(sizeof(struct Node));
    c=(struct Node *) malloc(sizeof(struct Node));
    a->data=10;
    b->data=20;
    c->data=30;
    a->next=b;
    b->next=c;
    c->next=NULL;
    current=a;
    while(current!=NULL)
    {
        printf("%d ->",current->data);
        current=current->next;
    }
    return 0;
}
