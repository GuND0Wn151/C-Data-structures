#include<stdio.h>
int i,j,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int find(int i);
int union(int i,int j);
void main( )
{
	
    printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)// spanning contains n-1 no of edges if it has n vertices
	{
		for(i=0,min=9999;i<n;i++)// i is here rows
		{
			for(j=0;j < n;j++)//j is here coulumns
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;// a,u indicates first vertex
					b=v=j;// b,v indicates second vertex
				}
			}
		}
		u=find(u);
		printf("\nu=%d",u);
		v=find(v);
		printf("v=%d\n",v);
		if(union(u,v))
		{
			// min=3 edge(a-b) of weight=3
			printf("%d edge (%c,%c) =%d\n",ne++,a+65,b+65,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=9999;        
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	
}
int find(int i)
{
	while(parent[i]!=-1)
	i=parent[i];
	return i;
}
int union(int i,int j)// i,j are vertices
{
	if(i!=j)//i ,j are different vertices
	{
		parent[j]=i;
		return 1;// i,j are not forming a cycle
	}
	return 0;// forming a cycle
}

