#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n; //Number of vertices
int adjMatrix[MAX][MAX];
void insertEdge(int u,int v){   //u=souce ,v=destination
    adjMatrix[u][v] =1;
    adjMatrix[v][u]=1;   //Only for un-directed graph
    printf("Edge Insert !!\n");   
}
void bfs(int start){
    int queue[MAX],front =-1,rear =-1;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i] =0;
    printf("BFS Traversal : ");
    queue[++rear] = start;
    front++;
    while(front<=rear){
        int v= queue[front++];
        printf("%d ",v);
        for(int i=0;i<n;i++){
            if(visited[i] == 0 &&adjMatrix[v][i] ==1)
            visited[i] = 1;
            queue[++rear] = i;
        }
    }
    printf("\n");
}
void dfs(int start){
    int stack[MAX],top =-1;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i] = 0;
    printf("DFS Traversal : ");
    stack[++top] =start;
    while(top != -1){
        int v =stack[top--];
        if(visited[v]==0){
            printf("%d",v);
            visited[v]=1;
        }
        for(int i=0;i<n;i++){
            if(adjMatrix[v][i] ==1 && visited[i] ==0)
            stack[++top] =i;
        }
    }
    printf("\n");
}
int main(){
    printf("Enter number of vertexs: ");    printf("0")
    scanf("%d",&n);
    int choice,u,v,start;
    while(1){
        printf("1. Insert Edge In graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4.Exit\n");
        printf("Enter choice :");
        switch(choice){
            case 1:
            printf("Enter Edge (U,V): ");
            scanf("%d%d",&u,&v);
            insertEdge(u,v);
                 break;
            case 2:
            printf("Enter Staring Vertex ");
            scanf("%d",&start);
            bfs(start);
                 break;
            case 3:
            printf("Enter Staring Vertex :");
            scanf("%d",&start);
            dfs(start);
                 break;
            case 4:
                 exit(0);
            default:
                 printf("Invalid Choice!!!\n");
        }
    }
    return 0;
}
