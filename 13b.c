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
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,  char *argv[]){
   pid_t id = (pid_t) atoi(argv[1]);
   printf("Sender Program has started.\n");
   printf("Attempting to stop %d to process with PID: %d\n", SIGSTOP, id);
    int rid = kill(id, SIGSTOP);

    if (rid == 0) {
        printf("Sent stop signal to PID %d. The process should now be suspended.\n", id);
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


