/*  Boss Code
Author : Joshua Ibirogba
Assignment #2 
What does the Program do : This function creates n workers by the boss program. 
Each of the worker created is assigned a range of prime numbers.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char **argv){
    if (argc >= 3){
        // atoi function casts the string input to integer
        int range = atoi(argv[2]);
        int workerNum = atoi(argv[1]);

        int step = range/workerNum;
        
        //range for worker 1
        int lo = 1;
        int hi = step;

        // creation of number of workers passed
        for (int i = 0; i < workerNum; i++){
            int status;
            int pid = fork(); //fork creates the child(worker) process

            if (pid == 0){
                char lo_s[10];
                char hi_s[10];

                // sprintf casts integer to string to be passed to the workers                
                sprintf(lo_s, " %d ", lo);
                sprintf(hi_s, " %d ", hi);

                execl("./worker", "./worker", lo_s, hi_s, (char *)NULL);
                printf(" low = %s , high = %s \n ", lo_s,hi_s);
                exit(-1);
            }
            // increment range for next worker
            lo = hi + 1;
            hi = hi + step;

            // remainder of prime numbers 
            if (i == (workerNum - 2)){
                hi = range;
            }
            printf(" \n ");
        }
    }
    else {
        printf(" Error, insufficient argument. \n ");    
    }
}