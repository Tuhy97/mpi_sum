#include <iostream>
#include "mpi.h"
#include "mpi.h"
#include <math.h>
using namespace std;
double f(double);
double f(double x)
{
	return (4.0 / (1.0 + x * x));
}
int main(int argc, char* argv[])
{
	int done = 0, n, myid, numprocs, i;
	double PI25DT = 3.141592653589793238462643;
	double startwtime = 0.0, endwtime;
	int namelen;
	double pi;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Get_processor_name(processor_name, &namelen);
	fprintf(stdout, "Process %d of %d on %s\n", myid, numprocs, processor_name);
	n = 0;
		if(myid == 0) {
		printf("Please give N=");
		//scanf(&n);
		cin >> n;
		startwtime = MPI_Wtime();
	}
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	double h = 1.0 / (double)n;
	double sum = 0.0;
	for (i = myid + 1; i <= n; i += numprocs) {
		double x = h * ((double)i - 0.5);
		sum += f(x);
	}
	double mypi = h * sum;
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (myid == 0) {
		printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
		endwtime = MPI_Wtime();
		printf("wall clock time = %f\n", endwtime - startwtime);
		fflush(stdout);
	}
	MPI_Finalize();
}
	
