#include<stdio.h>
#include<stdlib.h>
struct node{
	int row,column,value;
	struct node *next;
};
struct node *head=NULL, *tail=NULL;
void create(int a, int b, int c){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->row=a;
	newnode->column=b;
	newnode->value=c;
	newnode->next=NULL;
	if(head==NULL)
	head=tail=newnode;
	else
	tail->next=newnode,tail=newnode;
}
void traverse(){
	struct node *temp=head;
	while(temp!=NULL){
		printf("The value at row %d, column %d is %d\n",temp->row,temp->column,temp->value);
		temp=temp->next;
	}
}
void main()
{
int a,b,i,j,noz=0;
printf("Enter the size of matrix ");
scanf("%d %d",&a,&b);
int mat[a][b];
printf("Enter the values of matrix\n");
for(i=0;i<a;i++)
for(j=0;j<b;j++){
	scanf("%d",&mat[i][j]);
	if (mat[i][j]==0)
	noz++;
}
if (noz<=a*b/2)
printf("The given matrix is not sparse matrix\n");
else{
for(i=0;i<a;i++)
for(j=0;j<b;j++){
	if (mat[i][j]!=0)
	create(i,j,mat[i][j]);
}
	printf("The elements of Sparse Matrix are\n");
	traverse();
}
}
