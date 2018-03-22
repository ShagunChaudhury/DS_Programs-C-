//stack using linked list

#include<iostream.h>
#include<conio.h>
struct node
{
	int data;
	node *next;
};
node *top=NULL;
void push(int x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=top;
	top=temp;
}
int pop()
{
	if(top==NULL)
	{
		cout<<"underflow!! \n";
		return(0);
	}
	else
	{
	node *temp;
	temp=top;
	int x=temp->data;
	top=top->next;
	delete temp;
	return x;
	}
}
void display()
{
	node *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}
void main()
{
	clrscr();
	int ch,n,y;
	char c;
	do
	{
		cout<<"choose your option \n";
		cout<<"1. Pushing an element in stack\n";
		cout<<"2. Popping an element from stack\n";
		cout<<"3. To display contents of stack\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the number to be pushed : ";
			cin>>n;
			cout<<endl;
			push(n);
			cout<<"resultant stack is\n";
			display();
		}
		else if(ch==2)
		{
			y=pop();
			if(y==0)
			{
			cout<<"No element deleted \n";
			}
			else
			cout<<"The deleted element is "<<y<<endl;
		}
		if(ch==3)
		{
			cout<<"Entered stack is \n";
			display();
		}
		cout<<"Do you want to perform more operations Y or N\n";
		cin>>c;
	}
	while(c=='y'||c=='Y');
	getch();
}