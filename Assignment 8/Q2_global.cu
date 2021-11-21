%%cu
#include<bits/stdc++.h>
using namespace std;

__device__ int global_arr[10];

__device__ void initialize(int i)
{
    global_arr[i] = i + 1;
}

__global__ void getArr(int *a)
{
    int idx = threadIdx.x;
    initialize(idx);
    a[idx] = global_arr[idx];
}

int main()
{
    int *a = new int[10], *devc_a;
    cudaMalloc(&devc_a, 10 * sizeof(int));
    getArr<<<1,10>>>(devc_a);
    cudaMemcpy(a, devc_a, 10 * sizeof(int), cudaMemcpyDeviceToHost);
 
    cout<<"Copied array: ";
    for(int i=0;i<10;i++)
      cout<<a[i]<<" ";

    cudaFree(devc_a);
    delete(a);
    return 0;
}
