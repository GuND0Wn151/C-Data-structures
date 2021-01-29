
#include<stdio.h>
int visited[10]={0},adj[10][10],n;
void bfs(int start );
void  main( )
{
   int  i,j,start;
   printf("\n enter number of nodes/vertices in a graph");
   scanf("%d",&n);
   printf(" enter the adjacency matrix of a graph");
     for (i=0;i<n ;i++) {
     for (j=0;j<n ;j++) {
	 scanf("%d",&adj[i][j]);
                    }
     }
   printf("\n enter starting node/vertex in integer");
   scanf("%d",&start);
   printf( "BFS TRAVERSAL");
   bfs(start);
}
 void bfs( int start )
{
    	int queue[10],rear=-1,front=-1,i,dv;
    	queue[++rear]=start;
    	front++;
    	visited[ start]=1;
    	while ( front<=rear)
    	{
	 	 dv=queue[front++];
      		printf("%c\t",dv+65);
         		for (i=0;i<n;i++)
            		{

                          		if (visited [i]==0 && adj[dv][i]==1)
                                		{
                                          		queue[++rear]=i;
                                           		visited[i]=1;
                                  		}
          	 	}
           	}
 }
