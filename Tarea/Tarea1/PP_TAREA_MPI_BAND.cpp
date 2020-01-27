#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
 using namespace std;
 
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
 
    
    int size,rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtener cpus
    
    if(size != 4)
    {
        printf("Solo se puede ejecutar con 4 procesos");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE); //Finalizar
    }
   	
    int rootRank = 0;
 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 
    char local[4] = {0, 1, 3, 8};
    char localFinal= local[rank];
    char resultadoRed = 0;
    MPI_Reduce(&localFinal, &resultadoRed, 1, MPI_UNSIGNED_CHAR, MPI_BAND, rootRank, MPI_COMM_WORLD);
 
    if(my_rank == root_rank)
    {
        printf("bit-wise es:  %d.\n", reduction_result);
    }
 
    MPI_Finalize();
 
    return EXIT_SUCCESS;
}
