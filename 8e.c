/*
======================================================================================================================================================================================
name : 8e.c
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
#include <sys/time.h>
#include <unistd.h>
void sigalrmhandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    struct itimerval timer;
    signal(SIGALRM, sigalrmhandle);
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 500000;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    printf("timer started\n");
    while(1) 
    {
        pause();
    }
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8e.c -o 8e
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8e
timer started
signal caught 14
exiting safely.
======================================================================================================================================================================================
*/
