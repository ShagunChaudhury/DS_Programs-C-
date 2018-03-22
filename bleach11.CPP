#include<iostream.h>
#include<conio.h>
/*struct node1
{
	 int coff;
	 int pow;
	 node1 *next;
}*list1;
struct node2
{
	int coff;
	int pow;
	node2 *next;
}*list2;   */
struct node
{	int coff;
	int pow;
	node *next;
}*list1,*list2,*list;
/*void push1(node1 *list1,int x,int y)
{
	node1 *t,*t1;
	t=new node1;
	t->coff=x;
	t->pow=y;
	t->next=NULL;
	t1=list1;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
	t1->next=t;
	t->next = NULL;
}
void push2(node2 *list2,int x,int y)
{
	node2 *t,*t1;
	t=new node2;
	t->coff=x;
	t->pow=y;
	t->next=NULL;
	t1=list2;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
	t1->next=t;
	t->next = NULL;
}  */
void push(node *list,int x,int y)
{
	node *t,*t1;
	t=new node;
	t->coff=x;
	t->pow=y;
	t->next=NULL;
	t1=list;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
	t1->next=t;
	t->next = NULL;
}
void traverse(node *list)
{
	node *t;
	t=list;
	while(t->next!=NULL)
	{
		cout<<t->coff<<"x^"<<t->pow<<"+";
		t=t->next;
	}
	cout<<t->coff<<"x^"<<t->pow;
}
void main()
{
	clrscr();
	int c1,p1,p,q,c2,p2;
	char c;
	node *t1;
	node *t2;
	node *t;
	cout<<"enter coff and power of first term of polynomial 1\n";
	cin>>c1>>p1;
	list1=new node;
	list1->coff=c1;
	list1->pow=p1;
	list1->next=NULL;
	cout<<"do you want to enter more terms Y or N : ";
	cin>>c;
	while(c=='Y'||c=='y')
	{
		cout<<"enter coff and power : ";
		cin>>c1>>p1;
		push(list1,c1,p1);
		cout<<"do you want to enter more terms Y or N : ";
		cin>>c;
	}
	cout<<"enter coff and power of first term of polynomial 2 \n";
	cin>>c2>>p2;
	list2=new node;
	list2->coff=c2;
	list2->pow=p2;
	list2->next=NULL;
	cout<<"do you want to enter more terms Y or N : ";
	cin>>c;
	while(c=='Y'||c=='y')
	{
		cout<<"enter coff and power : ";
		cin>>c2>>p2;
		push(list2,c2,p2);
		cout<<"do you want to enter more terms Y or N : ";
		cin>>c;
	}
	cout<<"the two polynomials are \n";
	traverse(list1);
	cout<<endl;
	traverse(list2);
	list=new node;
	list->coff=0;
	list->pow=0;
	list->next=NULL;
	t1=list1;
	t2=list2;
	while(t1!=NULL&&t2!=NULL)
	{
		if(t1->pow>t2->pow)
		{
			p=t1->coff;
			q=t1->pow;
			push(list,p,q);
			t1=t1->next;
		}
		else if(t1->pow<t2->pow)
		{
			p=t2->coff;
			q=t2->pow;
			push(list,p,q);
			t2=t2->next;
		}
		else if(t1->pow==t2->pow)
		{
			p=t1->coff+t2->coff;
			q=t1->pow;
			push(list,p,q);
			t1=t1->next;
			t2=t2->next;
		}
	}
	if(t1==NULL)
	{
		while(t2!=NULL)
		{
			p=t2->coff;
			q=t2->pow;
			push(list,p,q);
			t2=t2->next;
		}
	}
	else if(t2==NULL)
	{
		while(t1!=NULL)
		{
			p=t1->coff;
			q=t1->pow;
			push(list,p,q);
			t1=t1->next;
		}
	}
	cout<<"\nsum of two polynomials is \n";
	traverse(list->next);
	getch();
}

