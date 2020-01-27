#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
 
    bool valor = (my_rank == 2);
    bool resultado = false;
    MPI_Reduce(&valor, &resultado, 1, MPI_C_BOOL, MPI_LOR, root_rank, MPI_COMM_WORLD);
 
    if(my_rank == root_rank){
        cout<<"El valor logico total, de la operacion OR es: "<<resultado;
    }
 
    MPI_Finalize();
 
    return 0;
}
