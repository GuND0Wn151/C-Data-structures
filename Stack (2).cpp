#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void push(){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data of newnode");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	head=newnode;
	else{
		newnode->next=head;
		head=newnode;
	}
}


void pop(){
	struct node *temp;
	if(head=NULL)
	printf("The stack is empty");
	else{
		temp=head;
		printf("%d is the deleted value",temp->data);
		head=head->next;
		free(temp);
	}
	
}


void peek(){
	if(head=NULL)
	printf("The stack is empty");
	else
	printf("%d is the top value",head->data);
}

void traverse(){
	struct node *temp;
	temp=head
	while(temp->next!=NULL){
		printf("%d \t",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}








