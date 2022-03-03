/*  Worker Code
Author : Joshua Ibirogba
Assignment #2 
What does the program do : This program takes two strings as input, then casts the strings into integers, when this is done, 
the program finds all prime numbers in the range of the inputs, the initial input is the minimum limit while the 
latter input is the maximum limit.
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

    // convers the inputs to ints
    int minBound = atoi(argv[1]);
    int maxBound = atoi(argv[2]);

    //
    int flag = 0;   // checks if value input is a prime
    int x = minBound ; // checks if value input is not a prime

    printf("\n");
    printf(" Prime values in the range of %d and %d are : ",minBound,maxBound);

    // while loop runs & returns prime 
    while (x < maxBound)
    {
        flag = 0;
        for (int i = 2; i <= x / 2; ++i){
            if (x % i == 0){
               flag = 1;  // if the modulo of a returns 1 then a is not a prime 
                break;
            }
        }
        if (flag == 0) // then a is prime thus we print it 
            printf( " %d  ", x);
            ++x;
    }    
    return 0 ;
}