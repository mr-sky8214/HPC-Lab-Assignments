%%cu
#include<bits/stdc++.h>
using namespace std;

__global__ void addVectors(int *a, int *b, int *c)
{
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    c[id] = a[id] + b[id];
}

int main()
{
    int n = 1e5, i = 0;
    int *host_a, *host_b, *host_c;
    int *devc_a, *devc_b, *devc_c;
 
    host_a = (int *)malloc(n * sizeof(int));
    host_b = (int *)malloc(n * sizeof(int));
    host_c = (int *)malloc(n * sizeof(int));
 
    cudaMalloc(&devc_a, n * sizeof(int));
    cudaMalloc(&devc_b, n * sizeof(int));
    cudaMalloc(&devc_c, n * sizeof(int));
 
    for(i = 0; i < n; i++)
    {
        host_a[i] = i;
        host_b[i] = log(i)/log(2);
    }
 
    cudaMemcpy(devc_a, host_a, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(devc_b, host_b, n * sizeof(int), cudaMemcpyHostToDevice);
 
    int blocks = 1000, threads;
    threads = n / blocks;

    addVectors<<<blocks,threads>>>(devc_a,devc_b,devc_c);
 
    cudaMemcpy(host_c, devc_c, n * sizeof(int), cudaMemcpyDeviceToHost);
  
    for(i = 0; i < n; i++)
    {
        cout<<host_a[i]<<" + "<<host_b[i]<<" = "<<host_c[i]<<endl;
    }
 
    cudaFree(devc_a);
    cudaFree(devc_b);
    cudaFree(devc_c);
 
    free(host_a);
    free(host_b);
    free(host_c);
 
    return 0;
}

