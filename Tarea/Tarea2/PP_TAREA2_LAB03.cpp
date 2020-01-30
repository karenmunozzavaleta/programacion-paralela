#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <iostream>
#include <time.h>

using namespace std;
//Declaracion
int[] getArrRandomData(int size);
int[] getArrPartitionOfRanks(int[] arr, int initial, int end);
int[] sumArrays(int[] arr1, int[] arr2, int size);

int main(int argc, char* argv[])
{	int size;
	int root_rank = 0;
    int arr1[100],arr2[100], arrAux1[100/size], arrAux2[100/size], arrResul[100];

	MPI_Init(&argc, &argv);
    
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(size%100!=0){
    	cout<<"El numero de procesos es diferente de multiplo de 100."<<endl;
    	return EXIT_SUCCESS;
	}

 	
	int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 	
 	if(my_rank==root_rank){
 		arr1 = getArrRandomData(100);
 		arr2 = getArrRandomData(100);
 		arrAux1 = getArrRandomData(arrAux1);
 		arrAux2 = getArrRandomData(arrAux2);
 		
 		MPI_Send(&arrAux1, 100/size, MPI_INT, 1, 0, MPI_COMM_WORLD);
 		MPI_Send(&arrAux2, 100/size, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else{
		
		MPI_Recv(&arrAux1, 100/size, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
		MPI_Recv(&arrAux2, 100/size, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
        arrResul = sumArrays(arrAux1,arrAux2,100/size);
        printArray(arrResul,100/size);
	}
    MPI_Finalize();
 
    return EXIT_SUCCESS;
}

int[] getArrRandomData(int size){
	int num, i;
	int array[size];
	
    for(i = 0; i < size; i++){
    	num = 1 + rand() % (9 - 1);
        array[i] = num;
    }
    return array;
}

int[] getArrPartitionOfRanks(int[] arr, int initial, int end) {
	int i, array[end-initial];
	for(i = initial; i < end; i++){
    	array[i] = arr[i];
    }
    return array;
}

int[] sumArrays(int[] arr1, int[] arr2, int size) {
	int i, arrResul[size];
	for(i = 0; i < size; i++){
    	arrResul[i] = arr1[i] + arr2[i];
    }
    return arrResul;
}

void printArray(int[] arr, int size){
	int i;
	cout<<"Vector";
	for(i = 0; i < size; i++){
    	cout<<arr[i]<<" - ";
    }
    cout<<endl;
}
