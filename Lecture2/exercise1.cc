#include "mpi.h"


int main(int argc,char*** argv){

int rank=1; int size=1; int ierr=-1; int data=-1;

ierr = MPI_Init(&argc,argv);
MPI_Comm comm = MPI_COMM_WORLD;
MPI_Status status;

ierr = MPI_Comm_rank(comm,&rank);
ierr = MPI_Comm_size(comm,&size);


if(rank == 0) { ierr = MPI_Send(&rank, 1, MPI_INT, 1, 9, comm);
		ierr = MPI_Recv(&data, 1, MPI_INT, 1, 9, comm,&status);
	      }

if(rank == 1) {		
		ierr = MPI_Recv(&data, 1, MPI_INT, 0, 9, comm, &status);
		ierr = MPI_Send(&rank, 1, MPI_INT, 0, 9, comm);
	      }


ierr = MPI_Finalize();

printf("iam = %d, received = %d \n", rank,data);

}//end main
