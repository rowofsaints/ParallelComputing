#include "mpi.h"



//This doesn't run correctly, can't figure out the non-blocking 
// :(


int main(int argc,char*** argv){

int rank=1; int size=1; int ierr=-1; int data=-1;

ierr = MPI_Init(&argc,argv);
MPI_Comm comm = MPI_COMM_WORLD;
MPI_Status status;

ierr = MPI_Comm_rank(comm,&rank);
ierr = MPI_Comm_size(comm,&size);

int messages [size];
MPI_Request req2,req1,req3,req4;
MPI_Status stat1,stat2,stat3,stat4;

for(int i =0;i<size;i++) messages[i]=-1;

for(int i =0;i<size;i++)
	{
	if (rank==i) continue;

	if (rank< i) 
	{ierr = MPI_Isend(&rank, 1, MPI_INT, i, i*rank, comm, &req1);
	ierr = MPI_Irecv(&messages[i], 1, MPI_INT, i, i*rank, comm,&req2);
	ierr = MPI_Wait(&req1,&stat1);
	ierr = MPI_Wait(&req2,&stat2);
	continue;
	}
	if (rank >i) 
	{ierr = MPI_Irecv(&messages[i], 1, MPI_INT, i, i*rank, comm,&req3);
	ierr = MPI_Isend(&rank, 1, MPI_INT, i, i*rank, comm, &req4);
	ierr = MPI_Wait(&req3,&stat3);
	ierr = MPI_Wait(&req4,&stat4);
	continue;}

	}

	ierr = MPI_Wait(&req1,&stat1);

ierr = MPI_Finalize();

printf("iam = %d, received = %d \n", rank,messages[5]);

}//end main
