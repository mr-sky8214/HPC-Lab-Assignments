#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);
	printf("Hello World\n");
	MPI_Finalize();
	return 0;
}