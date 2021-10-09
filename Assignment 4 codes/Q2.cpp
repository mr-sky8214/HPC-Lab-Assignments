#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc, char** argv)
{
	int rank, communicator_group;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &communicator_group);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	printf("Output of %d communicator group with %d rank\n",communicator_group,rank);

	MPI_Finalize();
	return 0;
}