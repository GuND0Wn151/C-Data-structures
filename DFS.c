
#include<stdio.h>
int visited[10]={0},adj[10][10],n;
void dfs(int start );
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
   printf( "DFS TRAVERSAL");
   dfs(start);
}
 void dfs( int start )
{
    	int stack[10],top=-1,i,dv;
    	stack[++top]=start;
    	visited[ start]=1;
    	while ( top!=-1)
    	{
           		dv=stack[top--];
           		printf("%c\t",dv+65);
           		for (i=0;i<n;i++)
            		{

                          		if (visited [i]==0 && adj[dv][i]==1)
                                 		{
                                          		stack[++top]=i;
                                           		visited[i]=1;
                                  		}
             		}
      	}
 }
