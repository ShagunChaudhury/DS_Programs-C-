#include<iostream.h>
#include<conio.h>
#include"stack1.h"
#include<math.h>
int opt(char op,int p,int q)
{
      int res;
      if(op=='+')
      {
	res=p+q;
      }
      if(op=='-')
      {
	res=p-q;
      }
      if(op=='*')
      {
	res=p*q;
      }
      if(op=='/')
      {
	res=p/q;
      }
      if(op=='^')
      {
	res=(pow(p,q));
      }
      return(res);
}
int posteval(char e[],int s[],int n)
{
       for(int i=0;i<=n;i++)
       {
	     int x=e[i];
	     while(x!='\0')
	     {
		if(x>=48&&x<=57)
		{
			push(s,x-'0');
		}
		else
		{
			int m=pop(s);
			int n=pop(s);
			int y=opt(x,n,m);
			push(s,y);
		}
		break;
	     }
       }
       int result=pop(s);
       return result;
}
void main()
{
	clrscr();
	char e[100];
	int s[100];
	int n,res;
	cout<<"Enter the size of postfix expression \n";
	cin>>n;
	cout<<"Enter the postfix expression \n";
	for(int i=0;i<n;i++)
	{
		cin>>e[i];
	}
	res=posteval(e,s,n);
	cout<<"Result of the given postfix expression is "<<res;
	getch();
}