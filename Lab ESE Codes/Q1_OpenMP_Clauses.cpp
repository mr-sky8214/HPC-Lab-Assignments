#include <omp.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"\n**************** reduction Cluase ***********************\n";
	int sum = 0;
	
	#pragma omp parallel for shared(arr) reduction(+: sum)
	for(int i = 0;i < n;i++) {
		sum += arr[i];
	}
	
	cout<<"Sum by OpenMP reduction: "<<sum<<endl;
	
	cout<<"\n**************** Critical Cluase ***********************\n";
	
	sum = 0;
	
	#pragma omp parallel shared(arr, sum) num_threads(n)
	{
		int tid = omp_get_thread_num();
		#pragma omp critical
			sum += arr[tid];
	}
	
	cout<<"Sum by OpenMP critical: "<<sum<<endl;
	
	cout<<"\n**************** Master Cluase ***********************\n";
	#pragma omp parallel num_threads(n/2)
	{
		int tid = omp_get_thread_num();
		cout<<"Thread " <<tid<<" can execute this"<<endl;
		
		#pragma omp master
			cout<<"Only master thread " <<tid<<"can execute this"<<endl;
	}
}
