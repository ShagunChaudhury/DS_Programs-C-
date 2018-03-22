#include<iostream.h>
#include<conio.h>
struct node
{
	int data;
	node *next;
};
node *rear;
node *front=rear->next;
void enqueue(int item)
{
	node *temp;
	temp=new node;
	temp->data=item;
	temp->next=NULL;
	if(front==NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=rear->next;
	}
}
int dequeue()
{
	node *temp;
	int item;
	if(front==NULL&&rear==NULL)
	{
		return(0);
	}
	else if(front==rear)
	{
		temp=front;
		item=temp->data;
		front=rear=NULL;
		delete temp;
	}
	else
	{
		temp=front;
		item=temp->data;
		front=front->next;
		delete temp;
	}
	return(item);
}
void display()
{
	node *temp;
	temp=front;
	if(front==NULL)
	cout<<"Empty queue \n";
	else
	cout<<"Entered queue is \n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
void main()
{
	clrscr();
	int ch,n,y;
	char ans;
	do
	{
		cout<<"Enter 1 to insert an element in queue \n";
		cout<<"Enter 2 to delete an element from queue\n";
		cout<<"Enter 3 to display queue\n";
		cout<<"Enter your choice \n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the element to be inserted : ";
			cin>>n;
			enqueue(n);
		   //	cout<<"Updated queue is \n";
			display();
		}
		if(ch==2)
		{
			y=dequeue();
			if(y==0)
			cout<<"Underflow!! No element deleted \n";
			else
			{
				cout<<"The deleted item is "<<y<<endl;
			}
		}
		if(ch==3)
		{
		     //	cout<<"Entered queue is \n";
			display();
		}
		cout<<"\nDo you want to perform more operations Y or N : ";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	getch();
}

