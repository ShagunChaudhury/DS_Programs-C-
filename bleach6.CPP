#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,m,i,j,a[10][10],ca[10][10],ch,b[10][10],cb[10][10],c[10][10],r1,r2;
char ans;
do
{
cout<<"press 1 for coversion of sparse matrix in condensed form \n";
cout<<"press 2 for addition of two sparse matrices in condensed form \n";
cout<<"press 3 for transpose of sparse matrix \n";
cout<<"enter your choice \n";
cin>>ch;
cout<<"enter the no of rows and no of columns of sparse matrix \n";
cin>>n>>m;
cout<<"enter the elements of sparse matrix \n";
for(i=0;i<n;i++)
{for(j=0;j<m;j++)
{cin>>a[i][j];
}
}
ca[0][0]=n;
ca[0][1]=m;
int k=0;
for(i=0;i<n;i++)
{for(j=0;j<m;j++)
{if(a[i][j]!=0)
{k++;
ca[k][0]=i;
ca[k][1]=j;
ca[k][2]=a[i][j];
}}}
ca[0][2]=k;
r1=k+1;
if(ch==1)
{
cout<<"matrix in condensed form is \n";
for(i=0;i<r1;i++)
{for(j=0;j<3;j++)
{cout<<ca[i][j]<<" ";
}cout<<endl;
}}
else if(ch==2)
{cout<<"enter the no. of rows and columns of second matrix \n";
cin>>n>>m;
cout<<"enter elements of second sparse matrix \n";
for(i=0;i<n;i++)
{for(j=0;j<m;j++)
{cin>>b[i][j];
}}
cb[0][0]=n;
cb[0][1]=m;
int k2=0;
for(i=0;i<n;i++)
{for(j=0;j<m;j++)
{if(b[i][j]!=0)
{k2++;
cb[k2][0]=i;
cb[k2][1]=j;
cb[k2][2]=b[i][j];
}}}
cb[0][2]=k2;
r2=k2+1;
i=j=k=1;
while(i<r1&&j<r2)
{
if(ca[i][0]<cb[j][0])
{
c[k][0]=ca[i][0];
c[k][1]=ca[i][1];
c[k][2]=ca[i][2];
k++;i++;
}else if(ca[i][0]>cb[j][0])
{
c[k][0]=cb[j][0];
c[k][1]=cb[j][1];
c[k][2]=cb[j][2];
k++;j++;}
else if(ca[i][0]==cb[j][0])
{
if(ca[i][1]<cb[j][1])
{
c[k][0]=ca[i][0];
c[k][1]=ca[i][1];
c[k][2]=ca[i][2];
k++;
i++;
}else if(ca[i][1]>cb[j][1])
{
c[k][0]=cb[j][0];
c[k][1]=cb[j][1];
c[k][2]=cb[j][2];
k++;j++;
}
else if(ca[i][1]==cb[j][1])
{
c[k][0]=cb[j][0];
c[k][1]=cb[j][1];
c[k][2]=cb[j][2]+ca[i][2];
i++;
k++;j++;}}}
if(j==r2)
{
while(i<r1)
{
c[k][0]=ca[i][0];
c[k][1]=ca[i][1];
c[k][2]=ca[i][2];
k++;
i++;
}}
if(i==r1)
{
while(j<r2)
{
c[k][0]=cb[j][0];
c[k][1]=cb[j][1];
c[k][2]=cb[j][2];
k++;j++;
}}
c[0][0]=ca[0][0];
c[0][1]=ca[0][1];
c[0][2]=k-1;
cout<<"resultant matrix in condensed form is \n";
for(i=0;i<k;i++)
{for(j=0;j<3;j++)
{cout<<c[i][j]<<" ";
}cout<<endl;
}}
if(ch==3)
{
cout<<"matrix in condensed form is \n";
for(i=0;i<r1;i++)
{for(j=0;j<3;j++)
{cout<<ca[i][j]<<" ";
}cout<<endl;
}
for(i=0;i<r1;i++)
{
c[i][0]=ca[i][1];
c[i][1]=ca[i][0];
c[i][2]=ca[i][2];
}
int min1,pos;
for(i=1;i<r1-1;i++)
{
min1=c[i][0];
pos=i;
for(j=i+1;j<r1;j++)
{if(c[j][0]<min1)
{min1=c[j][0];
pos=j;
}}
int temp;
for(j=0;j<3;j++)
{temp=c[i][j];
c[i][j]=c[pos][j];
c[pos][j]=temp;
}}
for(i=1;i<r1-1;i++)
{
for(j=i+1;j<r1;j++)
{
if(c[i][0]==c[j][0])
{
if(c[i][1]>c[j][1])
{
int t;
t=c[i][1];
c[i][1]=c[j][1];
c[j][1]=t;
t=c[i][2];
c[i][2]=c[j][2];
c[j][2]=t;
}}}}
cout<<"transpose of given matrix in condensed form is \n";
for(i=0;i<r1;i++)
{for(j=0;j<3;j++)
{cout<<c[i][j]<<" ";
}cout<<endl;
}}
cout<<"do you want to perform more operations Y or N \n";
cin>>ans;
}
while(ans=='Y'||ans=='y');
getch();
}











































