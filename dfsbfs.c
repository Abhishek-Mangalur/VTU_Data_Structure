#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 25
int adj_matrix[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES]; 

void add_edge(int start, int end)
{
    adj_matrix[start][end] = 1;
}

void create_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    printf("Enter the no. of Edges: ");
    int edge;
    scanf("%d",&edge);
    printf("Enter the starting and ending vertices of a an edge\n");
    for (int i = 0; i < edge; i++)
    {
        int start, end;
        scanf("%d %d",&start,&end);
        add_edge(start,end);
    }
}

void printarray(int n)
{
    printf("Matrix Representation\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int start, int n)
{
    visited[start] = 1;
    printf("%d ",start);
    for (int i = 0; i < n; i++)
    {
        if(adj_matrix[start][i] && !visited[i])
            dfs(i, n);
    }
}

void bfs(int start, int n)
{
    int queue[MAX_CITIES], front = -1, rare = -1;
    queue[++rare];
    visited[start] = 1;
    while (front != rare)
    {
        int node = queue[++front];
        printf("%d", node);
        for (int i = 0; i < node; i++)
        {
            if(adj_matrix[node][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++rare] = i;
            }
        }
    }
}

void main()
{
    printf("Enter the no. of cities: ");
    int n, start;
    scanf("%d", &n);
    create_graph(n);
    printarray(n);
    printf("Enter the starting point: ");
    scanf("%d",&start);
    printf("dfs from node %d", start);
    dfs(start,n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("bfs from node %d", start);
    bfs(start, n);
}
