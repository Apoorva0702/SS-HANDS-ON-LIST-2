*
======================================================================================================================================================================================
name : 10.c
author : Apoorva Kharya 
description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
date: 20 sept 2025
======================================================================================================================================================================================
*/


#include <stdio.h>
#include <signal.h>
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
    int a = 5;
    int b = 0;
    int result = a / b;
    return 0;
}

/*
======================================================================================================================================================================================
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ gcc 10.c -o 10
apoorva-kharya@apoorva-kharya-OMEN-Laptop-15-ek0xxx:~$ ./10
signal caught 8
exiting safely.
======================================================================================================================================================================================
*/
