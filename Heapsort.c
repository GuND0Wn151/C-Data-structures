// C Program for implementation of heap sort for sorting the elements  in ascending  order
#include<stdio.h>
void buildheap(int a[ ],int n,int i)//check max heap property at index i
{
     int t,child;
      while(2*i+1<n )
     {
     	child=2*i+1;//this is left child
      if(child!=n-1 && a[child+1] >a[child] )//child+1 is right child
       child=child+1;
     if(a[i]<a[child])
     {
     	//swap a[i],a[child]
     	t=a[i];
     	a[i]=a[child];
     	a[child]=t;
     }    
     i=child;
    }
          
}

void heapsort(int a[ ],int n)
{
    int i,t;
    // build heap phase
       for(i=n/2;i>=0;i--)
       buildheap(a,n,i);
  //repeatedly delete the root node(node at index 0)
      for(i=n-1;i>=1;i--)
     {
           // swap a[0],a[i]
               t=a[0];
               a[0]=a[i];
              a[i]=t;
             buildheap(a,i,0);// check heap property at root for i number of values
    }
}


void main()
{
       int a[20],n,i;
       printf("enter no of values in the array");
       scanf("%d",&n);
       printf("\n enter array values:");
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       printf("\n before  sorting, array values are:\n");
       for(i=0;i<n;i++)
       printf("%d\t",a[i]);
        heapsort(a,n);
       printf("\n after  sorting,array values are:\n");
       for(i=0;i<n;i++)
       printf("%d\t",a[i]);
}
