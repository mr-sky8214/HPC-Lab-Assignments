#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int bcast_val;

    int buff[10];

    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
        bcast_val = 10;

    MPI_Bcast(&bcast_val, 1, MPI_INT, 0, MPI_COMM_WORLD);
   
    printf("Process %d is having data %d after broadcast\n", rank, bcast_val);

    MPI_Finalize();
}