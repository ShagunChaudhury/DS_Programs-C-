#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{
clrscr();
int a[100],item,pos,i,n,ch,ans;
cout<<"enter the size of array \n";
cin>>n;
cout<<"enter the elements of the array \n ";
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"press 1 for traversal in array \n";
cout<<"press 2 for selection in array \n";
cout<<"press 3 for searching in array \n";
cout<<"press 4 for insertion in array \n";
cout<<"press 5 for deletion in array \n";
label:
cout<<"enter your choice from 1 to 5 \n";
cin>>ch;
switch(ch)
{
case 1:
for(i=0;i<n;i++)
{
cout<<a[i]<<"  ";
} cout<<endl;
break;
case 2:
cout<<"enter the position of the element to be selected \n";
cin>>pos;
cout<<"element at the given position is "<<a[pos-1]<<endl;
break;
case 3:
cout<<"enter the element to be searched in the array \n";
cin>>item;
for(i=0;i<n;i++)
{
if(a[i]==item)
{
cout<<"the element is at "<<i+1<<" position "<<endl;
break;
}
}
if(i==n)
cout<<"the element is not present in the array "<<endl;
break;
case 4:
cout<<"enter the element to be inserted \n";
cin>>item;
cout<<"enter the position at which it is to be inserted \n";
cin>>pos;
for(i=n-1;i>=pos-1;i--)
{
a[i+1]=a[i];}
a[pos-1]=item;
n=n+1;
cout<<"array after insertion is \n";
for(i=0;i<n;i++)
{
cout<<a[i]<<"  ";
}cout<<endl;
break;
case 5:
cout<<"enter the position of the element to be deleted \n";
cin>>pos;
for(i=pos-1;i<n-1;i++)
{a[i]=a[i+1];}
n=n-1;
cout<<"array after deletion operation is \n";
for(i=0;i<n;i++)
{cout<<a[i]<<"  ";
}cout<<endl;
break;
default:
cout<<"you have entered invalid choice"<<endl;
}
cout<<"do you want to perform more operations? press 1 for yes, press 2 for no \n";
cin>>ans;
switch(ans)
{
case 1:
goto label;
case 2:
exit(0);
}
getch();
}


































































