#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no of eleemnts in array: ";
	cin>>n;
	int a[n],b[n],c[n],i;
	
	for(i=0;i<n;i++)
	{
		a[i] = i;
		b[i] = i + 200;
	}
	
	
	
	#pragma omp parallel for shared(a,b,c) num_threads(n/3)
	for(i=0;i<n;i++)
	{
		c[i] = a[i] + b[i];
		printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
	}
	
	printf("i\ta[i]\t+\tb\t=\tc[i]\n",b);
    for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
    }
	return 0;
}
