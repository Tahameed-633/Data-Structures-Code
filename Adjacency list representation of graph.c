#include<stdio.h>
#include<stdlib.h>
int nodes;
int item;
struct Node
{
    int data;
    struct Node *next;
};
void create_graph(struct Node *adj[])
{
    int n;
    struct Node *new_node=NULL;
    struct Node *current=NULL;
    for(int i=0; i<nodes; i++)
    {
        printf("Enter the number of nodes adjacent to node: %d\n",i);

        scanf("%d",&n);
        adj[i]=NULL;
        current=NULL;
        for(int j=0; j<n; j++)
        {
            new_node=(struct Node *)malloc(sizeof(struct Node));
            if(new_node==NULL)
            {
                printf("Can't allocate memory.\n");
                return;
            }
            printf("Enter the %dth neighbour of %dth node.\n",j+1,i);
            scanf("%d",&item);
            new_node->data=item;
            new_node->next=NULL;
            if(adj[i]==NULL)
            {
                adj[i]=new_node;

            }
            else
            {
                current->next=new_node;

            }
            current=new_node;

        }
    }
}
void print_graph(struct Node *adj[])
{
    struct Node *temp=NULL;
    for(int i=0; i<nodes; i++)
    {
        temp=adj[i];
        printf("\nNodes adjacent to %d th node are:\n",i);
        while(temp!=NULL)
        {
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    printf("Enter the number of nodes in the graph:\n");
    scanf("%d",&nodes);
    struct Node *adj[nodes];
    for(int i=0; i<nodes; i++)
    {
        adj[i]=NULL;
    }
    create_graph(adj);
    print_graph(adj);

}

