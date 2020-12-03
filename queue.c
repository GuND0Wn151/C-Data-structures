
#include<stdio.h>
#include<stdlib.h>
#define size 10
int que[size];
int front =-1, rear=-1;
void enq(){
	int a;
	printf("\nEnter the value to be inserted");
	scanf("%d",&a);
	if(rear==9)
		printf("\nq is full overflow occers");
	else{
		que[++rear]=a;
		if(front==-1)
			front++;
	}
}

void deq(){
	if(front==-1)
		printf("\nque is empty");
	else{
		printf("\ndeletd value%d",que[front++]);
		if(front==size)
		front=rear=-1;
	}
}

void display(){
	if(front==-1)
		printf("\nqueue is empty");
	else{
		for(int i=front;i<=rear;i++)
			printf("%d  ",que[i]);
	}
}



int main(){
	int opt;
	int t=0;
	while(t==0){
	printf("\n1)enq 2)deq 3)display");
	printf("\nenter your option");
	scanf("%d",&opt);

	switch(opt){
		case 1: enq();break;
		case 2: deq();break;
		case 3: display();break;
		default :t=1; break;
	}

	}
}