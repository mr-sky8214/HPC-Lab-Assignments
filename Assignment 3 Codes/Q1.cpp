#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#include<bits/stdc++.h>
#define SEED 35791246
using namespace std;

main(int argc, char* argv)
{
	time_t start,end;
	time(&start);
	int niter=0;
	double x,y;
	int i,count=0; /* # of points in the 1st quadrant of unit circle */
	double z;
	double pi;
	printf("Enter the number of iterations used to estimate pi: ");
	scanf("%d",&niter);
	
	/* initialize random numbers */
	srand(SEED);
	count=0;
	#pragma omp parallel for reduction(+ : count)
	for ( i=0; i<niter; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x+y*y;
		if (z<=1) count++;
	}
	pi=(double)count/niter*4;
	time(&end);
	double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(3);
    cout << " sec " << endl;
	printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
}

