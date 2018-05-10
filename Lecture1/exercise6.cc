//Exercise 6 
////Finding if the Number N=2,000,000,111 prime
//

#include "mpi.h"

int main(int argc,char*** argv){

int rank; int size; int ierr; int N = 2000000111;
//bool isPrime=true;

ierr = MPI_Init(&argc,argv);
MPI_Comm comm = MPI_COMM_WORLD;
MPI_Status status;

ierr = MPI_Comm_rank(comm,&rank);
ierr = MPI_Comm_size(comm,&size);

int range = 45200/size;

for(int i = 1; i <= range ; i++)
{

	if (N%(i*rank) == 0) 
		{
		//isPrime = false;
		printf("N has a factor!\n");
		break;
		}
}


/*
if (isPrime == false)
	{printf("CPU %d: Not Prime \n",rank);}
else
	{printf("CPU %d: Prime \n", rank);}

isPrime = true;
*/

ierr = MPI_Finalize();


}//end main
