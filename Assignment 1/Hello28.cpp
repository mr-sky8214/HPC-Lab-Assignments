#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	#pragma omp parallel num_threads(10)
	{
		cout<<"\nHello from PRN 2018BTECS00028 with thread "<<omp_get_thread_num();
	}
	return 0;
}
