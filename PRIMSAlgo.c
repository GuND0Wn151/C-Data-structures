#include<stdio.h>
#define max 10
int ad[max][max] , tree[max][max],n,vis[max]={0};
void read()
{
  int i,j;
  printf("\n enter no of vertices");
  scanf("%d",&n);
  printf("\n enter the adjacency matrix:\n ");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&ad[i][j]);
    }
  }
}
int spt(int src)
{
  int i,j,min,profit=0,no_edges=1,v1,v2;
  vis[src]=1;
  while(no_edges<=n-1)
  {
    min=9999;
    for(i=0;i<n;i++)
      {
      if(vis[i]==1)
      {
        for(j=0;j<n;j++)
        {
          if(vis[j]==0&&ad[i][j]!=0)
          {
            if(min>ad[i][j])
            {
              min=ad[i][j];
              v2=j;
              v1=i;
            }
          }
        }
      }
    }
    vis[v2]=1;
    profit+=min;
    printf("\n edge %d--%d is %d",v1,v2,min);
    printf("\n edge %c--%c is %d",v1+65,v2+65,min);    
    no_edges++;
    
  }
  return profit;
}
void main(){
  int s,tc,i;
  read();
  printf("\n enter starting vertex in integer --0 for A,1 for B");
  scanf("%d",&s);
  tc=spt(s);
  printf("\n cost=%d",tc);
  
}
