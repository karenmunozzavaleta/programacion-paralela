#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>//no
using namespace std;

#define GetSize(array_enteros) (sizeof(array_enteros)/sizeof(*(array_enteros)))

int main(int argc, char **argv)
{
	
    int  rank, size; 
	int localMin=0;
	
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	int localArray[] = {15,24,30,12,23};
	
	for(int i =0 ; i <= GetSize(localArray) i = i + paso)
	{
	  if(	localArray[i]%2==0){
	  		localArray[i]=localArray[i]+6
	  }
	}

    MPI_Reduce(&localArray, &localMin, 1, MPI_DOUBLE,MPI_MAX, 0, MPI_COMM_WORLD);

      
        printf("Mínimo: %localMin ", localMin);
   

    MPI_Finalize();

    return 0;
}
