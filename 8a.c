/*
======================================================================================================================================================================================
name : 8a.c
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
void segvhandle(int sig) 
{
    printf("signal caught %d\n", sig);
    printf("seg_v action exit safely.\n");
    _exit(1); 
}
int main()
{
    signal(SIGSEGV, segvhandle);
    printf("triggering SIGSEGV by dereferencing NULL...\n");
    int *p = NULL;
    *p = 22;
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8a.c -o 8a
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8a
triggering SIGSEGV by dereferencing NULL...
signal caught 11
seg_v action exit safely.
======================================================================================================================================================================================
*/
