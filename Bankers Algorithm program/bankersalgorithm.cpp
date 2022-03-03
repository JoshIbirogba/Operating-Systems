/* Name: Joshua Ibirogba 
   Course Code: CS 3790
   Student ID: 5073203
   What Does this program do: This Program implements the banker's algorithm used to avoid deadlock and allocate resources safely to each process
*/

#include <stdio.h>


 
int main() {
    int curr[5][3];

    int max_init[5][3] = { 
                { 7, 5, 3 }, // P0 
                { 3, 2, 2 }, // P1
                { 9, 0, 2 }, // P2
                { 2, 2, 2 }, // P3
                { 4, 3, 3 }  // P4
                };
    int available[3];                  //
    int alloc[5][3] = { 
                    { 0, 1, 0 }, // P0 
                    { 2, 0, 0 }, // P1
                    { 3, 0, 2 }, // P2
                    { 2, 1, 1 }, // P3
                    { 0, 0, 2 }  // P4
                  };
    int max_result[3];
    int runningP[5];                  // no/count of process running
 
    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;
 
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);
 
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        runningP[i] = 1;
        count++;
    }

//Enter NEED
    printf("\n Enter NEED you want : ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_result[i]);


 //print resource demand/input
    printf("\n The Input Resource Demand is : ");
    for (i = 0; i < r; i++)
        printf("%d ", max_result[i]);


//print allocated resource table
    printf("\n -----Allocated Resource Table------\n");
    for (i = 0; i < p; i++) 
	{
        for (j = 0; j < r; j++)
            printf("%d", &curr[i][j]);
        printf("\n");
    }


//maximum table
    printf("\n -----Maximum Table----- \n");
    for (i = 0; i < p; i++) 
	{
        for (j = 0; j < r; j++)
            printf("%d ", max_init[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[i][j] += curr[i][j];


 // new allocated resources table
    printf("\n Allocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);
    for (i = 0; i < r; i++)
        available[i] = max_result[i] - alloc[i][j];
 
    printf("\n Available resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", &available[i]);
    printf("\n");
 

 //check if process(es) passes safety algorithm or not
    while (count != 0) 
	{
        safe = false;
        for (i = 0; i < p; i++)
		{
            if (runningP[i]) 
			{
                exec = 1;
                for (j = 0; j < r; j++) 
				{
                    if (max_init[i][j] - curr[i][j] > available[j]) 
					{
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) 
				{
                    printf("\n Process %d is executing.\n", i + 1);
                    runningP[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        available[j] += curr[i][j];
                    break;
                }
            }
        }
 
        if (!safe) 
		{
            printf("\n The processes are in unsafe state. \n");
            break;
        }
 
        if (safe)
            printf("\n The process is in safe state. \n");
 
//Update Available Resource
        printf("\n Available Resource: \n");
        for (i = 0; i < r; i++)
            printf("%d ", available[i]);
			printf("\n");
    }
 
    return 0;
}