#include "mpi.h"
#include <stdlib.h>
#include <time.h>

//It works! Yay! 
// This one took me a while to realize that the Reduction needs to be called by every task
// Not just the root. My Program would just block and freeze!
int main(int argc,char*** argv){

int rank=1; int size=1; int ierr=-1; int data=-1;

ierr = MPI_Init(&argc,argv);
MPI_Comm comm = MPI_COMM_WORLD;
MPI_Status status;

ierr = MPI_Comm_rank(comm,&rank);
ierr = MPI_Comm_size(comm,&size);

srand(time(NULL) + rank);
double rando = rand();
double max = 0;

printf("iam = %d, my rando = %f \n",rank,rando);

ierr = MPI_Reduce(&rando,&max,1,MPI_DOUBLE, MPI_MAX,0,comm);
if (rank == 0)
printf("max rando found by root: %f \n",max);


ierr = MPI_Finalize();


}//end main
