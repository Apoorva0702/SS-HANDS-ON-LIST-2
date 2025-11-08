/*
======================================================================================================================================================================================
name : 8d.c
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
void sigalrmhandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
   signal(SIGALRM, sigalrmhandle);
    printf("Setting alarm for 5 seconds...\n");
    alarm(4);
    while (1) {
        pause();
    return 0;
    }
}

/*
======================================================================================================================================================================================
poorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8d.c -o 8d
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8d
Setting alarm for 5 seconds...
signal caught 14
exiting safely.
======================================================================================================================================================================================
*/
