#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
 

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
 

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    int root_rank = 0;

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 

    char all_values[4] = {0, 1, 3, 8};
    char my_value = all_values[my_rank];
    char reduction_result = 0;
    MPI_Reduce(&my_value, &reduction_result, 1, MPI_UNSIGNED_CHAR, MPI_BOR, root_rank, MPI_COMM_WORLD);
 
    if(my_rank == root_rank)
    {
        printf("The bit-wise or of all values is %d.\n", reduction_result);
    }
 
    MPI_Finalize();
 
    return EXIT_SUCCESS;
}
