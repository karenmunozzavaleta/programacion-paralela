#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <iostream>

using namespace std;
 
int main(int argc, char* argv[])
{
    // Raiz del proceso
    int root_rank = 0;
 	MPI_Init(&argc, &argv);
 	
    // Obtener el tamaño de la comunicacion
    int tamanio = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &tamanio);
 
   // Obtener el proceso
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 
    int resultado = 0;
    MPI_Reduce(&my_rank, &resultado, 1, MPI_INT, MPI_MAXLOC, root_rank, MPI_COMM_WORLD);
 
    if(my_rank == root_rank){
        cout<<"El valor max local es: "<<resultado;
    }
 
    MPI_Finalize();
 
    return 0;
}
