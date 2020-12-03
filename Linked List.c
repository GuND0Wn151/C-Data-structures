#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL,*tail=NULL;
void traverse()
{
	struct node *temp;
	temp=head;
	if (temp==NULL)
	printf("SLL is empty\n");
	else{
		printf("The elements of SLL are \n");

		for(temp=head;temp!=NULL;temp=temp->next)
		printf("%d\n",temp->data);
}
}

   
void insertatbegin()
{	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data ");
	scanf("%d",&newnode->data);
	if (head==NULL)
	tail=newnode;
	newnode->next=head;
	head=newnode;
}
void insertatend()
{	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (head==NULL)
	head=newnode,tail=newnode;
	else	{
	tail->next=newnode;
	tail=newnode;
}
}
void insertatmid()
{
	int count=1,a;
	struct node *newnode,*temp,*pretemp;
	temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the position ");
	scanf("%d",&a);
	printf("Enter data ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if (head==NULL)
		head=tail=newnode;
	else{
	while (count<a)
	{ 
		pretemp=temp;
		temp=temp->next;
		if(temp==NULL)
		{
		printf("the last position in SLL is %d\n",count);
		printf("The given element will be added to the end of SLL\n");
		break;
		}
		count++;
	}
	if (temp==head)
		newnode->next=temp,head=newnode;		
	pretemp->next=newnode;
	newnode->next=temp;
	if (temp==NULL)
	tail=newnode;
}}
void deleteatbegin(){
	if (head==NULL)
	printf("SLL is empty\n");
	else
	{
	struct node *temp;
	temp=head->next;
	free(head);
	head=temp;
}
}
void deleteatend()
{
	if (tail==NULL)
	printf("SLL is empty\n");
	else
	{
		struct node *temp;
		temp=head;
		while (temp->next!=tail)
		{
			temp=temp->next;
		}
	temp->next=NULL;
	free(tail);
	}
}

void deleteatmid()
{
	int a,count=1;
	printf("Enter the position to delete ");
	scanf("%d",&a);
	struct node *temp, *pretemp;
	if (head==NULL)
	printf("SLL is empty\n");
	else if(a==1)
	{
		temp=head->next;
		free(head);
		head=temp;
	}
	else
	{temp=head;
	while(count<a)
	{
		pretemp=temp;
		temp=temp->next;
		if(temp->next==NULL)
		{
			printf("The last position of node is %d\n",++count);
			printf("The last node will be deleted\n");
			break;
		}
		count++;
	}
	if (temp->next==NULL)
	{
	pretemp->next=NULL;
	free(temp);
	tail=pretemp;
	}
	else
	{
		pretemp->next=temp->next;
		free(temp);
	}
	}
}

void main()
{
	while(1)
	{
	printf("Select the option to perform certain operation on SLL\n1. inserting element in front\n2. inserting element at back\n3. inserting an elemtny in middle\n4. delete element at front\n5. delete element at end\n6. delete an element in middle\n7. display the elememts of SLL\n8. exit\n");
	int op;
	scanf("%d",&op);
	switch(op)
	{
		case 1:insertatbegin();break;
		case 2:insertatend();break;
		case 3:insertatmid();break;		
		case 4:deleteatbegin();break;
		case 5:deleteatend();break;
		case 6:deleteatmid();break;
		case 7:traverse();break;
		case 8:exit(0);
		deafult:printf("Please enter a valid option\n");
	}
	
	}

}
