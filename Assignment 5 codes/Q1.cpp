#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc, char** argv)
{
	int rank, size, n, src, dest, tag;
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (size != 4)
	{
		printf("Number of processors must be 4\n");
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	switch (rank)
	{
		case 0:
			n = 25;
			dest = 1;
			tag = 200;
			MPI_Send(&n, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
			// printf("Processor %d has sent number %d to processor %d ", rank, n, dest);
			break;

		case 1:
			src = 0;
			tag = 200;
			MPI_Recv(&n, 1, MPI_INT, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Processor %d has received number %d from processor %d ", rank, n, src);
			break;

		case 2:
			n = 100;
			dest = 3;
			tag = 0;
			MPI_Send(&n, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
			//printf("Processor %d has sent number %d to processor %d ", rank, n, dest);
			break;

		case 3:
			src = 2;
			tag = 0;
			MPI_Recv(&n, 1, MPI_INT, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Processor %d has received number %d from processor %d ", rank, n, src);
			break;
	}


	MPI_Finalize();
	return 0;
}
