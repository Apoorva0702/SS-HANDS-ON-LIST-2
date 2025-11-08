/*
======================================================================================================================================================================================
name : 8b.c
author : Apoorva Kharya 
description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
date: 20 sept 2025
======================================================================================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void seginthandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    signal(SIGINT, seginthandle);
    while (1) {
        printf("press Ctrl+C to stop\n");
        sleep(1);
    }
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8b.c -o 8b
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8b
press Ctrl+C to stop
press Ctrl+C to stop
press Ctrl+C to stop
press Ctrl+C to stop
^Csignal caught 2
exiting safely.
======================================================================================================================================================================================
*/
