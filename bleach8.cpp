#include<iostream.h>
#include<conio.h>
struct node
{ int data;
node *next;
node *prev;
};
node *list;
void traverse_DLL()
{
node *t;
t=list;
while(t!=NULL)
{cout<<t->data<<" ";
t=t->next;
}}
void push(int x)
{
node *temp,*temp1;
temp=new node;
temp->data=x;
temp->next=NULL;
temp->prev=NULL;
temp1=list;
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp1->next=temp;
temp->prev=temp1;
temp->next=NULL;
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
list->next=NULL;
list->prev=NULL;
cout<<"do you want to enter more Y or N: ";
cin>>c;
while(c=='y'||c=='Y')
{cout<<"enter value: ";
cin>>x;
push(x);
cout<<"do you want to enter more Y or N: ";
cin>>c;
}
do
{
cout<<"enter 1 for traversal in DLL \n";
cout<<"enter 2 for insertion in DLL \n";
cout<<"enter 3 for deletion from DLL \n";
cout<<"enter your choice: ";
cin>>ch;
if(ch==1)
{
cout<<"The enteren list is \n";
traverse_DLL();
}
if(ch==2)
{
cout<<"enter 1 if you want to insert after a particular node \n";
cout<<"enter 2 if you want to insert before a particular node\n";
cout<<"enter your choice ";
cin>>ch;
if(ch==1)
{
cout<<"enter the element you want to insert: ";
cin>>x;
cout<<"enter the element you want to insert after(key): ";
cin>>key;
node *t1,*t;
t1=list;
t=new node;
t->data=x;
t->next=NULL;
t->prev=NULL;
while(t1->next!=NULL&&t1->data!=key)
{t1=t1->next;}
if(t1->data==key)
{
t->next=t1->next;
t1->next->prev=t;
t->prev=t1;
t1->next=t;
}
else if(t1->next==NULL&&t1->data==key)
{
while(t1->next!=NULL)
{t1=t1->next;}
t1->next=t;
t->prev=t1;
}
else if(t1->next==NULL)
{ cout<<key<<" is not present in the list \n";
}
cout<<"DLL after operation is \n";
traverse_DLL();
}
else if(ch==2)
{cout<<"enter the element you want to insert: ";
cin>>x;
cout<<"enter the element you want to insert before(key): ";
cin>>key;
node *t,*t1;
t1=list;
t= new node;
t->data=x;
t->next=NULL;
t->prev=NULL;
if(list->data==key)
{t->next=list;
list->prev=t;
list=t;}
else
{while(t1->next!=NULL&&t1->data!=key)
{t1=t1->next;}
if(t1->data==key)
{t->next=t1;
t1->prev->next=t;
t->prev=t1->prev;
t1->prev=t;
}
if(t1->next==NULL)
{cout<<key<<" is not present int the list \n";
}}
cout<<"DLL after operation is \n";
traverse_DLL();
}}
if(ch==3)
{cout<<"enter the element you want to delete from list: ";
cin>>key;
node *temp;
temp=list;
if(list->data==key)
{list=list->next;
list->prev=NULL;
delete temp;
}
else
{while(temp->data!=key&&temp->next!=NULL)
{temp=temp->next;}
if(temp->data==key)
{ if(temp->next==NULL)
{temp->prev->next=NULL;
delete temp;
}
else
{
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
delete temp;
}}
else if(temp->next==NULL)
{cout<<key<<" is not present in the list \n";
}}
cout<<"DLL after operation is \n";
traverse_DLL();
}
cout<<"do you want to perform more opeartions Y or N: ";
cin>>ans;
}while(ans=='Y'||ans=='y');
getch();
}

