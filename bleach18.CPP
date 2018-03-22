#include<iostream.h>
#include<conio.h>
struct node
{
	int data;
	node *left;
	node *right;
}*root;
node* insertBST(node *root,int item)
{
	if(root==NULL)
	{
		root=new node;
		root->data=item;
		root->left=NULL;
		root->right=NULL;
	}
	else if(item<root->data)
	{
	     root->left=insertBST(root->left,item);
	}
	else if(item>root->data)
	{      root->right=insertBST(root->right,item);
	}
	return root;
}
node* searchBST(node *root,int item)
{
	if(root!=NULL)
	{
		node* temp;
		if(root==NULL)
		temp=root;
		if(root->data==item)
		temp=root;
		else if(item<root->data)
		temp=searchBST(root->left,item);
		else if(item>root->data)
		temp=searchBST(root->right,item);
		return(temp);
	}
	else return(0);
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
node* parent =NULL;
node* searchparentBST(node *root,int item)
{
	if(root==NULL||root->data==item)
	return(parent);
	else if(item<root->data)
	{
		parent=root;
		searchparentBST(root->left,item);
	}
	else if(item>root->data)
	{
		parent=root;
		searchparentBST(root->right,item);
	}
}
node* succptr(node *ptr)
{
	node *succptr;
	if(ptr->right==NULL)
	succptr=NULL;
	else
	{
		succptr=ptr->right;
		while(succptr->left!=NULL)
		{
		succptr=succptr->left;
		}
	}
	return(succptr);
}
void deleteBST(node *root,int item)
{
	node* ptr=searchBST(root,item);
	node* par=searchparentBST(root,item);
	{if(ptr==NULL)
	cout<<"Element not present \n";
	else
	cout<<"Element deleted \n";
	}
	if(ptr->left==NULL&&ptr->right==NULL)
	{
		if(par->right==ptr)
		par->right=NULL;
		if(par->left==ptr)
		par->left=NULL;
		delete ptr;
	}
	if(ptr->left!=NULL&&ptr->right==NULL)
	{
		if(par->right==ptr)
		par->right=ptr->left;
		if(par->left==ptr)
		par->left=ptr->left;
		delete ptr;
	}
	if(ptr->left==NULL&&ptr->right!=NULL)
	{
		if(par->right==ptr)
		par->right=ptr->right;
		if(par->left==ptr)
		par->left=ptr->right;
		delete ptr;
	}
	if(ptr->left!=NULL&&ptr->right!=NULL)
	{
		node* S=succptr(ptr);
		ptr->data=S->data;
		deleteBST(S,S->data);
	}
}
void main()
{
	clrscr();
	int ch,x;
	node *temp1;
	char ans;
	do
	{
		cout<<"Enter 1 for searching an element in tree\n";
		cout<<"Enter 2 for inserting an element in tree\n";
		cout<<"Enter 3 for deleting an element from tree\n";
		cout<<"Enter 4 for inorder traversal of tree\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the element to be searched : ";
			cin>>x;
			temp1=searchBST(root,x);
			if(temp1!=NULL)
			cout<<"Element found\n";
			else if(temp1==NULL)
			cout<<"Element not present\n";
		}
		if(ch==2)
		{
			cout<<"Enter the element to be inserted : ";
			cin>>x;
			root=insertBST(root,x);
			cout<<"Entered tree is ";
			inorder(root);
			cout<<endl;
		}
		if(ch==3)
		{
			cout<<"Enter the element to be deleted : ";
			cin>>x;
			deleteBST(root,x);
		}
		if(ch==4)
		{
			cout<<"The tree is \n";
			inorder(root);
			cout<<endl;
		}
		cout<<"Do you want to perform more operations Y or N : ";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	getch();
}