#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int rank,tamanio;
    int resultadoMax = -1;
    int conjuntoNumeros[6] = {1, 2, 4, 3, 7, 1};

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&tamanio);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    if (my_rank != 0) {
        MPI_Reduce(conjuntoNumeros, &resultadoMax, 6, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    } else {
        MPI_Reduce(conjuntoNumeros, &resultadoMax, 6, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD)
        cout<<"El máximo valor encontrado es: "<<resultadoMax;
    }

    return 0;
}
