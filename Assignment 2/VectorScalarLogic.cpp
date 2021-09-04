#include <omp.h>
#include <stdio.h>
#include<stdlib.h>
#define n 8


int main() {

    int *a, *c;
    int *flag;
    a=(int*)malloc(n*sizeof(int));
    c=(int*)malloc(n*sizeof(int));
    flag=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
    	a[i]=i;
    	flag[i]=0;
	}
	int x=5;
	omp_set_num_threads(3);
	#pragma omp parallel shared(c)
	for(int i = 0;i < n;i++) {
		if(!flag[i])
		{
			c[i]=a[i]+x;
			flag[i]=1;
			printf("\nThread number %d, executing iteration %d first time",omp_get_thread_num(),i);	

		}
		else
		{
			printf("\nThread number %d, executing iteration %d already computed",omp_get_thread_num(),i);	
		}
	
	}
	
		printf("\ni\ta[i]\t+x\t=\tb[i]\n");
        for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t=\t%d\n", i, a[i],x,c[i]);
        }
	
}
