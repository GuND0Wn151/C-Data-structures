#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left, *right;
};
struct node *root=NULL;
void insert(struct node *node,struct node *root);
struct node * delete(struct node *root,int a);
struct node *findparent(struct node *root,struct node *rt);
void inorder(struct node *root);
void rightrotate(struct node * r);
void leftrotate(struct node * r);
int bf(struct node *root);
struct node * findmin(struct node *root);
int height(struct node *root);
struct node * search(int a,struct node *root);
void LL(struct node *root);
void RR(struct node *root);
void LR(struct node *root);
void RL(struct node *root);
void main(){
	int op,a;
	while(1){
		printf("Select an option to perform that operatin\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Find min\n5. Height\n6. Exit\n");
		scanf("%d",&op);
		struct node *temp,*newnode;
		switch(op){
			case 1:
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter an element ");
			scanf("%d",&newnode->data);
			newnode->left=NULL;
			newnode->right=NULL;
			insert(newnode,root);printf("root is %d\n",root->data);
			break;
			case 2:printf("Enter the element you want to delete ");
			scanf("%d",&a);
			root=delete(root,a);
			break;
			case 3:
			if(root==NULL)
			printf("AVL tree is empty\n");
			else{
			//printf("Tree is ");
			inorder(root);break;
			case 4:if(root!=NULL){
				temp=findmin(root);	
				printf("The minimun value is %d\n",temp->data);}
				else
				printf("AVL tree is empty\n");
				break;
			case 5:a=height(root);
					printf("The height of the tree is %d\n",a);
					break;
			case 6:exit(0);
			default:printf("Please enter a valid option\n");
		}
	}

}}

struct node * findmin(struct node * root){
	while(root->left!=NULL)
	root=root->left;
	return root;	
	
}
int bf(struct node *root){
	if(root->right==NULL && root->left!=NULL)
	return height(root->left)+1;
	else if (root->left==NULL && root->right!=NULL)
	return -height(root->right)-1;
	else
	return height(root->left)-height(root->right);
}
int height(struct node *root){
	if (root ==NULL || (root->right==NULL && root->left==NULL))
	return 0;
	else 
	{
	int lh=height(root->left),rh=height(root->right) ;
	return lh>rh?lh+1:rh+1;
	}
}
struct node *search(int a,struct node *root){
	if (a<root->data)
	search(a,root->left);
	else if (a>root->data)
	search(a,root->right);
	else if(a==root->data)
	return root;
	else
	return NULL;
}
void inorder(struct node *root){
	if(root!=NULL){
	inorder(root->left);
	printf("elemnt = %d, bf = %d\n",root->data,bf(root));
	inorder(root->right);	
	}
}
void LL(struct node *root){
	rightrotate(root);
}
void RR(struct node *root){
	leftrotate(root);
}
void LR(struct node *root){
	leftrotate(root->left);
	rightrotate(root);
}
void RL(struct node *root){
	rightrotate(root->right);
	leftrotate(root);
}
void rightrotate(struct node *rt){
	struct node *parent=findparent(root,rt), *temp=rt->left->right;
	if (rt!=root){
	parent->left=rt->left;
	rt->left->right=rt;
	rt->left=temp;}
	else{
	rt->left->right=rt;
	root=rt->left;
	root->right->left=temp;
	}
}
void leftrotate(struct node *rt){
	struct node *parent=findparent(root,rt), *temp=rt->right->left;
	if(rt==root){
		rt->right->left=rt;
		root=rt->right;
		root->left->right=temp;
	}
	else
	{
	parent->right=rt->right;
	rt->right->left=rt;
	rt->right=temp;
	}
}
void insert(struct node *newnode , struct node *rt){
	if (rt==NULL)
		root=newnode;
	
	else if(newnode->data<root->data){
		if(rt->left==NULL)
		rt->left=newnode;
		else{
		insert(newnode,rt->left);
		if(bf(rt)==2){
			if(newnode->data < rt->left->data)
			LL(rt);
			else
			LR(rt);
		}
		}
	}
	else{
		if(rt->right==NULL)
		rt->right=newnode;
		else{
		insert(newnode,rt->right);
		if(bf(rt)==-2){
			if(newnode->data < rt->right->data)
			RL(rt);
			else
			RR(rt);
	
		}
	}
	}
}
struct node *findparent(struct node *root, struct node *find){
	if (root==NULL || root==find)
		return NULL;
	else if (root->left==find || root->right==find)
	return root;
	else if (find->data < root->data)
	return findparent(root->left,find);
	else if (find->data > root->data)
	return findparent(root->right,find);
	
}

struct node * delete(struct node * root,int a){
	if (root==NULL)
	return NULL;
	else if(a > root->data){
	root->right=delete(root->right,a);
	if(bf(root)==2){
			if(root->left->right==NULL)
			LL(root);
			else
			LR(root);
		}
		
	}
	else if(a<root -> data)
	{
	root->left=delete(root->left,a);
	if(bf(root)==-2){
			if(root->right->left==NULL)
			RR(root);
			else
			RL(root);
	
		}
	
	}else{
		struct node *temp=root;
		if(root->left==NULL){
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL){
			root=root->left;
			free(temp);}
		else{
			struct node * temp=findmin(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
		
	}	
	return root;
}
