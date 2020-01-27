#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {

    int rank, size;
    const int locn=5;
    int localArr[locn];
    
	int localRes[2];
    int globalRes[2];
    localRes[0] = localArr[0];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(rank);
    for (int i=0; i<locn; i++) 
        localArr[i] = rand() % 100;

    for (int proc=0; proc<size; proc++) {
        if (rank == proc) {
            printf("Rangos %2d has values: ",rank);
            for (int i=0; i<locn; i++)
                printf(" %d ", localArr[i]);
            printf("\n");
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }


    for (int i=1; i<locn; i++) 
        if (localArr[i] < localRes[0]) localRes[0] = localArr[i];

    localres[1] = rank;

    MPI_Allreduce(localRes, globalRes, 1, MPI_2INT, MPI_MINLOC, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Rango: %d tiene el más bajo valor  %d\n", globalRes[1], globalRes[0]);
    }

    MPI_Finalize();

    return 0;
}
