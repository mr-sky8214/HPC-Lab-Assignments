%%cu
#include <bits/stdc++.h>
using namespace std;

__device__ int getFactorial(int n)
{
    if(n == 0 || n == 1)
      return n;
    return n * getFactorial(n-1);
}

__global__ void factorial(int *n, int * res)
{
    *res = getFactorial(*n);
}
int main()
{
	int host_n , host_res;
  int *devc_n, *devc_res;
  host_n = 10;
  cudaMalloc(&devc_n, sizeof(int));
  cudaMalloc(&devc_res, sizeof(int));
 
  cudaMemcpy(devc_n, &host_n, sizeof(int), cudaMemcpyHostToDevice);
 
  factorial<<<1,1>>>(devc_n, devc_res);
 
  cudaMemcpy(&host_res, devc_res,sizeof(int), cudaMemcpyDeviceToHost);
  
  cout<<"Factorial of "<<host_n<<" is "<<host_res;
 
  cudaFree(devc_n);
  cudaFree(devc_res);
	return 0;
}
