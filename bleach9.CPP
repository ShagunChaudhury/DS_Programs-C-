#include<iostream.h>
#include<conio.h>
struct node{
int data;
node *next;
};
node *list;
void traverse_CLL()
{
node *t;
t=list;
if(list!=NULL)
{
	while(t->next!=list)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<t->data<<endl;
}
}
void push(int x)
{
	node *temp,*temp1;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	temp1=list;
	while(temp1->next!=list)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp1->next->next=list;
}
void insert_after_CLL(node *list,int x,int key)
{node *t,*t1;
t1=list;
t=new node;
t->data=x;
t->next=NULL;
while(t1->next!=list&&t1->data!=key)
	{
	t1=t1->next;
	}
	if(t1->data==key)
	{
	t->next=t1->next;
	t1->next=t;
	}
else if(t1->data==key&&t1->next==NULL)
	{
	t1->next=t;
	t->next=list;
	}
else if(t1->next==NULL)
{
cout<<key<<" is not present in the list \n";
}
}
void insert_before_CLL(int x,int key)
{
node *t,*t1,*prev;
t=new node;
t->data=x;
t->next=NULL;
t1=list;
if(list->data==key)
{while(t1->next!=list)
{t1=t1->next;
}t1->next=t;
t->next=list;
list=t;
}
else
{while(t1->data!=key&&t1->next!=list)
{prev=t1;
t1=t1->next;
}
if(t1->data==key)
{t->next=t1;
prev->next=t;
}
else if(t1->next==NULL)
{
cout<<key<<" is not present \n";
}}
}
void delete_CLL(int key)
{node *temp,*prev,*temp1;
temp=list;
temp1=list;
if(list->data==key)
{while(temp1->next!=list)
{temp1=temp1->next;
}
temp1->next=list->next;
list=list->next;
delete temp;
}
else
{
while(temp->data!=key)
{
prev=temp;
temp=temp->next;
}
if(temp->data==key)
{prev->next=temp->next;
delete temp;
}
else
{cout<<key<<" is not present in the list \n";
}}
}
void main()
{
	clrscr();
	int x,item,ch,key;
char c,ans;
list=new node;
cout<<"enter data in first node: ";
cin>>x;
list->data=x;
list->next=list;
cout<<"do you want to enter more Y or N: ";
cin>>c;
while(c=='Y'||c=='y')
{
cout<<"enter value: ";
cin>>x;
push(x);
cout<<"do you want to enter more values Y or N: ";
cin>>c;
}
do
{
cout<<"enter 1 for traversal in CLL \n";
cout<<"enter 2 for insertion after a particular node \n";
cout<<"enter 3 for insertion before a particular node \n";
cout<<"enter 4 for deletion in CLL \n";
cout<<"enter your choice \n";
cin>>ch;
if(ch==1)
{
cout<<"the entered CLL is as follows \n";
traverse_CLL();
}
if(ch==2)
{
cout<<"enter the element you want to insert \n";
cin>>item;
cout<<"enter the element you want to insert after(key) \n";
cin>>key;
insert_after_CLL(list,item,key);
cout<<"CLL after insertion is \n";
traverse_CLL();
}
if(ch==3)
{
cout<<"enter the element you want to insert \n";
cin>>item;
cout<<"enter the element you want to insert before(key) \n";
cin>>key;
insert_before_CLL(item,key);
cout<<"CLL after insertion is \n";
traverse_CLL();
}
if(ch==4)
{
cout<<"enter the element you want to delete \n";
cin>>x;
delete_CLL(x);
cout<<"CLL after deletion is \n";
traverse_CLL();
}
cout<<"do you want to perform more operations Y or N \n";
cin>>ans;
}while(ans=='Y'||ans=='y');
getch();
}














