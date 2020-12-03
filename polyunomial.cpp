// WWEK 5a: C program to implement or represent a polynomial  using  SLL
#include<stdio.h>
#include<stdlib.h>
struct node{
  int coeff,expo;
  struct node *next;
};
struct node *head=NULL,*tail=NULL;
void create();
void traverse();
int main(){
  int opt;
  while(1){
  
  printf("\n 1.create \n 2.traverse 3.exit");
  printf("\n enter your option ");
  scanf("%d",&opt);
switch(opt){
  case 1:
    create();break;
  case 2:
      traverse();break;  
  default:
    return(0);
}
  }
}
void create(){
  struct node *newnode;
  int n,i;
  printf("\n how many terms you want");
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
  
  newnode=(struct node*)malloc(sizeof(struct node));
 printf("\n enter expo and coefficent values");
 scanf("%d %d",&newnode->coeff,&newnode->expo);
newnode->next=NULL;
if(head==NULL)
head=tail=newnode;
else{
  tail->next=newnode;
  tail=newnode;
  
}

}
  
}
void traverse(){
  struct node *temp;

if(head=NULL)
printf("SLL is empty");
else{
temp=head;
  while(temp!=NULL)
  { 
    printf("%d %d",temp->coeff,temp->expo);
    temp=temp->next;
  }
}
}
