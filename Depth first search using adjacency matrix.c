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
    printf("Create edges from source to vertices:\n");
    scanf("%d %d",&s,&d);
    while(s!=-1&&d!=-1)
    {
        adj[s][d]=1;
        adj[d][s]=1;
        scanf("%d%d",&s,&d);
    }
}
void depth_first_search(int vertices,int adj[vertices][vertices],int visited[vertices],int start)
{
    printf("%d\t",start);
    visited[start]=1;
    for(int i=0; i<vertices; i++)
    {
        if(visited[i]==0&& adj[start][i]==1)
        {
            depth_first_search(vertices,adj,visited,i);
        }
    }
}
int main()
{
    int vertices,start;
    printf("\nEnter the number of vertices:\n");
    scanf("%d",&vertices);
    int adj[vertices][vertices];
    int visited[vertices];
    for(int i=0; i<vertices; i++)
        visited[i]=0;
    create_graph(vertices,adj);
    printf("\nAdjacency matrix representation of graph:\n");
    print_graph(vertices,adj);
    printf("\nEnter the starting node to start the depth first search:\n");
    scanf("%d",&start);
    printf("\nDepth first search:\n");
    depth_first_search(vertices,adj,visited,start);
}
