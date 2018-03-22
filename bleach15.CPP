#include<iostream.h>
#include<conio.h>
#include"stack.h"
int precedence(char sym)
{
	if(sym=='+'||sym=='-')
	return(1);
	else if(sym=='*'||sym=='/')
	return(2);
	else if(sym=='^')
	return(3);
	else
	return (0);
}
int isopt(char op)
{
	if(op=='+'||op=='-'||op=='*'||op=='/'||op=='^')
	return(1);
	else
	return(0);
}
void infix_to_postfix(char e[],char s[],int n)
{
	char x;
	e[n]='#';
	n=n+1;
	push(s,'#');
	for(int i=0;i<n;i++)
	{
		x=e[i];
		while(x!='#')
		{
			if(x>='a'&&x<='z'||x>='A'&&x<='Z'||x>=48&&x<=57)
			{
				cout<<x;
			}
			if(x=='(')
			{
				push(s,x);
			}
			if(x==')')
			{
				char y=pop(s);
				while(y!='(')
				{
					cout<<y;
					y=pop(s);
				}
			}
			if(isopt(x)==1)
			{
				char y=pop(s);
				int p=precedence(x);
				int q=precedence(y);
				while(y!='#'&&p<q)
				{
					cout<<y;
					y=pop(s);
				}
				push(s,y);
				push(s,x);
			}
			break;
		}
		if(x=='#')
		{
			char y=pop(s);
			while(y!='#')
			{
				cout<<y;
				y=pop(s);
			}
		}
	}
}
void main()
{
	clrscr();
	char e[100];
	char s[100];
	int n;
	cout<<"Enter the size of infix expression \n";
	cin>>n;
	cout<<"Enter the Infix expression \n";
	for(int i=0;i<n;i++)
	{
		cin>>e[i];
	}
	cout<<"The equivalent postfix expression is \n";
	infix_to_postfix(e,s,n);
	getch();
}
