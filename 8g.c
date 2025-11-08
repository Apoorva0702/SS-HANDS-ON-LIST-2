/*
======================================================================================================================================================================================
name : 8g.c
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
void sigprofhandle(int signal_1) 
{
    printf("signal caught %d\n", signal_1);
    printf("exiting safely.\n");
    _exit(1); 
}
int main()
{
    struct itimerval timer;
    signal(SIGPROF, sigprofhandle);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 500000;
    setitimer(ITIMER_PROF, &timer, NULL);
    printf("timer started\n");
    while(1) 
    {
        for(long i = 0; i < 1000000; i++); 
    }
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 8g.c -o 8g
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./8g
timer started
signal caught 27
exiting safely.
======================================================================================================================================================================================
*/
