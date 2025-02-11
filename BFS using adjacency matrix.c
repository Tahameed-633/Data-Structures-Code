#include<stdio.h>
void print_graph(int vertices,int adj[vertices][vertices])
{
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}
void create_graph(int vertices,int adj[vertices][vertices])
{
    int s,d;
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            adj[i][j]=0;
        }
    }
    printf("Create an edge from source to destination(-1 to -1 to stop):\n");
    scanf("%d %d",&s,&d);
    while(s!=-1&&d!=-1)
    {
        adj[s][d]=1;
        adj[d][s]=1;
        scanf("%d %d",&s,&d);
    }
}
void breadth_first_search(int vertices,int adj[vertices][vertices],int start)
{
    int visited[vertices],front=-1,rear=-1,queue[vertices];
    for(int i=0; i<vertices; i++)
        visited[i]=0;
    front++;
    queue[++rear]=start;
    visited[start]=1;
    while(front<=rear)
    {
        start=queue[front++];
        printf("%d\t",start);
        for(int i=0; i<vertices; i++)
        {
            if(adj[start][i]==1&&visited[i]!=1)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int vertices,start;
    printf("Enter the number of vertices:\n");
    scanf("%d",&vertices);
    int adj[vertices][vertices];

    create_graph(vertices,adj);
    printf("\nAdjacency matrix representation of graph:\n");
    print_graph(vertices,adj);
    printf("\nEnter the source node to start breathe first search(BFS):\n");
    scanf("%d",&start);
    printf("\nBreathe first search:\n");
    breadth_first_search(vertices,adj,start);
    return 0;
}

