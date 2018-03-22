#include<iostream.h>
#include<conio.h>
struct node
{int data;
node *next;
};
node *list;
void traverse_SLL()
{
node *t;
t=list;
while(t!=NULL)
{
cout<<t->data<<" ";
t=t->next;
}}
void push(int x)
{
node *temp,*temp1;
temp=new node;
temp->data=x;
temp->next=NULL;
temp1=list;
while(temp1->next!=NULL)
{temp1=temp1->next;
}
temp1->next=temp;
temp->next=NULL;
}
void main()
{
clrscr();
int x,item,ch,key;
char c,ans;
list=new node;
cout<<"enter data in first node ";
cin>>x;
list->data=x;
list->next=NULL;
cout<<"do you want to enter more Y or N ";
cin>>c;
while(c=='Y'||c=='y')
{
cout<<"enter value ";
cin>>x;
push(x);
cout<<"do you want to enter more values ";
cin>>c;
}
do
{
cout<<"enter 1 for traversal in SLL \n";
cout<<"enter 2 for insertion after a particular node in SLL \n";
cout<<"enter 3 for insertion before a particular node in SLL \n";
cout<<"enter 4 for deletion in SLL \n";
cout<<"enter 5 for revering a SLL by revering the links \n";
cout<<"enter your choice ";
cin>>ch;
if(ch==1)
{
traverse_SLL();
}
if(ch==2)
{
cout<<"enter the element you want to insert after in the node\n";
cin>>key;
cout<<"enter the element you want to insert\n";
cin>>item;
node *t,*t1;
t=new node;
t->data=item;
t->next=NULL;
t1=list;
while(t1->data!=key&&t1->next!=NULL)
{t1=t1->next;}
if(t1->data==key)
{
t->next=t1->next;
t1->next=t;
}else if(t1->next==NULL)
{cout<<key<<" is not present in the list\n";
}
cout<<"SLL after insertion is \n";
traverse_SLL();
}
if(ch==3)
{
cout<<"enter the element you want to insert before in the node\n";
cin>>key;
cout<<"enter the element you want to insert\n";
cin>>item;
node *t,*t1,*prev;
t=new node;
t->data=item;
t->next=NULL;
t1=list;
if(t1->data==key)
{t->next=list;
list=t;
}
else
{while(t1->data!=key&&t1->next!=NULL)
{prev=t1;
t1=t1->next;
}if(t1->data==key)
{t->next=t1;
prev->next=t;
}
else if(t1->next==NULL)
{cout<<key<<" is not present\n";
}}
cout<<"SLL after insertion is \n";
traverse_SLL();
}
if(ch==4)
{
cout<<"enter the element to be deleted from the list \n";
cin>>key;
node *temp,*prev;
temp=list;
if(temp->data==key)
{
list=list->next;
delete temp;
}else
{while(temp->data!=key&&temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
if(temp->data==key)
{prev->next=temp->next;
delete temp;
}
else
{cout<<key<<" is not present in the list\n";
}}
cout<<"SLL after deletion is \n";
traverse_SLL();
}
if(ch==5)
{
node *temp;
node *cnode,*pnode,*nnode;
cnode=list;
pnode=NULL;
while(cnode!=NULL)
{
nnode=cnode->next;
cnode->next=pnode;
pnode=cnode;
cnode=nnode;
}
list=pnode;
cout<<"SLL after reversal is \n";
traverse_SLL();
}
cout<<"do you want to perform more operations Y or N ";
cin>>ans;
}while(ans=='Y'||ans=='y');
getch();
}















