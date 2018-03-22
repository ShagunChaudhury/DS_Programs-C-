#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int ch,n,location;
	int count=0;
	int ch1=0;
	char ans,c,line;
	ifstream inf;
	inf.open("anjali.txt");
	inf.get(line);
	while(!inf.eof())
	{
		cout<<line;
		inf.get(line);
	}
	inf.close();
//	inf.seekg(0);
	do
	{
	cout<<"\nEnter 1 to delete a line from the file\n";
	cout<<"Enter 2 to count the number of lines in the file\n";
	cout<<"Enter 3 to append the content of file 1 to the end of file 2\n";
	cout<<"Enter 4 to copy the contents of given file to another file\n";
	cout<<"Enter your choice : ";
	cin>>ch;
	if(ch==1)
	{
		cout<<"Enter the number of the line to be deleted : ";
		cin>>n;
		ifstream fin;
		fin.open("anjali.txt");
		ofstream fout;
		fout.open("newfile.txt");
		fin.get(c);
		while(ch1!=n-1&&fin.eof()==0)
		{
			if(c=='.')
			{
				ch1++;
			}
			fout<<c;
			fin.get(c);
		}
		fin.get(c);
		while(fin.eof()==0)
		{
			if(c=='.')
			break;
			fin.get(c);
		}
		fin.get(c);
		while(!fin.eof())
		{
			fout<<c;
			fin.get(c);
		}
		fin.close();
		fout.close();
		ifstream fin2;
		fin2.open("newfile.txt");
		cout<<"Now reading contents of modified file \n";
		fin2.get(c);
		while(!fin2.eof())
		{
			cout<<c;
			fin2.get(c);
		}
		fin2.close();
	}
	if(ch==2)
	{
		ifstream fin3;
		fin3.open("anjali.txt");
		fin3.get(line);
		while(!fin3.eof())
		{
			if(line=='.')
			count++;
			fin3.get(line);
		}
		cout<<"Total number of lines is "<<count;
		fin3.close();
	}
	if(ch==3)
	{
		ofstream fout1;
		ifstream fin1;
		fout1.open("intro.txt",ios::app);
		fout1<<"\n";
		fin1.open("anjali.txt");
		fin1.get(c);
		while(!fin1.eof())
		{
			fout1<<c;
			fin1.get(c);
		}
		fin1.close();
		fout1.close();
		ifstream fin2;
		cout<<"Contents of appended file are \n";
		fin2.open("intro.txt");
		fin2.get(line);
		while(!fin2.eof())
		{
			cout<<line;
			fin2.get(line);
		}
	}
	if(ch==4)
	{
		inf.open("anjali.txt");
		ofstream fout;
		fout.open("file.txt");
		inf.get(line);
		while(!inf.eof())
		{
			fout<<line;
			inf.get(line);
		}
		inf.close();
		fout.close();
	    ifstream fin4;
		cout<<"Now reading contents from temperory file \n";
		fin4.open("file.txt");
		fin4.get(c);
		while(!fin4.eof())
		{
			cout<<c;
			fin4.get(c);
		}
		fin4.close();
	}
	cout<<"Do you want to perform more operations Y or N : ";
	cin>>ans;
	}
	while(ans=='Y'||ans=='y');
	return 0;
}
