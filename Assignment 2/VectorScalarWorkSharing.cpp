#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no of eleemnts in array: ";
	cin>>n;
	int a[n],b,c[n],i;
	
	for(i=0;i<n;i++)
	{
		a[i] = i;
	}
	cout<<"\nEnter scalar: ";
	cin>>b;
	
	
	
	#pragma omp parallel for firstprivate(a,b) num_threads(n/3)
	for(i=0;i<n;i++)
	{
		c[i] = a[i] + b;
		printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
	}
	
	printf("i\ta[i]\t+\t%d\t=\tc[i]\n",b);
    for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b, c[i]);
    }
	return 0;
}
