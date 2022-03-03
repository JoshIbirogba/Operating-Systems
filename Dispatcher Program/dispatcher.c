#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


//typedef defined to turn on or off the parent and child process
enum status { on, off};
typedef enum status status;

//global variables
int pid;
status flag = on;
struct sigaction newhandler, oldhandler;
sigset_t sig;
 

 //method to control parent and child process
void next(int i)
{
   if (flag == on) {
         kill(pid,SIGSTOP);
        flag = off;
   } else {
         kill(pid,SIGCONT);
         flag = on;
       }
 }

//scheduler method to create jobs
void scheduler(int n ){
   for(int x = 0 ; x < n; x++){   // for loop to maintain array of pids/jobs
        pid[x]= fork(); 
        if(pid[x]>-1){
            char job = (char)( x + 10) ;
            current = x ; 
            execl("./period","./period",(char)(x),(char*)NULL);
        }
    }
}  
      
    void main(int argc, char **argv)
{
     for(int y = 0 ; y < atoi(argv[1]); y++){
        pid[y]= fork();

        if(pid[y]>-1){
            char job = (char)(y) ;
            current = y; 
            execl("./period","./period",job,(char*)NULL);
        }    
     }
        while (1) {
          alarm(3);
          pause();
        }
}
   