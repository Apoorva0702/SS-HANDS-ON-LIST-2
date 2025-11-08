/*
======================================================================================================================================================================================
name : 8f.c
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
void sigvtalrmhandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    struct itimerval timer;
    signal(SIGVTALRM, sigvtalrmhandle);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 500000;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    printf("timer started\n");
    while(1) 
    {
        for(long i = 0; i < 1000000; i++); 
    }
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8f.c -o 8f
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8f
timer started
signal caught 26
exiting safely.
======================================================================================================================================================================================
*/
