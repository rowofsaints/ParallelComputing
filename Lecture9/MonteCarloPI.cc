#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include "mpi.h"

void main(int argc, char** argv)
{

double x,y,z,pi;
int i,n,m; 
int count,sumcount;
int ierr,rank,size;

//begin parallel 
ierr = MPI_Init(&argc,&argv);

MPI_Comm comm = MPI_COMM_WORLD;

ierr = MPI_Comm_size(comm,&size);
ierr = MPI_Comm_rank(comm,&rank);

	
printf("Rank: %d Out of : %d \n",rank,size);

n= 1000000;count = 0;
m = n/size;

srand((int)(rank*(double)RAND_MAX/size));

	for(i=0;i<m;++i)
	{
		x = (double)random()/RAND_MAX;
		y = (double)random()/RAND_MAX;
		z = sqrt((x*x) + (y*y));
		if(z<=1)
		{
		   ++count;
		}
	}

ierr = MPI_Reduce(&count,&sumcount, 1, MPI_INTEGER, MPI_SUM,0,comm);

if(rank ==0)
{
pi = ((double)sumcount/n)*4.0;
printf("Pi: %f\n",pi);
}

ierr = MPI_Finalize();

}//end main
