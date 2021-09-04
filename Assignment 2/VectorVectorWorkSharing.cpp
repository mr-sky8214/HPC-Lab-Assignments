#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

void input(int a[], int n,int no)
{
	system("cls");
	cout<<"========Enter array "<<no<<"========\n";
	for(int i=0;i<n;i++)
	{
		cout<<i<<" element: ";
		cin>>a[i];
		cout<<endl;
	}
}

void display(int a[],int b[],int c[],int n)
{
//	system("cls");
	cout<<"========Addition========\na[i]\tb[i]\t=\tc[i]\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t"<<b[i]<<"\t=\t"<<c[i];
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter no of eleemnts in array: ";
	cin>>n;
	int a[n],b[n],c[n],i;
	
	for(i=0;i<n;i++)
	{
		a[i] = i;
		b[i] = i + 100;
	}
	
	#pragma omp parallel for firstprivate(a,b) shared(c) num_threads(n/2)
	for(i=0;i<n;i++)
	{
		c[i] = a[i] + b[i];
		printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
	}
	
	display(a,b,c,n);
	return 0;
}
