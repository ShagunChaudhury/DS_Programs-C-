#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void bubblesort(int a[],int n)
{
	int i=1;
	int swapped;
	do
	{
		swapped=0;
		for(int j=0;j<n-i;j++)
		{
			if(a[j+1]<a[j])
			{
			    //	int temp=a[j+1];
			    //	a[j+1]=a[j];
			    //	a[j]=temp;
				swap(a[j],a[j+1]);
				swapped=1;
			}
		}i++;
	}while(swapped==1);
}
void traverse(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
}
int pivot_list(int a[],int first,int last)
{
	int pvalue=a[first];
	int ppoint=first;
	for(int i=first+1;i<=last;i++)
	{
		if(a[i]<pvalue)
		{
			ppoint++;
		    //	int temp=a[ppoint];
		     //	a[ppoint]=a[i];
		      //	a[i]=a[ppoint];
		      swap(a[ppoint],a[i]);
		}
	}
	swap(a[first],a[ppoint]);
	return(ppoint);
}
int* quicksort(int a[],int first,int last)
{
	int pivot;
	if(first<last)
	{
		pivot=pivot_list(a,first,last);
		quicksort(a,first,pivot-1);
		quicksort(a,pivot+1,last);
	}
	return(a);
}
void insertion_sort(int a[],int n)
{
	int j,key,i;
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}
void merge(int a[],int s1,int e1,int s2,int e2)
{
	int i=0;
	int FS=s1;
	int FE=e2;
	int result[100],j;
	while(s1<=e1&&s2<=e2)
	{
		if(a[s1]<a[s2])
		{
			result[i]=a[s1];
			i++;
			s1++;
		}
		else
		{
			result[i]=a[s2];
			i++;
			s2++;
		}
	}
	if(s2>e2)
	{
		for(j=s1;j<=e1;j++)
		{
			result[i]=a[j];
			i++;
		}
	}
	if(s1>e1)
	{
		for(j=s2;j<=e2;j++)
		{
			result[i]=a[j];
			i++;
		}

	}
	int k=0;
	for(j=FS;j<=FE;j++)
	{
		a[j]=result[k];
		k++;
	}
}
void mergesort(int a[],int first,int last)
{
	int mid;
	if(first<last)
	{

		mid=(first+last)/2;
		mergesort(a,first,mid);
		mergesort(a,mid+1,last);
		merge(a,first,mid,mid+1,last);
	}
}
void max_heapify(int a[],int i,int n)
{
	int heapsize=n;
	int largest;
	int l=2*i+1;
	int r=(2*i)+2;
	if(l<heapsize&&a[l]>a[i])
	largest=l;
	else
	largest=i;
	if(r<heapsize&&a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(a,largest,n);
	}
}
void build_maxheap(int a[],int n)
{
	for(int i=n/2;i>=0;i--)
	{
		max_heapify(a,i,n);
	}
}
void heapsort(int a[],int n)
{
	build_maxheap(a,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(a[0],a[i]);
		n--;
		max_heapify(a,0,n);
	}
}
int main()
{
	int a[100],ch,n,i;
	char ans;
	do
	{
		cout<<"Enter the size of array : ";
		cin>>n;
		cout<<"Enter the array elements \n";
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<"1. Bubble sort \n";
		cout<<"2. Quick sort \n";
		cout<<"3. Insertion sort\n";
		cout<<"4. Merge sort \n";
		cout<<"5. Heap sort\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			bubblesort(a,n);
			traverse(a,n);
		}
		if(ch==2)
		{
			int f=0;
			int l=n-1;
			quicksort(a,f,l);
			traverse(a,n);
		}
		if(ch==3)
		{
			insertion_sort(a,n);
			traverse(a,n);
		}
		if(ch==4)
		{
			int f=0;
			int l=n-1;
			mergesort(a,f,l);
			traverse(a,n);
		}
		if(ch==5)
		{
			heapsort(a,n);
			traverse(a,n);
		}
		cout<<"do you want more operation Y or N : ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}
