#include<iostream>
#include<stdio.h>
#include<mpi.h>
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char*** argv){
	
	MPI_Init(&argc,argv);
	  char name[MPI_MAX_PROCESSOR_NAME];
	  int len = 10;
	  int rank;
	  int size;
	MPI_Get_processor_name(name,&len);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	cout << "Hello World! "  <<name << " " << rank <<  endl;
	MPI_Finalize();
return 0;
}
