#include <thread>
#include <cstdio>
#include <cmath>
#include <cstdlib>

 int ThreadProc (void* voidThreadParam  );

int prime[5000] = {0} ;
int division = 0;
int Thread;


void main( int argc, char **argv)
{
	if (argc > 1) 
	{
		int low = atoi( argv[1]);
		int Thread = atoi( argv[2]);
	}

	if((N < prime) && (Thread < N))
	{

		int previousCounter = 1;	
		int sqrRoot = sqrt((double)low);
		division = sqrRoot/nThreads + 1;	
		
		
		//print the prime numbers
		printf("Prime Values are:\n");
		for(int i = 2 ; i <= low; i++)
		{
			if(prime[i] == 0)
			{
				printf("%d\t",i);
			}
		}


//Thread Routine
int ThreadOne ( void* Count ) 
{
	int x = (*(int*)Count);
	for(int i = x; i <= (x + division); i++)
	{
		if(prime[i] == 0)
		{
			for(int j = i * i ; j <= N ; j+=i)
			{
				prime[j] = 1;
			}
		}
	}
	return 0;
}