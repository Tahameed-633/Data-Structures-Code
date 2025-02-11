#include<stdio.h>
void print_graph(int size,int adj[size][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}
void create_graph()
{
    int size,source,destination;
    printf("Enter the number of vertexes of the graph:\n");
    scanf("%d",&size);
    int adj[size][size];
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            adj[i][j]=0;
        }

    }
    printf("Create an edge from source to destination:(%d to %d)\n",source,destination);

    while(source!=-1&&destination!=-1)
    {
        adj[source][destination]=1;
        adj[destination][source]=1;
        scanf("%d %d",&source,&destination);
    }
    print_graph(size,adj);
}

int main()
{
    create_graph();


}
