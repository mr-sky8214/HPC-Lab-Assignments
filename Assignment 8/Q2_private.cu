%%cu
#include<bits/stdc++.h>
using namespace std;

__global__ void swap_nums(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int *a = new int(5);
    int *b = new int(10);
 
     cout<<"Before swapping "<<*a<<" "<<*b<<endl;
    int *devc_a, *devc_b;

    cudaMalloc(&devc_a, sizeof(int));
    cudaMalloc(&devc_b, sizeof(int));
 
    cudaMemcpy(devc_a, a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(devc_b, b, sizeof(int), cudaMemcpyHostToDevice);
 
    swap_nums<<<1,1>>>(devc_a,devc_b);

    cudaMemcpy(a, devc_a,sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(b, devc_b,sizeof(int), cudaMemcpyDeviceToHost);
 
    cout<<"After swapping "<<*a<<" "<<*b;
 
    cudaFree(devc_a);
    cudaFree(devc_b);
    delete(a);
    delete(b);
    
    return 0;
}