#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include "mpi.h"

void main(int argc, char** argv)
{

double a,b,h,pi,x2,n;
double ssum=0,rsum=0;
int i,m; 
int count,sumcount;
int ierr,rank,size;

//begin parallel 
ierr = MPI_Init(&argc,&argv);

MPI_Comm comm = MPI_COMM_WORLD;

ierr = MPI_Comm_size(comm,&size);
ierr = MPI_Comm_rank(comm,&rank);

printf("Rank: %d Out of : %d \n",rank,size);

n= 10000;
m = n/size;
h = 1.0/n;


	for(i=(rank*m);i<(rank+1)*m;++i)
	{
	x2 = h*h*i*i;
	ssum += sqrt(1.0-x2);
	}

printf("Iam = %d and my ssum is: %f \n",rank,ssum);
printf("Iam = %d and this is my work: %d \n",rank,rank*m);

ierr = MPI_Reduce(&ssum,&rsum, 1, MPI_DOUBLE, MPI_SUM,0,comm);

ierr = MPI_Finalize();

if(rank == 0)
{
printf("Iam = %d and my rsum is: %f \n",rank,rsum);
pi = (h*rsum)*4.0;
printf("Pi: %f\n",pi);
}


}//end main
