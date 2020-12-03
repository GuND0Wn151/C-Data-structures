//week 3 lab program c program to implement circular single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *head=NULL,*tail=NULL;
void create();
void traverse();
void insertbegin();
void insertend();
void insertspecific();
void deletebegin();
void deleteend();
void deletespecific();


void main(){
	create();
	traverse();
	insertbegin();
	traverse();
	insertend();
	traverse();
	insertspecific();
	traverse();
	deletebegin();
	traverse();
	deleteend();
	traverse();
	
	deletespecific();
	traverse();
}


void create(){
	struct node *newnode;
	int n,i;
	printf("\n enter the no of nodes u want ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter the newnodes data ");
		scanf("%d",&newnode->data);
		newnode->next=newnode;
		if(head==NULL)//csll is empty
		head=tail=newnode;
		else{
			tail->next=newnode;
			tail=newnode;
			tail->next=head;
		}
		
	}
	
}


void traverse(){
	struct node *temp;
	if(head==NULL)
	printf("\n csll is empty");
	else{
		temp=head;
		printf("\n csll is ");
		while(temp->next!=head){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("%d\t",temp->data);//for last data
		
	}
	
}


void insertbegin(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter newnode's data at begining  ");
	scanf("%d",&newnode->data);
	newnode->next=newnode;
	newnode->next=head;
	head=newnode;
	tail->next=head;
}


void insertend(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter newnode's data at end  ");
	scanf("%d",&newnode->data);
	newnode->next=newnode;
	tail->next=newnode;
	tail=newnode;
	tail->next=head;
	
}


void insertspecific(){
	struct node *newnode,*temp,*pretemp;
	int count,p;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter newnode's data");
	scanf("%d",&newnode->data);
	newnode->next=newnode;
	printf("\n enter the postion");
	scanf("%d",&p);
	temp=head;count=1;
	while(count!=p){
		pretemp=temp;
		temp=temp->next;
		count++;
	}
	pretemp->next=newnode;
	newnode->next=temp;
}


void deletebegin(){
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	tail->next=head;
}


void deleteend(){
	struct node*temp;
	temp=head;
	while(temp->next!=tail)
	temp=temp->next;
	temp->next=head;
	free(tail);
	tail=temp;
}

void deletespecific()
{
    printf("\nThis fucntion can't delete the head/tail node\n");
    if (head==NULL)
    printf("CSLL is empty\n");
    else
    {
        struct node *temp, *pretemp;
        int count,position;
        printf("\nEnter the position of node you want to delete ");
        scanf("%d",&position);
        for(temp=head,count=1;count<position; pretemp=temp, temp=temp->next, count++)
        {}
        pretemp->next=temp->next;
        free(temp);

    }
}






























