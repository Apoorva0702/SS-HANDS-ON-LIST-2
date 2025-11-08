/*
======================================================================================================================================================================================
name : 1.c
author : Apoorva Kharya 
description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>
void timer_handler(int signo)
{
    printf("timer has expired, the signal number is %d\n",signo);
}
int main()
{
    struct itimerval timer;
    signal(SIGALRM, timer_handler);
    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=10;
    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=10;
    setitimer(ITIMER_REAL,&timer,NULL);
    printf("timer alarm started waiting for sigalarm\n");
    while(1)pause();
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 1.c -o 1
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./1
timer alarm started waiting for sigalarm
timer has expired, the signal number is 14
timer has expired, the signal number is 14
timer has expired, the signal number is 14

======================================================================================================================================================================================
*/
