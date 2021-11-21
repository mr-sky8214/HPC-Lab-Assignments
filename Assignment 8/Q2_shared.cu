%%cu
#include<bits/stdc++.h>
using namespace std;

__global__ void sum_vect(int *a, int *b,int n)
{
    __shared__ int arr[10];
    int k = threadIdx.x;
    arr[k] = a[k];
    __syncthreads();
 
    int sum = 0;
    for(int i=0;i<n;i++)
      sum += arr[k];
    *b = sum / n;
}

int main()
{
    int *a = new int[10];
    int *b = new int(0);
 
    for(int i=0;i<10;i++)
      a[i] = (i+1);

    int *devc_a, *devc_b;

    cudaMalloc(&devc_a, 10 * sizeof(int));
    cudaMalloc(&devc_b, sizeof(int));
 
    cudaMemcpy(devc_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(devc_b, b, sizeof(int), cudaMemcpyHostToDevice);
 
    sum_vect<<<1,10>>>(devc_a,devc_b,10);

    cudaMemcpy(b, devc_b,sizeof(int), cudaMemcpyDeviceToHost);
 
    cout<<"Average: "<<*b;
 
    cudaFree(devc_a);
    cudaFree(devc_b);
    delete(a);
    delete(b);
    return 0;
}