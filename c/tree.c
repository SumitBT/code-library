#include<stdio.h>
#include<stdlib.h>
struct btree
{
int data;
struct btree *left;
struct btree *right;
};
struct btree *root=NULL;
struct btree *insert(struct btree*,int);
void inorder(struct btree*);
void main()
{
	int n;
	printf("enter numbers to insert in tree and -1 to quit\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		root=insert(root,n);
		scanf("%d",&n);
	}
	printf("inorder traversing:\n");
	inorder(root);
}
struct btree *insert(struct btree *node,int num)
{
	if(node==NULL)
	{
		node=(struct btree*)malloc(sizeof(struct btree));
		node->left=node->right=NULL;
		node->data=num;
	}
	else
	{
		if(num<node->data)
		{
			node->left=insert(node->left,num);
		}
		else if(num>node->data)
		{
			node->right=insert(node->right,num);
		}
	}
	return node;
}
void inorder(struct btree *node)
{
	if(node!=NULL)
	{
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
	}
}