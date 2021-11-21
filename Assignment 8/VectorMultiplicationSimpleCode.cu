%%cu
#include<bits/stdc++.h>
using namespace std;

const int r1 = 20, c1 = 30, r2 = 30, c2 = 20;

__global__ void mulMatrix(int *a, int * b, int *c)
{
    int x = blockIdx.x;
    int y = blockIdx.y;
 
    int id_c = c2 * y + x;

    c[id_c] = 0;
    for(int k = 0 ; k < c1; k++)
    {
        int id_a = c1 * y + k;
        int id_b = c2 * k + x;
        c[id_c] = c[id_c] + a[id_a] * b[id_b];
    }
}


int main()
{
    int host_a[r1][c1] , host_b[r2][c2], host_c[r1][c2];
    int *devc_a, *devc_b, *devc_c;
 
    cudaMalloc(&devc_a, r1 * c1 * sizeof(int));
    cudaMalloc(&devc_b, r2 * c2 * sizeof(int));
    cudaMalloc(&devc_c, r1 * c2 * sizeof(int));
 
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
          host_a[i][j] = i + j + 1;
    }
 
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
          host_b[i][j] = (i + 1) * (j + 1);
    }
 
    cudaMemcpy(devc_a, host_a, r1 * c1 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(devc_b, host_b, r2 * c2 * sizeof(int), cudaMemcpyHostToDevice);
 
    dim3 grid(c2,r1);

    mulMatrix<<<grid, 1>>>(devc_a, devc_b, devc_c);

    cudaMemcpy(host_c, devc_c, r1 * c2 * sizeof(int), cudaMemcpyDeviceToHost);
 
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
          cout<<host_c[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}