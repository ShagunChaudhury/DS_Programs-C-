#include<iostream.h>
#include<conio.h>
struct node
{
	int data;
	node *left;
	node *right;
}*root;
struct node* createnode(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	return temp;
}
void preorder(node *root)
{
	if(root==NULL)
	return;
	else
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root==NULL)
	return;
	else
	{
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root==NULL)
	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"  ";
	}
}
void main()
{
	clrscr();
	root=createnode(17);
	root->left=createnode(31);
	root->right=createnode(46);
	root->left->left=createnode(10);
	root->left->right=createnode(15);
	root->right->right=createnode(23);
	cout<<"Preorder traversal \n";
	preorder(root);
	cout<<endl;
	cout<<"\nInorder traversal \n";
	inorder(root);
	cout<<endl;
	cout<<"\nPostorder traversal \n";
	postorder(root);
	getch();
}


