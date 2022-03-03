/*
Name: Joshua Ibirogba
Student ID: 5073203
Course code: CS 3790
What does this program do: This program finds the prime numbers from the number of range provided using java threads.
*/
package javathread;

import java.util.Scanner;


public class JavaThread extends Thread implements Runnable
{

    public static void main(String args[]) 
    {
        Scanner input = new Scanner(System.in);
        
        int x = Integer.parseInt(args[0]); //get and convert number
        int y = Integer.parseInt(args[1]);
		int i = x;
		int low = 1;    
		int step = (y / x);      
		int count = 0;
                
		while(count < i)
                {
    		JavaThread threadOne = new JavaThread(x, step * low); // create threadOne from the javaThread class.
			count++;
			threadOne.start(); 				      // run the object as a thread.
			x = x + step - 1;
			low++;
		}
    }

    JavaThread(int a, int b)
    {
	    int counter = 0; //count keeps track of numbers that can evenly divide i.
	    System.out.println();
	    System.out.print("Primes found : ");
	    for (int i = a; i <= b; i++) {
		    for (int j = 1; j <= i; j++) {
			    if (i % j == 0) { // calculates if the number is divisible by j
                                counter++;
			    }
		    }
		    if (counter == 2){ // if the number is prime , print it.
			    System.out.print(" " + i);
		    }
		    counter = 0;
	    }
	    System.out.println();		
    }
}    

