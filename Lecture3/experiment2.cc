#include "mpi.h"

//It Works! Yay!
int main(int argc,char*** argv){

int rank=1; int size=1; int ierr=-1; int data=-1;

ierr = MPI_Init(&argc,argv);
MPI_Comm comm = MPI_COMM_WORLD;
MPI_Status status;

ierr = MPI_Comm_rank(comm,&rank);
ierr = MPI_Comm_size(comm,&size);

int messages [size];
for(int i =0;i<size;i++) messages[i]=rank;

for(int i =0;i<size;i++)
	{
	if (rank==i) continue;

	if (rank< i) 
	{ierr = MPI_Send(&rank, 1, MPI_INT, i, i*rank, comm);
	ierr = MPI_Recv(&messages[i], 1, MPI_INT, i, i*rank, comm,&status);}

	if (rank >i) 
	{ierr = MPI_Recv(&messages[i], 1, MPI_INT, i, i*rank, comm,&status);
	ierr = MPI_Send(&rank, 1, MPI_INT, i, i*rank, comm);}
	}

ierr = MPI_Finalize();

//printf("iam = %d, received = %d \n", rank,messages[10]);

}//end main
