//stack using array


#include<iostream.h>
#include<conio.h>
#include<process.h>
int maxsize;
int top=-1;
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==maxsize-1)
	return 1;
	else
	return 0;
}
void push(int s[],int item)
{
	if(isfull())
	cout<<"overflow!! stack is full \n";
	else
	{
		top=top+1;
		s[top]=item;
	}
}
int pop(int s[])
{
	int x;
	if(isempty())
	cout<<"Underflow!! stack is empty \n";
	else
	{
		x=s[top];
		top=top-1;
	}
	return(x);
}
void main()
{
	clrscr();
	cout<<"Enter size of stack \n";
	cin>>maxsize;
	int y,c,item,s[100];
	while(1)
	{
		cout<<"enter your choice \n";
		cout<<"1. Push \n2. Pop \n3. Display \n4. Exit\n";
		cin>>c;
		if(c==1)
		{
			cout<<"enter the element to be pushed into stack \n";
			cin>>item;
			push(s,item);
		}
		if(c==2)
		{       if(!isempty())
			{	y=pop(s);
				cout<<"the deleted element is ";
				cout<<y<<"\n";
			}
			else
			{
				y=pop(s);
			}
		}
		if(c==3)
		{       cout<<"the entered stack is \n";
			for(int i=top;i>=0;i--)
			cout<<s[i]<<endl;
		}
		if(c==4)
		{
			exit(1);
		}
	getch();
	}
}
