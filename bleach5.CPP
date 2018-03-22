#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a[10][10],b[10][10],c[20][20],i,j,r1,r2,c1,c2,ch;
char ans;
do
{
cout<<"enter 1 for addition of two matrices \n";
cout<<"enter 2 for subtraction of two matrices \n";
cout<<"enter 3 for multiplication of two arrays \n";
cout<<"enter 4 for performing transpose operation on a matrice \n";
cout<<"enter your choice ";
cin>>ch;
if(ch==1)
{
cout<<"enter no of rows and columns of the matrices \n";
cin>>r1>>c1;
cout<<"enter elements of first matrix \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cin>>a[i][j];
}}
cout<<"enter elements of second matrix \n";
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{
cin>>b[i][j];
}}
cout<<"sum of the two matrices is \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
c[i][j]=a[i][j]+b[i][j];
cout<<c[i][j]<<" ";
}cout<<endl;
}}
if(ch==2)
{
cout<<"enter no of rows and columns of the matrices \n";
cin>>r1>>c1;
cout<<"enter elements of first matrix \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cin>>a[i][j];
}}
cout<<"enter elements of second matrix \n";
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{
cin>>b[i][j];
}}
cout<<"difference of the two matrices is \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
c[i][j]=a[i][j]-b[i][j];
cout<<c[i][j]<<" ";
}cout<<endl;
}}
if(ch==3)
{
cout<<"enter the no of rows and columns of first matrix \n";
cin>>r1>>c1;
cout<<"enter no of rows and columns of second matrix \n";
cin>>r2>>c2;
if(c1!=r2)
{cout<<"matrix multiplication is not possible \n";
break;
}else
cout<<"enter elements of first matrix \n";
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{
cin>>a[i][j];
}}
cout<<"enter elements of second matrix \n";
for(i=0;i<r2;i++)
{for(j=0;j<c2;j++)
{
cin>>b[i][j];
}}
for(i=0;i<r1;i++)
{for(j=0;j<c2;j++)
{c[i][j]=0;
for(int k=0;k<c1;k++)
{c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
cout<<c[i][j]<<" ";
}
cout<<endl;
}}
if(ch==4)
{
cout<<"enter the no of rows and columns of the matrix \n";
cin>>r1>>c1;
cout<<"enter the elements of the matrix \n";
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{
cin>>a[i][j];
}}
for(i=0;i<r1;i++)
{for(j=0;j<c1;j++)
{
c[i][j]=a[j][i];
}}
cout<<"the transposed matrix is \n";
for(i=0;i<c1;i++)
{for(j=0;j<r1;j++)
{c[i][j]=a[j][i];
cout<<c[i][j]<<" ";
}cout<<endl;
}}
cout<<"do you want to perform more operations \n";
cin>>ans;
}while(ans=='Y'||ans=='y');
getch();
}













































