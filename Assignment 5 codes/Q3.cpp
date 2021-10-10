#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc, char** argv)
{
	int rank, size, sum = 0;
	int arr[] = { 34, 78, 28, -45, 98, 14 , -5, 35, 20, 85, 83, -42};
	int n = sizeof(arr) / sizeof(arr[0]);

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	int tmp_n = ceil(n * 1.0 / size);
	int start = rank * tmp_n, end = min(n, (rank + 1) * tmp_n);
	int tmp_sum = 0;
	for (int i = start; i < end; i++)
		tmp_sum += arr[i];

	cout << "Sum by process "<< rank <<" from " << start << " to " << end-1 << " is " << tmp_sum << endl;
	MPI_Reduce(&tmp_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		cout << endl << endl << "===========================================" << endl;
		cout << "Final Sum is " << sum << "\n===========================================" << endl;;
	}
	
	MPI_Finalize();


	return 0;
}