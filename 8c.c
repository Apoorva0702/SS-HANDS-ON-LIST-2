/*
======================================================================================================================================================================================
name : 8c.c
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
void sigfpehandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    signal(SIGFPE, sigfpehandle);
    int a = 7;
    int b = 0;
    int result = a / b;
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8c.c -o 8c
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8c
signal caught 8
exiting safely.
======================================================================================================================================================================================
*/
