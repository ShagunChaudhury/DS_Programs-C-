#include<iostream.h>
#include<conio.h>
int maxsize;
int front=0;
int rear=-1;
void enqueue(int q[],int item)
{
	if(rear==maxsize-1)
	{
		cout<<"Queue is full \n";
	}
	else
	{
		rear=rear+1;
		q[rear]=item;
	}
}
int dequeue(int q[])
{
	 int item;
	 if(front==rear+1)
	 {
		cout<<"queue is empty \n";
		return(0);
	 }
	 else
	 {
		item=q[front];
		front=front+1;
		return(item);
	 }
}
void traverse(int q[])
{
	int i;
	for(i=front;i<=rear;i++)
	{
		cout<<q[i]<<"  ";
	}
}
void main()
{
	clrscr();
	int y,c,item,q[100];
	char ans;
	cout<<"Enter size of Queue\n";
	cin>>maxsize;
	do
	{
		cout<<"Enter 1 to insert an element in queue\n";
		cout<<"Enter 2 to delete an element from queue\n";
		cout<<"Enter 3 to display queue\n";
		cout<<"enter your choice : ";
		cin>>c;
		if(c==1)
		{
			cout<<"Enter the element to be inserted : ";
			cin>>item;
			enqueue(q,item);
			cout<<"Updated queue is \n";
			traverse(q);

		}
		if(c==2)
		{
			y=dequeue(q);
			if(y==0)
			{
			cout<<"No element is deleted ";
			}
			else
			cout<<"The deleted element is "<<y;
		}
		if(c==3)
		{
			cout<<"The entered queue is \n";
			traverse(q);
		}
		cout<<"\nDo you want to perform more operations Y or N : ";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	getch();
}