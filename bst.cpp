#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *left;
  int data;
  struct node *right;
};
struct node *root=NULL;
struct node *insert(int e, struct node *root);
struct node *search(int e,struct node *root);
struct node *findmin(struct node *root);
struct node *delet(int e, struct node *root);
void inorder(struct node *root);
int height(struct node *root);
int main()
{
  int ch,ele,h;
  struct node *p;
  while(1){
    printf("\n binary search tree operations");
    printf("\n 1.INSERT");
    printf("\n 2.Search");
    printf("\n 3.Findmin");
    printf("\n 4.Delete");
    printf("\n 5.Height of tree");
    printf("\n 6.Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("\n enter the element to be inserted");
      scanf("%d",&ele);
      root=insert(ele,root);
      printf("\n bst after insertion");
      inorder(root);
      break;
      case 2:printf("\n enter the element to be searched");
      scanf("%d",&ele);
      p=search(ele,root);
      if(p!=NULL)
      printf("\n element is found");
      else
      printf("\n element is not found");
      break;
      case 3: p=findmin(root);
      if(p!=NULL)
      printf("\n bst is empty");
      else
      printf("\n the smallest element is:%d",p->data);
      break;
      case 4:
        printf("\n enter the element is %");
        scanf("%d",&ele);
        root=delet(ele,root);
        printf("\n the bst after deletion ");
        inorder(root);
        break;
      case 5:h=height(root);
      printf("\n height of a bst is:%d",h);
      break;
      case 6:
        exit(0);
        
    }
  }
}
struct node *insert(int val,struct node *root){
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  root=newnode;
  else if(val<=root->data)
  root->left=insert(val,root->left);
  else
  root->right=insert(val,root->right);
  return root;
}
void inorder(struct node *root){
  if(root!=NULL){
  
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
}
}
struct node *search(int x,struct node *root){
  if(root==NULL)
  return NULL;
  else if(x==root->data)
  return root;
  else if(x<root->data)
  return search(x,root->left);
  else
  return search(x,root->right);
  
}
struct node *findmin(struct node *root){
  if(root!=NULL)
  {
    while(root->left!=NULL)
      root=root->left;
      
}
    return root;
  
}
struct node *delet(int x,struct node *root){
  struct node *temp;
  if(root==NULL)
  printf("\n the element is not found");
  else if(x<root->data)
  root->left=delet(x,root->left);
  else if(x<root->data)
  root->right=delet(x,root->right);
  else{//x=root->data------------
    if(root->left&&root->right){//when node has 2 children
    
    temp=findmin(root->right);
    root->data=temp->data;
    root->right=delet(temp->data,root->right);
  }
  else if(root->left==NULL&&root->right==NULL)
  {
    temp=root;
    free(temp);
    root=NULL;
  }
  else{
  temp=root;
  if(root->right==NULL)
  root=root->left;
  else
  root=root->right;
  free(temp);
  }
  
  }
  return root;
}
int height(struct node *root){
  int lh,rh;
  if(root==NULL)
  return 0;
  else if(root->left==NULL&& root->right==NULL)
  return 0;
  else{
    lh=height(root->left);
    rh=height(root->right);
    if(lh>rh)
    return 1+lh;
    else 
    return 1+rh;
  }
}
