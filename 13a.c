/*
======================================================================================================================================================================================
name : 13.c
author : Apoorva Kharya 
description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void stopprog(int signal_id){
    printf("\nSignal Sent.");
    printf("Reciever Pid %d: Signal %d not caught.\n", getpid(), signal_id);   
}
int main(){
   printf("Receiver program started.\nPID of the process- %d\n", getpid());
   signal(SIGSTOP, stopprog);
   while(1){
       usleep(500000);
       fflush(stdout);
   }
   return 0;
   
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 13a.c -o 13a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./13a
Receiver program started.
PID of the process- 8443

[1]+  Stopped                 ./13a



apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./13b 8443
Sender Program has started.
Attempting to stop 19 to process with PID: 8443
Sent stop signal to PID 8443. The process should now be suspended.
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ 

======================================================================================================================================================================================
*/

